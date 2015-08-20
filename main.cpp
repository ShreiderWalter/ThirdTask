#ifdef __linux__
#include "LinuxSystemResourceHelper.h"
#define PLATFORM LinuxSystemResourceHelper
#elif defined _WIN32 || defined _WIN64
#include "WindowsSystemResourceHelper.h"
#define PLATFORM WindowsSystemResourceHelper
#endif

#include "SystemResourceHelper.h"

int main()
{
	SystemResourceHelper<PLATFORM> * helper = SystemResourceHelper<PLATFORM>::getInstance();
	std::cout << helper->getCPUUsage() << "%\n";
	//std::cout << helper->getMemoryUsage() << "%\n";
	/*std::list<std::string> disks = helper->getDisks();
	for(auto i : disks)
	{
		std::cout << i << "\n";
	}*/

	//std::cout << helper->getDiskUsage("c:") << "%\n";

    delete helper;
    helper = nullptr;

	return 0;
}
