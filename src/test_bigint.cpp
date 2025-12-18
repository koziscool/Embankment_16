#include <iostream>
#include <cassert>
#include "utils/bigint.h"

void test_constructors() {
    std::cout << "Testing constructors..." << std::endl;

    BigInt a(123);
    std::cout << "  BigInt(123) = " << a << std::endl;
    assert(a.to_string() == "123");

    BigInt b("987654321");
    std::cout << "  BigInt(\"987654321\") = " << b << std::endl;
    assert(b.to_string() == "987654321");

    BigInt c(0);
    std::cout << "  BigInt(0) = " << c << std::endl;
    assert(c.to_string() == "0");

    std::cout << "  ✓ Constructors pass" << std::endl;
}

void test_addition() {
    std::cout << "Testing addition..." << std::endl;

    BigInt a(123);
    BigInt b(456);
    BigInt c = a + b;
    std::cout << "  " << a << " + " << b << " = " << c << std::endl;
    assert(c.to_string() == "579");

    BigInt d("999999999999");
    BigInt e("1");
    BigInt f = d + e;
    std::cout << "  " << d << " + " << e << " = " << f << std::endl;
    assert(f.to_string() == "1000000000000");

    std::cout << "  ✓ Addition passes" << std::endl;
}

void test_multiply_int() {
    std::cout << "Testing multiplication by int..." << std::endl;

    BigInt a(123);
    BigInt b = a * 5;
    std::cout << "  " << a << " × 5 = " << b << std::endl;
    assert(b.to_string() == "615");

    BigInt c("999999999");
    BigInt d = c * 2;
    std::cout << "  " << c << " × 2 = " << d << std::endl;
    assert(d.to_string() == "1999999998");

    std::cout << "  ✓ Multiplication by int passes" << std::endl;
}

void test_multiply_bigint() {
    std::cout << "Testing BigInt * BigInt..." << std::endl;

    BigInt a(123);
    BigInt b(456);
    BigInt c = a * b;
    std::cout << "  " << a << " × " << b << " = " << c << std::endl;
    assert(c.to_string() == "56088");

    BigInt d("999");
    BigInt e("999");
    BigInt f = d * e;
    std::cout << "  " << d << " × " << e << " = " << f << std::endl;
    assert(f.to_string() == "998001");

    BigInt g("12345");
    BigInt h("67890");
    BigInt i = g * h;
    std::cout << "  " << g << " × " << h << " = " << i << std::endl;
    assert(i.to_string() == "838102050");

    std::cout << "  ✓ BigInt multiplication passes" << std::endl;
}

void test_power() {
    std::cout << "Testing power..." << std::endl;

    BigInt a(2);
    BigInt b = a.pow(10);
    std::cout << "  2^10 = " << b << std::endl;
    assert(b.to_string() == "1024");

    BigInt c(2);
    BigInt d = c.pow(16);
    std::cout << "  2^16 = " << d << std::endl;
    assert(d.to_string() == "65536");

    BigInt e(10);
    BigInt f = e.pow(5);
    std::cout << "  10^5 = " << f << std::endl;
    assert(f.to_string() == "100000");

    std::cout << "  ✓ Power passes" << std::endl;
}

void test_large_power() {
    std::cout << "Testing 2^1000 (for Problem 16)..." << std::endl;

    BigInt a(2);
    BigInt b = a.pow(1000);
    std::string result = b.to_string();

    // 2^1000 is a 302-digit number
    assert(result.length() == 302);

    // First few digits: 10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251...
    assert(result.substr(0, 10) == "1071508607");

    std::cout << "  2^1000 has " << result.length() << " digits" << std::endl;
    std::cout << "  First 50 digits: " << result.substr(0, 50) << std::endl;
    std::cout << "  ✓ 2^1000 passes" << std::endl;
}

void test_digit_sum() {
    std::cout << "Testing digit_sum..." << std::endl;

    BigInt a(123);
    std::cout << "  digit_sum(" << a << ") = " << a.digit_sum() << std::endl;
    assert(a.digit_sum() == 6);  // 1+2+3

    BigInt b("999");
    std::cout << "  digit_sum(" << b << ") = " << b.digit_sum() << std::endl;
    assert(b.digit_sum() == 27);  // 9+9+9

    // Problem 16: sum of digits of 2^1000
    BigInt c(2);
    BigInt d = c.pow(1000);
    int sum = d.digit_sum();
    std::cout << "  digit_sum(2^1000) = " << sum << std::endl;
    assert(sum == 1366);  // Known answer from Project Euler

    std::cout << "  ✓ digit_sum passes (Problem 16 answer: " << sum << ")" << std::endl;
}

void test_copy_and_equality() {
    std::cout << "Testing copy constructor and equality..." << std::endl;

    BigInt a(12345);
    BigInt b = a;  // Copy constructor
    std::cout << "  " << a << " == " << b << " : " << (a == b ? "true" : "false") << std::endl;
    assert(a == b);
    assert(!(a != b));

    BigInt c(12345);
    std::cout << "  " << a << " == " << c << " : " << (a == c ? "true" : "false") << std::endl;
    assert(a == c);

    BigInt d(99999);
    std::cout << "  " << a << " != " << d << " : " << (a != d ? "true" : "false") << std::endl;
    assert(a != d);
    assert(!(a == d));

    BigInt e(2);
    BigInt f = e.pow(100);
    BigInt g = f;  // Copy large number
    std::cout << "  2^100 copied: " << f.to_string().substr(0, 20) << "... == "
              << g.to_string().substr(0, 20) << "... : " << (f == g ? "true" : "false") << std::endl;
    assert(f == g);

    std::cout << "  ✓ Copy constructor and equality pass" << std::endl;
}

void test_output() {
    std::cout << "Testing output operator..." << std::endl;

    BigInt a(12345);
    std::cout << "  BigInt(12345) = " << a << std::endl;

    BigInt b(2);
    BigInt c = b.pow(20);
    std::cout << "  2^20 = " << c << std::endl;

    std::cout << "  ✓ Output operator works" << std::endl;
}

int main() {
    std::cout << std::endl;
    std::cout << "=== BigInt Test Suite ===" << std::endl;
    std::cout << std::endl;

    test_constructors();
    test_copy_and_equality();
    test_addition();
    test_multiply_int();
    test_multiply_bigint();
    test_power();
    test_large_power();
    test_digit_sum();
    test_output();

    std::cout << std::endl;
    std::cout << "=== All tests passed! ===" << std::endl;
    std::cout << std::endl;

    return 0;
}
