#ifndef SYSTEM_METRICS_H
#define SYSTEM_METRICS_H

struct SystemMetrics {
    double cpu_usage;
    double ram_usage;
    double cpu_temp;
};

SystemMetrics collect_metrics();

#endif

