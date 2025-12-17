#include <iostream>
#include <string>
#include <cstring>

// Forward declare problem functions
int problem_001(int limit);

void run_problem(int prob_num) {
    std::cout << "=== Problem " << prob_num << " ===" << std::endl;

    switch (prob_num) {
        case 1: {
            int limit = 1000;
            int result = problem_001(limit);
            std::cout << "Result: " << result << std::endl;
            break;
        }
        default:
            std::cerr << "Problem " << prob_num << " not implemented" << std::endl;
            break;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <problem_number|all>" << std::endl;
        return 1;
    }

    std::string arg = argv[1];

    if (arg == "all") {
        // Run all implemented problems
        for (int i = 1; i <= 1; ++i) {  // Update upper bound as more problems are added
            run_problem(i);
            std::cout << std::endl;
        }
    } else {
        int prob_num = std::atoi(argv[1]);
        run_problem(prob_num);
    }

    return 0;
}
