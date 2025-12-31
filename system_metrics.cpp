#include "../include/system_metrics.h"
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

static double get_cpu_usage() {
    long long user, nice, system, idle;
    std::ifstream file("/proc/stat");
    std::string cpu;

    file >> cpu >> user >> nice >> system >> idle;
    long long idle1 = idle;
    long long total1 = user + nice + system + idle;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    file.clear();
    file.seekg(0);
    file >> cpu >> user >> nice >> system >> idle;
    long long idle2 = idle;
    long long total2 = user + nice + system + idle;

    return 100.0 * (1.0 - (double)(idle2 - idle1) / (double)(total2 - total1));
}

static double get_ram_usage() {
    std::ifstream file("/proc/meminfo");
    std::string key;
    long long total = 0, available = 0;

    while (file >> key) {
        if (key == "MemTotal:") file >> total;
        else if (key == "MemAvailable:") {
            file >> available;
            break;
        }
    }
    return 100.0 * (1.0 - (double)available / (double)total);
}

static double get_cpu_temp() {
    std::ifstream file("/sys/class/thermal/thermal_zone0/temp");
    double temp = 0;
    file >> temp;
    return temp / 1000.0;
}

SystemMetrics collect_metrics() {
    return {
        get_cpu_usage(),
        get_ram_usage(),
        get_cpu_temp()
    };
}

