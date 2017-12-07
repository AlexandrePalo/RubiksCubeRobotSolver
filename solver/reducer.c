#include <stdio.h>
#include "../configCombination.h"

int reduceCombination () {
    /*
     Reduce the combination using a deep 1 algorithm
     If combination[k] is invert of combination[k-1]
     Then delete combination[k] & combination[k-1]
     Do until the number of reductions is 0

     Returns the number of reductions
     */
    int k;
    int reductions = 0;

    for (k=0; k<index; k++) {
        if ((combination[k][0] == 1) ||
            (combination[k][0] == 2) ||
            (combination[k][0] == 3) ||
            (combination[k][0] == 4) ||
            (combination[k][0] == 5) ||
            (combination[k][0] == 6)) {

            if ((combination[k][0] == combination[k-1][0]) &&
                (combination[k][1] != combination[k-1][1])) {

                reductions ++;
                printf("Want to reduce\n");

            }

        }
    }
    return reductions;
}
