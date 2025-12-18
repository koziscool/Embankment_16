#include <iostream>
#include <vector>

#include "../src/utils/utils.h"

// Problem 3: Largest prime factor
// What is the largest prime factor of the number 600851475143?

long long problem_003(long long n) {
    // TODO: implement

    std::vector<long long int> primes = getPrimes( 10'000'000 );
    
    long int max_prime = 0;
    long int remainder = n;

    for(const auto& p: primes){
        if( remainder == 1 || p*p > remainder )
            break;
        if( remainder % p == 0 )
            max_prime = p;
        while( remainder % p == 0 )
            remainder /= p;
    }
    if (remainder == 1)
        return max_prime;
    else
        return remainder;    
    
}
