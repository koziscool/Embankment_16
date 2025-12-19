#include "../src/utils/bigint.h"

#include <tuple>

int problem_025( int limit ){
    BigInt first, second;
    std::tie(first, second) = std::make_tuple( BigInt(1),BigInt(1) );
    int index = 2;

    while( second.num_digits() < limit ){
        std::tie(first, second) = std::make_tuple(second, first + second);
        index += 1;
    }

    return index;
}