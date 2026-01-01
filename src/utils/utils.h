#pragma once

#include <vector>
#include <map>

// Returns a list of primes < n (computed fresh each time)
std::vector<long long> makePrimes(long long n);

// Returns all cached primes (computes up to limit on first call, default 10^8)
// If you need primes > current limit, pass a larger limit to recompute
const std::vector<long long>& getPrimes(long long limit = 100'000'000);

std::map<long long int, int> primeFactors(long long int n);
long long int numFactors( long long int n );

long long int factorial(int n);
long long int combinations(int n, int r);

bool isPalindrome( long long int n );

long long int gcd( long long int a, long long int b );
