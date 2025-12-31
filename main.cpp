#include <iostream>
#include "../include/system_metrics.h"
#include "../include/ai_engine.h"

int main() {
    std::cout << "🧠 AI System Doctor (Rule-Based)\n";
    std::cout << "===============================\n";

    SystemMetrics metrics = collect_metrics();

    std::cout << "\n📊 System Metrics\n";
    std::cout << "CPU Usage : " << metrics.cpu_usage << "%\n";
    std::cout << "RAM Usage : " << metrics.ram_usage << "%\n";
    std::cout << "CPU Temp  : " << metrics.cpu_temp << " °C\n";

    auto diagnoses = run_ai_engine(metrics);

    std::cout << "\n🛠 Diagnosis & Solutions\n";
    for (const auto& d : diagnoses) {
        std::cout << "\n❗ Problem : " << d.problem << "\n";
        std::cout << "🔍 Cause   : " << d.cause << "\n";
        std::cout << "✅ Fix     : " << d.solution << "\n";
    }

    return 0;
}

