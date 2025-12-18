
#include "../src/utils/utils.h"

long long int problem_007( int limit ){
    std::vector<long long int> primes = getPrimes( 10'000'000 );
    return primes.at( limit - 1 );
}
