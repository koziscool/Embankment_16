
#include <vector>
#include <algorithm>
#include <cmath>

long long int problem_043(){
    long long int retSum = 0;
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> digits(std::begin(arr), std::end(arr));

    do {
        if( (digits.at(1) * 100 + digits[2] * 10 + digits[3]) % 2 == 0 )
            if( (digits.at(2) * 100 + digits[3] * 10 + digits[4]) % 3 == 0 )
                if( (digits.at(3) *100 + digits[4] * 10 + digits[5]) % 5 == 0 )
                    if( (digits.at(4) *100 + digits[5] * 10 + digits[6]) % 7 == 0 )
                        if( (digits.at(5) *100 + digits[6] * 10 + digits[7]) % 11 == 0 )
                            if( (digits.at(6) *100 + digits[7] * 10 + digits[8]) % 13 == 0 )
                                if( (digits.at(7) *100 + digits[8] * 10 + digits[9]) % 17 == 0 ){
                                    for( int i = 0; i <= 9; i++ ){
                                        retSum += digits.at(i) * std::pow(10, 9 - i);
                                    }
                                }
        

    } while( std::next_permutation( digits.begin(), digits.end() ) );

    return retSum;
}