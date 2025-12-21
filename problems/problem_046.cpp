
#include "../src/utils/utils.h"

#include <cmath>
#include <vector>

long long int problem_046(){
    long int oddCounter = 3;
    double maybeSquare;
    std::vector<long long int> primes = getPrimes(10'000'000);

    while(true){
        for( auto p: primes){
            if(p > oddCounter)
                return oddCounter;

            maybeSquare =  ( oddCounter - p ) / 2; 

            if( std::sqrt(maybeSquare) == int( std::sqrt(maybeSquare) ) )
                break;
        }
        oddCounter += 2;
    }
}