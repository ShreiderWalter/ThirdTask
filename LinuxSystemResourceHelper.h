#ifndef LINUXSYSTEMRESOURCEHELPER_H
#define LINUXSYSTEMRESOURCEHELPER_H
#include "SystemResourceHelper.h"

class LinuxSystemResourceHelper : public SystemResourceHelper
{
private:
    LinuxSystemResourceHelper(const LinuxSystemResourceHelper & other) = delete;
    LinuxSystemResourceHelper(LinuxSystemResourceHelper && other) = delete;

public:
    LinuxSystemResourceHelper();
    int getCPUUsage() const;
    std::list<std::string> getDisks() const;
    int getDiskUsage(const std::string &name) const;
    int getMemoryUsage() const;
};

#endif // LINUXSYSTEMRESOURCEHELPER_H
