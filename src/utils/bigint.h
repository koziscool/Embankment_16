#pragma once

#include <vector>
#include <string>
#include <iostream>

class BigInt {
private:
    // CLASS INVARIANT: digits vector must never have trailing zeros (except for zero itself: [0])
    // - This ensures unique representation of each number
    // - Makes operator==, operator<, and isPalindrome work correctly
    // - Maintained by: vector constructor, multiply operations
    // - Addition cannot create trailing zeros due to carry logic

    std::vector<int> digits;  // Stored in reverse (least significant first)

public:
    // Constructors
    BigInt();
    BigInt(std::vector<int> d);
    BigInt(long long n);
    BigInt(const std::string& s);
    BigInt(const BigInt& other);  // Copy constructor

    // Assignment
    BigInt& operator=(const BigInt& other);  // Copy assignment

    // Comparison
    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;

    // Basic operations
    BigInt operator+(const BigInt& other) const;
    BigInt operator*(int n) const;
    BigInt operator*(const BigInt& other) const;
    BigInt pow(int exp) const;
    BigInt reverseAndAdd() const;

    // Utility functions
    int digit_sum() const;
    int num_digits() const;
    bool isPalindrome() const;

    std::string to_string() const;

    // Static methods
    static BigInt factorial(int n);

    friend std::ostream& operator<<(std::ostream& os, const BigInt& b);
};
