#ifndef LINUXSYSTEMRESOURCEHELPER_H
#define LINUXSYSTEMRESOURCEHELPER_H
#include "SystemResourceHelper.h"

class LinuxSystemResourceHelper : public SystemResourceHelper<LinuxSystemResourceHelper>
{

public:
    int getCPUUsage() const;

    std::list<std::string> getDisks() const;
    int getDiskUsage(const std::string &name) const;
    int getMemoryUsage() const;
};

#endif // LINUXSYSTEMRESOURCEHELPER_H
