#include "../src/utils/utils.h"

long long int problem_015( int limit ){
    long long int retSum = 0;
    for( int i = 0; i <= limit; i++ ){
        retSum += combinations(limit, i) * combinations(limit, i);
    }
    return retSum;
}