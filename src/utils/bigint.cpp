#include "bigint.h"
#include <algorithm>

// Default constructor
BigInt::BigInt() : digits({0}) {}

// Constructor from long long
BigInt::BigInt(long long n) {
    if (n == 0) {
        digits = {0};
        return;
    }

    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
}

// Constructor from string
BigInt::BigInt(const std::string& s) {
    // Store in reverse order
    for (int i = s.length() - 1; i >= 0; --i) {
        digits.push_back(s[i] - '0');
    }
}

// Copy constructor
BigInt::BigInt(const BigInt& other) : digits(other.digits) {}

// Copy assignment operator
BigInt& BigInt::operator=(const BigInt& other) {
    if (this != &other) {  // Check for self-assignment
        digits = other.digits;
    }
    return *this;
}

// Equality operator
bool BigInt::operator==(const BigInt& other) const {
    return digits == other.digits;
}

// Inequality operator
bool BigInt::operator!=(const BigInt& other) const {
    return !(*this == other);
}

// Less than operator
bool BigInt::operator<(const BigInt& other) const {
    // Different sizes - fewer digits means smaller number
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }

    // Same size - compare digit by digit from most significant (end) to least
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }

    // All digits equal
    return false;
}

// Addition
BigInt BigInt::operator+(const BigInt& other) const {
    BigInt result;
    result.digits.clear();

    int carry = 0;
    size_t max_len = std::max(digits.size(), other.digits.size());

    for (size_t i = 0; i < max_len || carry; ++i) {
        int sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];

        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }

    return result;
}

// Multiply by small integer
BigInt BigInt::operator*(int n) const {
    BigInt result;
    result.digits.clear();

    int carry = 0;
    for (size_t i = 0; i < digits.size() || carry; ++i) {
        int prod = carry;
        if (i < digits.size()) prod += digits[i] * n;

        result.digits.push_back(prod % 10);
        carry = prod / 10;
    }

    // Remove trailing zeros (except for zero itself)
    while (result.digits.size() > 1 && result.digits.back() == 0) {
        result.digits.pop_back();
    }

    return result;
}

// BigInt * BigInt multiplication (grade-school algorithm)
BigInt BigInt::operator*(const BigInt& other) const {
    BigInt result;
    result.digits.assign(digits.size() + other.digits.size(), 0);

    // Multiply each digit of this by each digit of other
    for (size_t i = 0; i < digits.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < other.digits.size() || carry; ++j) {
            long long prod = result.digits[i + j] + carry;
            if (j < other.digits.size()) {
                prod += (long long)digits[i] * other.digits[j];
            }
            result.digits[i + j] = prod % 10;
            carry = prod / 10;
        }
    }

    // Remove leading zeros
    while (result.digits.size() > 1 && result.digits.back() == 0) {
        result.digits.pop_back();
    }

    return result;
}

// Power using exponentiation by squaring
BigInt BigInt::pow(int exp) const {
    if (exp == 0) return BigInt(1);
    if (exp == 1) return *this;

    BigInt result(1);
    BigInt base = *this;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * base;  // Odd: multiply result by base
        }
        base = base * base;  // Square the base (not double!)
        exp /= 2;
    }

    return result;
}

// Sum all digits
int BigInt::digit_sum() const {
    int sum = 0;
    for (int d : digits) {
        sum += d;
    }
    return sum;
}

int BigInt::num_digits() const {
    return digits.size();
}

// Convert to string
std::string BigInt::to_string() const {
    std::string s;
    for (int i = digits.size() - 1; i >= 0; --i) {
        s += ('0' + digits[i]);
    }
    return s;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const BigInt& b) {
    os << b.to_string();
    return os;
}

// Factorial
BigInt BigInt::factorial(int n) {
    BigInt result(1);
    for (int i = 2; i <= n; ++i) {
        result = result * i;
    }
    return result;
}
