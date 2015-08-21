#include "LinuxSystemResourceHelper.h"
#include <thread>
#include <sys/statvfs.h>

LinuxSystemResourceHelper::LinuxSystemResourceHelper()
{
}

int LinuxSystemResourceHelper::getCPUUsage() const
{

    std::ifstream infile("/proc/stat");
    std::string line;
    std::getline(infile, line);
    infile.close();
    std::istringstream iss(line);
    int tmp, i = 0;
    double before_total = 0, before_work = 0;
    std::string str;
    iss >> str;
    while(iss >> tmp)
    {
        before_total += tmp;
        if(i < 3)
        {
            before_work += tmp;
        }
        ++i;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    infile.open("/proc/stat");
    std::getline(infile, line);
    infile.close();
    iss.clear();
    iss.str(line);
    iss >> str;
    i = 0, tmp = 0;
    double after_total = 0, after_work = 0;
    while(iss >> tmp)
    {
        after_total += tmp;
        if(i < 3)
        {
            after_work += tmp;
        }
        ++i;
    }

    double res = (after_work - before_work)
            / (after_total - before_total) * 100;
    return res;
}


namespace walter
{
    struct MountedPoint
    {
        std::string device;
        std::string fstype;
        std::string options;
    };

    std::ostream & operator << (std::ostream & out,
                                const MountedPoint & other)
    {
        return out << other.fstype << " device \"" << other.device
                  << "\". Options : " << other.options;
    }
}

std::list<std::string> LinuxSystemResourceHelper::getDisks() const
{
    std::list<std::string> result;

    std::ifstream infile("/proc/mounts");
    walter::MountedPoint point;
    while(!infile.eof())
    {
        infile >> point.device >> point.fstype >>
                point.options;
        std::stringstream buffer;
        buffer << point;
        result.push_back(buffer.str());
    }

    return result;
}

int LinuxSystemResourceHelper::getDiskUsage(const std::string &name) const
{
    struct statvfs Data;

    statvfs(name.c_str(), &Data);
    long double free = Data.f_frsize * Data.f_bfree;
    long double total = Data.f_frsize * Data.f_blocks;

    long double res = free / total * 100;
    return 100 - res;
}

int LinuxSystemResourceHelper::getMemoryUsage() const
{
    std::ifstream infile("/proc/meminfo");
    std::string line;
    std::getline(infile, line);
    infile.close();
    std::istringstream iss(line);
    std::string tmp;
    iss >> tmp;
    double totalMemory  = 0.0;
    iss >> totalMemory;

    infile.open("/proc/meminfo");
    std::getline(infile, line);
    std::getline(infile, line);

    infile.close();
    iss.clear();
    iss.str(line);
    iss >> tmp;
    double freeMemory = 0.0;
    iss >> freeMemory;

    double res = freeMemory / totalMemory * 100;
    res = 100 - res;

    return res;
}
