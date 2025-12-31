#include "utils.h"

#include <cmath>
#include <iostream>
#include <string>

std::vector<long long> makePrimes(long long n) {
    if (n <= 2) return {};

    std::vector<bool> sieve(n, true);
    sieve[0] = sieve[1] = false;

    long long sqrt_n = static_cast<long long>(std::sqrt(n));

    for (long long i = 3; i <= sqrt_n; i += 2) {
        if (sieve[i]) {
            for (long long j = i * i; j < n; j += 2 * i) {
                sieve[j] = false;
            }
        }
    }

    std::vector<long long> primes;
    primes.push_back(2);
    for (long long i = 3; i < n; i += 2) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

// Global cache - one vector of all primes up to currentLimit
static std::vector<long long> allPrimes;
static long long currentLimit = 0;

const std::vector<long long>& getPrimes(long long limit) {
    // If we need more primes than currently cached, recompute
    if (limit > currentLimit) {
        // std::cout << "[Computing primes up to " << limit << "...]" << std::endl;
        allPrimes = makePrimes(limit);
        currentLimit = limit;
        // std::cout << "[Cached " << allPrimes.size() << " primes]" << std::endl;
    }

    // Return full cache (caller can filter if needed)
    return allPrimes;
}

std::map<long long int, int> primeFactors(long long int n){

    long long remainder = n;
    const std::vector<long long int>& primes = getPrimes( n );
    std::map<long long int, int> factorsMap;

    for(auto p: primes){

        if( remainder == 1 || p * p > remainder)
            break;
        while( remainder % p == 0 ){
            remainder /= p;
            factorsMap[p] += 1;
        }
    }

    if( remainder > 1 )
        factorsMap[remainder] = 1;    

    return factorsMap;
}

long long int numFactors( long long int n ){
    // std::vector<long long int> primes = getPrimes( n );
    std::map<long long int, int> d = primeFactors(n);
    long int retVal = 1;
    for (auto i = d.begin(); i != d.end(); i++) 
        retVal *= (i->second + 1);
    return retVal;
}

long long int factorial(int n){
    if( n == 0 ) return 1;

    long long int retProd = 1;
    for( int i = 1; i <= n; i++ ){
        retProd *= i;
    }
    return retProd;
}

long long int combinations(int n, int r){
    return factorial(n) / factorial(r) / factorial(n-r);
}

bool isPalindrome(long long n) {
    std::string s = std::to_string(n);
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
