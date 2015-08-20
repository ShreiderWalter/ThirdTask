#ifndef WINDOWS_SYSTEM_RESOURCE_HELPER_H
#define WINDOWS_SYSTEM_RESOURCE_HELPER_H

#include "SystemResourceHelper.h"
#include <Windows.h>
#include "TCHAR.h"
#include "pdh.h"

class WindowsSystemResourceHelper : public SystemResourceHelper<WindowsSystemResourceHelper>
{
public:
	int getCPUUsage() const;
	std::list<std::string> getDisks() const;
	int getDiskUsage(const std::string & name) const;
	int getMemoryUsage() const;
};

#endif //WINDOWS_SYSTEM_RESOURCE_HELPER_H