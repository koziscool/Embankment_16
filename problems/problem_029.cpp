
#include "../src/utils/bigint.h"

#include <set>

long long int problem_029(int limit){
    std::set<BigInt> retSet = {};

    for(int a = 2; a <= limit; a++ ){
        BigInt aa(a);
        for(int b = 2; b <= limit; b++ ){
            retSet.insert( aa.pow(b) );
        }
    }
    
    return retSet.size();

}