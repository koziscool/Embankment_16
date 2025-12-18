#include <tuple>

// Problem 2: Even Fibonacci numbers
// Find the sum of the even-valued terms in the Fibonacci sequence whose values do not exceed four million

int problem_002(int limit) {
    long long int total = 0, first, second;
    std::tie(first, second) = std::make_tuple(1,2);

    while (second <= limit){
        if(second % 2 == 0)
            total += second;
        std::tie(first, second) = std::make_tuple(second, first + second);
    }
    
    return total;
}
