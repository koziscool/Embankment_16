
#include "../src/utils/bigint.h"

#include <string>
#include <algorithm>

int problem_055(int problemLimit){

    int retCount = 0, iterationLimit = 50;
    bool isLychrel;

    for( int i = 10; i < problemLimit; i++){
        BigInt currentNumber(i);
        isLychrel = true;

        for( int _ = 0; _ < iterationLimit; _++){
            currentNumber = currentNumber.reverseAndAdd();

            if( currentNumber.isPalindrome() ) {
                isLychrel = false;
                break;
            };
        }
        if ( isLychrel ) retCount++;
    }

    return retCount;
} 
