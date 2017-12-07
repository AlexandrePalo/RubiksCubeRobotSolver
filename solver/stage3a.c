#include "transformations.h"
#include "configCombination.h"

void s3formulaA(int cube[9][12]) {
  //formula a (FRUR'U'F')
  F(cube);
  R(cube);
  U(cube);
  Rc(cube);
  Uc(cube);
  Fc(cube);
}


int isStage3CompleteA(int cube[9][12]) {
    // Be careful, the cube was returned with X2

    // D completed
    int colorD = cube[4][4];
    int Dcompleted = 0;
    if (
      (cube[3][3] == colorD) &&
      (cube[3][4] == colorD) &&
      (cube[3][5] == colorD) &&
      (cube[4][3] == colorD) &&
      (cube[4][5] == colorD) &&
      (cube[5][3] == colorD) &&
      (cube[5][4] == colorD) &&
      (cube[5][5] == colorD)
    ) {
      Dcompleted = 1;
    }

    // First & second rows of L, R, F, & B completed
    int colorL = cube[4][1];
    int firstAndSecondRowsLcompleted = 0;
    if (
      (cube[3][2] == colorL) &&
      (cube[4][2] == colorL) &&
      (cube[5][2] == colorL) &&
      (cube[3][1] == colorL) &&
      (cube[5][1] == colorL)
    ) {
      firstAndSecondRowsLcompleted = 1;
    }

    int colorR = cube[4][7];
    int firstAndSecondRowsRcompleted = 0;
    if (
      (cube[3][6] == colorR) &&
      (cube[4][6] == colorR) &&
      (cube[5][6] == colorR) &&
      (cube[3][7] == colorR) &&
      (cube[5][7] == colorR)
    ) {
      firstAndSecondRowsRcompleted = 1;
    }

    int colorF = cube[7][4];
    int firstAndSecondRowsFcompleted = 0;
    if (
      (cube[6][3] == colorF) &&
      (cube[6][4] == colorF) &&
      (cube[6][5] == colorF) &&
      (cube[7][3] == colorF) &&
      (cube[7][5] == colorF)
    ) {
      firstAndSecondRowsFcompleted = 1;
    }

    int colorB = cube[1][4];
    int firstAndSecondRowsBcompleted = 0;
    if (
      (cube[2][3] == colorB) &&
      (cube[2][4] == colorB) &&
      (cube[2][5] == colorB) &&
      (cube[1][3] == colorB) &&
      (cube[1][5] == colorB)
    ) {
      firstAndSecondRowsBcompleted = 1;
    }

    // cross U completed
    int colorU = cube[4][10];
    int crossUcompleted = 0;
    if (
      (cube[4][9] == colorU) &&
      (cube[4][11] == colorU) &&
      (cube[3][10] == colorU) &&
      (cube[5][10] == colorU)
    ) {
      crossUcompleted = 1;
    }

    if (
      (Dcompleted == 1) &&
      (firstAndSecondRowsLcompleted == 1) &&
      (firstAndSecondRowsRcompleted == 1) &&
      (firstAndSecondRowsFcompleted == 1) &&
      (firstAndSecondRowsBcompleted == 1) &&
      (crossUcompleted == 1)
    ) {
      return 1;
    }

  return 0;
}


int solverStage3a(int cube[9][12], int consecutiveU, int wd) {
  int stage3CompleteA = 0;

  // First check if stage3 is needed
  if (isStage3CompleteA(cube) == 1) {
    stage3CompleteA = 1;
  }

  if (stage3CompleteA == 0) {
    int colorU = cube[4][10];

    if (
      ((cube[4][9] == colorU) && (cube[4][11] == colorU)) ||
      ((cube[4][11] == colorU) && (cube[3][10] == colorU))
    ) {
      // line well oriented or half cross well oriented
      s3formulaA(cube);
      return solverStage3a(cube, 0, 0);
    } else {
      if (consecutiveU < 3) {
        // U and retry
        U(cube);
        return solverStage3a(cube, consecutiveU + 1, 0);
      } else {
        if (wd < 2) {
            s3formulaA(cube);
            return solverStage3a(cube, 0, wd + 1);
        } else {
            // Unreached case
            return 0;
        }
      }
    }
  } else {
    //----- STAGE 3a END -----
      addToCombination(31, 0);
    return 1;
  }
}
