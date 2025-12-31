
#include "problems.h"

long long int problem_028( int gridSize ){

    long int numRings = gridSize / 2;
    int retTotal = 1, bottomRightCorner = 3, increment = 2;
    
    for( int _ = 0; _ < numRings; _++ ){
        retTotal += 4 * bottomRightCorner + 6 * increment;
        bottomRightCorner += 4*increment + 2;
        increment += 2;
    }

    return retTotal;
}