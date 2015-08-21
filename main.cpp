#ifdef __linux__
#include "LinuxSystemResourceHelper.h"
#elif defined _WIN32 || defined _WIN64
#include "WindowsSystemResourceHelper.h"
#endif

#include "SystemResourceHelper.h"

int main()
{
    SystemResourceHelper * helper = SystemResourceHelper::getInstance();
    std::cout << helper->getCPUUsage() << "%\n";
	//std::cout << helper->getMemoryUsage() << "%\n";
	/*std::list<std::string> disks = helper->getDisks();
	for(auto i : disks)
	{
		std::cout << i << "\n";
	}*/

	//std::cout << helper->getDiskUsage("c:") << "%\n";

	return 0;
}
