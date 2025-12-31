
#include "../src/utils/utils.h"
#include <iostream>

long long int problem_012( int limit ){

    auto triangle = [](long long n){
        return n * (n+1) / 2;
    };

    // Optimization: triangle(n) = n*(n+1)/2
    // Since gcd(n, n+1) = 1, we can factor them separately
    // If n is even: triangle(n) = (n/2) * (n+1)
    //   numDivisors = numFactors(n/2) * numFactors(n+1)
    // If n is odd: triangle(n) = n * ((n+1)/2)
    //   numDivisors = numFactors(n) * numFactors((n+1)/2)

    long long i = 1;
    long long divisors;

    while( true ){
        if( i % 2 == 0 ){
            divisors = numFactors(i/2) * numFactors(i+1);
        } else {
            divisors = numFactors(i) * numFactors((i+1)/2);
        }

        if( divisors > limit ){
            break;
        }
        i += 1;
    }

    return triangle(i);
}