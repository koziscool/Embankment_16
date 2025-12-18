#include "utils.h"
#include <cmath>
#include <iostream>

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