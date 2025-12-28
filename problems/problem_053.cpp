
#include <gmpxx.h>

int problem_053( int limit ){

    int retCount = 0;

    for( int n = 1; n <= limit; n++ ){
        for( int r = 0; r <= n; r++ ){
            mpz_class combo;
            mpz_bin_uiui(combo.get_mpz_t(), n, r);
            if ( combo > 1'000'000 ) retCount++;
        }

    }

    return retCount;
}
