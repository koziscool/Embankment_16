#include <vector>
#include <string>

long long int problem_040(){
    std::vector<long long int> digitsVector;
    digitsVector.push_back(0);
    int limit = 100'000;

    for (int i = 1; i < limit; i++ ){
        std::string s = std::to_string(i);
        for( auto c: s ) {
            digitsVector.push_back(int(c - 48));
            // need to subtract 48 to convert to int digit from ascii code
        }
    }

    return digitsVector.at(1) * 
                digitsVector.at(10) * 
                digitsVector.at(100) * 
                digitsVector.at(1000) * 
                digitsVector.at(10'000) * 
                digitsVector.at(100'000);
}