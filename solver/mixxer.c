#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "transformations.h"
#include "configCombination.h"
#include "../steppers/steppersControl.h"

void mix(int cube[9][12], int nbIterations) {
    // Mixing mode on
    mixingMode = 1;

    int r = 0;
    int i = 0;
    
    srand(time(NULL));
    
    for(i=0; i<nbIterations; i++) {
        r = rand() % 12;
        switch(r) {
            case 0:
                U(cube);
                break;
            case 1:
                Uc(cube);
                break;
            case 2:
                L(cube);
                break;
            case 3:
                Lc(cube);
                break;
            case 4:
                F(cube);
                break;
            case 5:
                Fc(cube);
                break;
            case 6:
                R(cube);
                break;
            case 7:
                Rc(cube);
                break;
            case 8:
                B(cube);
                break;
            case 9:
                Bc(cube);
                break;
            case 10:
                D(cube);
                break;
            case 11:
                Dc(cube);
                break;
        }
    }

    // Mixing mode off
    mixingMode = 0;
}

void mixReal(int nbIterations) {
    // Mix the real cube, without knowing the matrix state.

    int i,r;

    srand(time(NULL));

    for(i=0; i<nbIterations; i++) {
        r = rand() % 12;
        switch(r) {
            case 0:
                realU();
                break;
            case 1:
                realUc();
                break;
            case 2:
                realL();
                break;
            case 3:
                realLc();
                break;
            case 4:
                realF();
                break;
            case 5:
                realFc();
                break;
            case 6:
                realR();
                break;
            case 7:
                realRc();
                break;
            case 8:
                realB();
                break;
            case 9:
                realBc();
                break;
            case 10:
                realD();
                break;
            case 11:
                realDc();
                break;
        }
    }
}
