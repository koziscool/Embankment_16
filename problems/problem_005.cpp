#include "../src/utils/utils.h"

// Problem 5: Smallest multiple
// What is the smallest positive number that is evenly divisible by all numbers from 1 to 20?

long long problem_005(int limit) {
    // TODO: implement

    std::vector<long long int> littlePrimes = makePrimes(limit);

    long int retVal = 1;
    for(auto p: littlePrimes){
        long int prime_power = p;
        while( prime_power * p < limit ){
            prime_power *= p;
        }
        retVal *= prime_power;
    }
    return retVal;
}
