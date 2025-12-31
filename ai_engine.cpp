#include "../include/ai_engine.h"

std::vector<Diagnosis> run_ai_engine(const SystemMetrics& m) {
    std::vector<Diagnosis> results;

    // Rule 1: CPU Overheating
    if (m.cpu_temp > 85.0) {
        results.push_back({
            "CPU Overheating",
            "CPU temperature exceeds safe threshold",
            "Clean fan, replace thermal paste, improve airflow"
        });
    }

    // Rule 2: High CPU usage
    if (m.cpu_usage > 80.0 && m.cpu_temp < 85.0) {
        results.push_back({
            "High CPU Usage",
            "CPU-bound background process",
            "Use top/htop and stop unnecessary processes"
        });
    }

    // Rule 3: High RAM usage
    if (m.ram_usage > 85.0) {
        results.push_back({
            "High Memory Usage",
            "Applications consuming excessive RAM",
            "Restart heavy apps or check for memory leaks"
        });
    }

    // Rule 4: Healthy system
    if (results.empty()) {
        results.push_back({
            "System Healthy",
            "All metrics within safe ranges",
            "No action required"
        });
    }

    return results;
}

