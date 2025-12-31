#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <iomanip>

#include "../problems/problems.h"
#include "utils/utils.h"

void run_problem(int prob_num) {
    std::cout << "=== Problem " << prob_num << " ===" << std::endl;

    if (PROBLEM_MAP.count(prob_num) == 0) {
        std::cerr << "Problem " << prob_num << " not implemented" << std::endl;
        return;
    }

    auto start = std::chrono::high_resolution_clock::now();

    long long result = PROBLEM_MAP.at(prob_num)();  // Call function via map
    std::cout << "Result: " << std::setw(21) << std::left << result;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << " Elapsed: " << std::fixed << std::setprecision(3)
              << duration.count() / 1000.0 << " ms" << std::endl;
}

int main(int argc, char* argv[]) {
    std::cout << std::endl;

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <problem_number|all>" << std::endl;
        return 1;
    }

    std::string arg = argv[1];

    if (arg == "all") {
        auto total_start = std::chrono::high_resolution_clock::now();

        // Get last problem number from map (map is sorted, so rbegin gives largest key)
        int last_problem = PROBLEM_MAP.empty() ? 0 : PROBLEM_MAP.rbegin()->first;

        // Run all problems from 1 to last_problem (skip unimplemented ones)
        for (int i = 1; i <= last_problem; ++i) {
            if (PROBLEM_MAP.count(i) == 0) {
                std::cout << "=== Problem " << i << " ===" << std::endl;
                std::cout << "Not implemented" << std::endl;
                std::cout << std::endl;
                continue;
            }
            run_problem(i);
            std::cout << std::endl;
        }

        auto total_end = std::chrono::high_resolution_clock::now();
        auto total_duration = std::chrono::duration_cast<std::chrono::microseconds>(total_end - total_start);
        std::cout << "====================" << std::endl;
        std::cout << "Total time: " << std::fixed << std::setprecision(3)
                  << total_duration.count() / 1000.0 << " ms" << std::endl;
    } else {
        int prob_num = std::atoi(argv[1]);
        run_problem(prob_num);
    }

    std::cout << std::endl;
    return 0;
}
