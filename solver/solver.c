#include <stdio.h>
#include "stage1a.h"
#include "stage1b.h"
#include "stage2.h"
#include "stage3a.h"
#include "stage3b.h"
#include "stage4.h"
#include "stage5.h"
#include "tools.h"
#include "configCombination.h"

int solver(int cube[9][12]) {
    // Initialize combination
    resetCombination();

    // Solve it!
    if (solverStage1a(cube, 0) == 1) {
        if (solverStage1b(cube, 0) == 1) {
            if (solverStage2(cube, 0, 0, 0) == 1) {
                if (solverStage3a(cube, 0, 0) == 1) {
                    if (solverStage3b(cube) == 1) {
                        if (solverStage4(cube) == 1) {
                            if (solverStage5(cube, 0, 0) == 1) {
                                return 1;
                            } else {
                                printf("Error stage 5\n");
                                return 0;
                            }
                        } else {
                            printf("Error stage 4\n");
                            return 0;
                        }
                    } else {
                        printf("Error stage 3b\n");
                        return 0;
                    }
                } else {
                    printf("Error stage 3a\n");
                    return 0;
                }
            } else {
                printf("Error stage 2\n");
                return 0;
            }
        } else {
            printf("Error stage 1b\n");
            return 0;
        }
    } else {
        printf("Error stage 1a\n");
        return 0;
    }
}
