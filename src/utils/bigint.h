#pragma once

#include <vector>
#include <string>
#include <iostream>

class BigInt {
private:
    std::vector<int> digits;  // Stored in reverse (least significant first)

public:
    // Constructors
    BigInt();
    BigInt(long long n);
    BigInt(const std::string& s);
    BigInt(const BigInt& other);  // Copy constructor

    // Assignment
    BigInt& operator=(const BigInt& other);  // Copy assignment

    // Comparison
    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;

    // Basic operations
    BigInt operator+(const BigInt& other) const;
    BigInt operator*(int n) const;
    BigInt operator*(const BigInt& other) const;
    BigInt pow(int exp) const;

    // Utility functions
    int digit_sum() const;
    std::string to_string() const;

    friend std::ostream& operator<<(std::ostream& os, const BigInt& b);
};
