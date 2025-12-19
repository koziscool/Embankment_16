

#include "../src/utils/utils.h"

long long int problem_006( int limit ){
    long long int sum = 0, squareSum = 0;
    for (int i = 1; i <= limit; i++){
        sum += i;
        squareSum += i * i;
    }
    return sum * sum - squareSum;
}