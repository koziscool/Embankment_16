#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <iomanip>

// Forward declare problem functions
int problem_001(int limit);
int problem_002(int limit);

void run_problem(int prob_num) {
    std::cout << "=== Problem " << prob_num << " ===" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    switch (prob_num) {
        case 1: {
            int limit = 1000;
            int result = problem_001(limit);
            std::cout << "Result: " << result;
            break;
        }
        case 2: {
            int limit = 4000000;
            int result = problem_002(limit);
            std::cout << "Result: " << result;
            break;
        }
        default:
            std::cerr << "Problem " << prob_num << " not implemented" << std::endl;
            return;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\t\tElapsed: " << std::fixed << std::setprecision(3)
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

        // Run all implemented problems
        for (int i = 1; i <= 2; ++i) {  // Update upper bound as more problems are added
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
