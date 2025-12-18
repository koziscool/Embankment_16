#include "../src/utils/utils.h"

long long int problem_010( int limit ){
    std::vector<long long int> primes = getPrimes( limit );
    long long int retSum = 0;
    for ( auto p: primes ){
        if( p < 2'000'000 )
            retSum += p;
    }
    return retSum;
}
