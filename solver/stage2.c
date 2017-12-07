#include "transformations.h"
#include "configCombination.h"

void s2formulaL(int cube[9][12]) {
  //formula L (DLD'L'D'F'DF)
  D(cube);
  L(cube);
  Dc(cube);
  Lc(cube);
  Dc(cube);
  Fc(cube);
  D(cube);
  F(cube);
}

void s2formulaR(int cube[9][12]) {
  //formula R (D'R'DRDFD'F')
  Dc(cube);
  Rc(cube);
  D(cube);
  R(cube);
  D(cube);
  F(cube);
  Dc(cube);
  Fc(cube);
}

int isStage2Complete(int cube[9][12]) {
  // U completed
  int colorU = cube[4][10];
  int Ucompleted = 0;
  if (
    (cube[3][9] == colorU) &&
    (cube[3][10] == colorU) &&
    (cube[3][11] == colorU) &&
    (cube[4][9] == colorU) &&
    (cube[4][11] == colorU) &&
    (cube[5][9] == colorU) &&
    (cube[5][10] == colorU) &&
    (cube[5][11] == colorU)
  ) {
    Ucompleted = 1;
  }

  // First & second rows of L, R, F, & B completed
  int colorL = cube[4][1];
  int firstAndSecondRowsLcompleted = 0;
  if (
    (cube[3][0] == colorL) &&
    (cube[4][0] == colorL) &&
    (cube[5][0] == colorL) &&
    (cube[3][1] == colorL) &&
    (cube[5][1] == colorL)
  ) {
    firstAndSecondRowsLcompleted = 1;
  }

  int colorR = cube[4][7];
  int firstAndSecondRowsRcompleted = 0;
  if (
    (cube[3][8] == colorR) &&
    (cube[4][8] == colorR) &&
    (cube[5][8] == colorR) &&
    (cube[3][7] == colorR) &&
    (cube[5][7] == colorR)
  ) {
    firstAndSecondRowsRcompleted = 1;
  }

  int colorF = cube[7][4];
  int firstAndSecondRowsFcompleted = 0;
  if (
    (cube[8][3] == colorF) &&
    (cube[8][4] == colorF) &&
    (cube[8][5] == colorF) &&
    (cube[7][3] == colorF) &&
    (cube[7][5] == colorF)
  ) {
    firstAndSecondRowsFcompleted = 1;
  }
  int colorB = cube[1][4];
  int firstAndSecondRowsBcompleted = 0;
  if (
    (cube[0][3] == colorB) &&
    (cube[0][4] == colorB) &&
    (cube[0][5] == colorB) &&
    (cube[1][3] == colorB) &&
    (cube[1][5] == colorB)
  ) {
    firstAndSecondRowsBcompleted = 1;
  }

  if (
    (Ucompleted == 1) &&
    (firstAndSecondRowsLcompleted == 1) &&
    (firstAndSecondRowsRcompleted == 1) &&
    (firstAndSecondRowsFcompleted == 1) &&
    (firstAndSecondRowsBcompleted == 1)
  ) {
    return 1;
  }
  return 0;
}

int solverStage2(int cube[9][12], int consecutiveD, int consecutiveY, int consecutiveYbis) {
  int stage2Complete = 0;

  // First check if stage2 is needed
  if (isStage2Complete(cube) == 1) {
    stage2Complete = 1;
  }

  if (stage2Complete == 0) {
    // Check if formula is needed on F, with R or L formula
    if (
      (cube[6][4] == cube[7][4]) &&
      (cube[5][4] != cube[4][4]) &&
      (cube[5][4] == cube[4][1])
    ) {
      // The cube need to be moved to L or R
      // Formula L
      s2formulaL(cube);
      return solverStage2(cube, 0, 0, 0);
    } else if (
      (cube[6][4] == cube[7][4]) &&
      (cube[5][4] != cube[4][4]) &&
      (cube[5][4] == cube[4][7])
    ) {
      // The cube need to be moved to L or R
      // Formula R
      s2formulaR(cube);
      return solverStage2(cube, 0, 0, 0);
    } else {
      if (consecutiveD < 3) {
        //D
        D(cube);
        return solverStage2(cube, consecutiveD + 1, consecutiveY, 0);
      } else {
        if (consecutiveY < 3) {
          //Y
          Y(cube);
          return solverStage2(cube, 0, consecutiveY + 1, 0);
        } else {
          // Second phase to check wrongly placed edges
          if (consecutiveYbis < 3) {
            if ((cube[7][3] != cube[7][4]) || (cube[5][1] != cube[4][1])) {
              s2formulaL(cube);
              return solverStage2(cube, 0, 0, 0);
            } else if ((cube[7][4] != cube[7][5]) && (cube[5][7] != cube[4][7])) {
              s2formulaR(cube);
              return solverStage2(cube, 0, 0, 0);
            } else {
              //Y
              Y(cube);
              return solverStage2(cube, consecutiveY, consecutiveY, consecutiveYbis + 1);
            }
          } else {
            // Unreached case
            return 0;
          }
        }
      }
    }
  } else {
    //----- STAGE 2 END -----
      addToCombination(20, 0);
    // X2 needed for stage 3 and further
    X(cube);
    X(cube);
    return 1;
  }
}
