
#include "../src/utils/utils.h"
#include <tuple>

int problem_071(int limit){

	int retNumerator = 2, retDenominator = 5;
	for( int newDenominator = 9; newDenominator <= limit; newDenominator++ ){
		int newNumerator = newDenominator * 3 / 7;
		if( newNumerator /  (double) newDenominator > retNumerator / (double) retDenominator ){
			if ( gcd( newNumerator, newDenominator ) == 1 )
				std::tie( retNumerator, retDenominator ) = std::make_tuple( newNumerator, newDenominator );
		}
	}

	return retNumerator;
}

