#include "../src/utils/bigint.h"

int problem_020( int limit ){
    // BigInt n = factorial(limit);
    return BigInt::factorial(limit).digit_sum();
}
