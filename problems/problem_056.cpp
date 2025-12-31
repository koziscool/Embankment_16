
#include "../src/utils/bigint.h"

int problem_056(int limit){
    int ds, maxDigitSum = 0;

    for(int a = 1; a <= limit; a++ ){
        BigInt aa(a);
        for(int b = 1; b <= limit; b++ ){
            ds = aa.pow(b).digit_sum();
            if ( ds > maxDigitSum ) maxDigitSum = ds;
        }
    }
    
    return maxDigitSum;
}