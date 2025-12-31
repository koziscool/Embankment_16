#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <iomanip>

#include "../problems/problems.h"
#include "utils/utils.h"

void run_problem(int prob_num) {
    std::cout << "=== Problem " << prob_num << " ===" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    switch (prob_num) {
        case 1: {
            int limit = 1000;
            int result = problem_001(limit);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }
        case 2: {
            int limit = 4000000;
            int result = problem_002(limit);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }
        case 3: {
            long long n = 600851475143LL;
            long long result = problem_003(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }
        case 4: {
            int digits = 3;
            int result = problem_004(digits);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }
        case 5: {
            int n = 20;
            long long result = problem_005(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }
        case 6: {
            int n = 100;
            long long result = problem_006(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }
        case 7: {
            int n = 10'001;
            long long result = problem_007(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }
        case 10: {
            int n = 2'000'000;
            long long result = problem_010(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }
        case 14: {
            int n = 1'000'000;
            long long result = problem_014(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }
        case 15: {
            int n = 20;
            long long result = problem_015(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }
        case 16: {
            int n = 1'000;
            long long result = problem_016(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }
        case 20: {
            int n = 100;
            long long result = problem_020(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }    
        case 25: {
            int n = 1000;
            long long result = problem_025(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }  
        case 29: {
            int n = 100;
            long long result = problem_029(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }              
        case 40: {
            long long result = problem_040();
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }   
        case 43: {
            long long result = problem_043();
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        } 
        case 46: {
            long long result = problem_046();
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }           
        case 53: {
            int n = 100;
            long long result = problem_053(n);
            std::cout << "Result: " << std::setw(21) << std::left << result;
            break;
        }           
        default:
            std::cerr << "Problem " << prob_num << " not implemented" << std::endl;
            return;
    }

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

        // Run all problems (skip unimplemented ones)
        for (int i = 1; i <= LAST_PROBLEM; ++i) {  // Update upper bound as more problems are added
            if (IMPLEMENTED.count(i) == 0) {
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
