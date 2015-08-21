#ifndef SYSTEMRESOURCEHELPER_H
#define SYSTEMRESOURCEHELPER_H

#include <memory>
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class SystemResourceHelper
{

protected:
    SystemResourceHelper(){}
    static SystemResourceHelper * m_instance;

public:
    SystemResourceHelper(const SystemResourceHelper & other) = delete;
    SystemResourceHelper(SystemResourceHelper && other) = delete;
    virtual int getCPUUsage() const = 0;
    virtual std::list<std::string> getDisks() const = 0;
    virtual int getDiskUsage(const std::string & name) const = 0;
    virtual int getMemoryUsage() const = 0;

    static SystemResourceHelper * getInstance();

};

#endif // SYSTEMRESOURCEHELPER_H
