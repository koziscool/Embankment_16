
#include "../src/utils/bigint.h"

long long int problem_016( int limit ){
    BigInt base(2);
    return base.pow(limit).digit_sum();
}
