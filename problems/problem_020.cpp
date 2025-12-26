#include "../src/utils/bigint.h"

int problem_020( int limit ){
    return BigInt::factorial(limit).digit_sum();
}
