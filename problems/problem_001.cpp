
// Problem 1: Multiples of 3 or 5
// Find the sum of all the multiples of 3 or 5 below 1000

int problem_001(int limit) {
    int total = 0;
    for( int i = 1; i < limit; i++ ){
        if( i % 3 == 0 || i % 5 == 0 )
            total += i;
    }

    return total;
}

