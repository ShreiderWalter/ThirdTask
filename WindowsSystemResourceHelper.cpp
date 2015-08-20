#include "WindowsSystemResourceHelper.h"

int WindowsSystemResourceHelper::getCPUUsage() const
{
	FILETIME last_idleTime;
	FILETIME last_kernelTime;
	FILETIME last_userTime;

	GetSystemTimes(&last_idleTime, &last_kernelTime, &last_userTime);

	Sleep(3000);

	FILETIME idleTime;
	FILETIME kernelTime;
	FILETIME userTime;

	GetSystemTimes(&idleTime, &kernelTime, &userTime);
	
	long usr = userTime.dwLowDateTime - last_userTime.dwLowDateTime;
	long ker = kernelTime.dwLowDateTime - last_kernelTime.dwLowDateTime;
	long idl = idleTime.dwLowDateTime - last_idleTime.dwLowDateTime;

	return int((ker + usr - idl) * 100 / (ker + usr));
}

int WindowsSystemResourceHelper::getMemoryUsage() const
{
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);

	GlobalMemoryStatusEx(&statex);

	return statex.dwMemoryLoad;
}

std::list<std::string> WindowsSystemResourceHelper::getDisks() const
{
	std::list<std::string> result;

	char szDrive[ ] = " A:";
	DWORD uDriveMask = GetLogicalDrives();
	if(uDriveMask == 0)
	{
		printf("\nGetLogicalDrives() failed with failure code: %d\n", GetLastError());
	}
	else
	{
		while(uDriveMask)
		{
			if(uDriveMask & 1)
			{
				result.push_back(std::string(szDrive));
			}
			++szDrive[1];
			uDriveMask >>= 1;
		}
	}

	return result;
}

int WindowsSystemResourceHelper::getDiskUsage(const std::string & name) const
{
	ULARGE_INTEGER m_uliFreeBytesAvailable;
	ULARGE_INTEGER m_uliTotalNumberOfBytes;
	ULARGE_INTEGER m_uliTotalNumberOfFreeBytes;
	m_uliFreeBytesAvailable.QuadPart = 0L;
	m_uliTotalNumberOfBytes.QuadPart = 0L;
	m_uliTotalNumberOfFreeBytes.QuadPart = 0L;
	GetDiskFreeSpaceEx(name.c_str(),
		&m_uliFreeBytesAvailable,
		&m_uliTotalNumberOfBytes,
		&m_uliTotalNumberOfFreeBytes);

	long double total = m_uliTotalNumberOfBytes.QuadPart / 100;
	long double free =  m_uliTotalNumberOfFreeBytes.QuadPart / 100;

	double res = (free / total * 100);
	return 100 - res;
}
