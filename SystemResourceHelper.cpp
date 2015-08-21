#include "SystemResourceHelper.h"
#include "LinuxSystemResourceHelper.h"

SystemResourceHelper * SystemResourceHelper::m_instance;

SystemResourceHelper * SystemResourceHelper::getInstance()
{

#ifdef __linux__
    m_instance = new LinuxSystemResourceHelper;
#elif defined _WIN32 || defined _WIN64
    m_instance = new WindowsSystemResourceHelper;
#endif
    return m_instance;
}
