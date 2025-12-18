#pragma once

#include <vector>

// Returns a list of primes < n (computed fresh each time)
std::vector<long long> makePrimes(long long n);

// Returns all cached primes (computes up to limit on first call, default 10^8)
// If you need primes > current limit, pass a larger limit to recompute
const std::vector<long long>& getPrimes(long long limit = 100000000);

long long int factorial(int n);
long long int combinations(int n, int r);

bool isPalindrome( long long int n );
