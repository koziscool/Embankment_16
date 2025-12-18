
// Problem 4: Largest palindrome product
// Find the largest palindrome made from the product of two 3-digit numbers

#include "../src/utils/utils.h"

#include <cmath>

int problem_004(int numDigits) {
    int retPal = 0;
    for( int a = std::pow(10, numDigits - 1 ); a < std::pow(10, numDigits); a++ ){
        for( int b = a+1; b < std::pow(10, numDigits); b++ ){
            if( isPalindrome(a*b) && a*b > retPal )  retPal = a*b;
        }
    }
    return retPal;
}
