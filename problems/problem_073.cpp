
#include "../src/utils/utils.h"

long long int problem_073(int limit){

	long long int retTotal = 0;
	for( int d = 3; d <= limit; d++ ){
		for( int n = d / 3 + 1; n <= d / 2; n++ ){
			if ( gcd(n, d) == 1 ) retTotal++;
		}
	}

	return retTotal;
}



