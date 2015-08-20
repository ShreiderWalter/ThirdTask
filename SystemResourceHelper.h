#ifndef SYSTEMRESOURCEHELPER_H
#define SYSTEMRESOURCEHELPER_H

#include <memory>
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

template<typename T>
class SystemResourceHelper
{

private:
    static T * m_instance;

public:

    virtual int getCPUUsage() const = 0;
    virtual std::list<std::string> getDisks() const = 0;
    virtual int getDiskUsage(const std::string & name) const = 0;
    virtual int getMemoryUsage() const = 0;

    static T * getInstance();

};

template<typename T>
T * SystemResourceHelper<T>::m_instance;

template<typename T>
T * SystemResourceHelper<T>::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new T;
    }
    return m_instance;
}


#endif // SYSTEMRESOURCEHELPER_H
