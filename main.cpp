#include "LinuxSystemResourceHelper.h"

int main()
{
    LinuxSystemResourceHelper * helper = LinuxSystemResourceHelper::getInstance();
    //std::cout << helper->getCPUUsage() << "%\n";
    //std::cout << helper->getMemoryUsage() << "%\n";

    /*std::list<std::string> disks = helper->getDisks();

    for(auto i : disks)
    {
        std::cout << i << "\n";
    }*/

    //std::cout << helper->getDiskUsage("/var");
    return 0;
}

