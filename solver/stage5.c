#include "transformations.h"
#include "configCombination.h"

void s5formula(int cube[9][12]) {
  //formula (RU2R'U'RU'R'L'U2LUL'UL)
  R(cube);
  U(cube);
  U(cube);
  Rc(cube);
  Uc(cube);
  R(cube);
  Uc(cube);
  Rc(cube);
  Lc(cube);
  U(cube);
  U(cube);
  L(cube);
  U(cube);
  Lc(cube);
  U(cube);
  L(cube);
}

int isStage5Complete(int cube[9][12]) {
  // Completed cube

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

  // F completed
  int colorF = cube[7][4];
  int Fcompleted = 0;
  if (
    (cube[6][3] == colorF) &&
    (cube[6][4] == colorF) &&
    (cube[6][5] == colorF) &&
    (cube[7][3] == colorF) &&
    (cube[7][5] == colorF) &&
    (cube[8][3] == colorF) &&
    (cube[8][4] == colorF) &&
    (cube[8][5] == colorF)
  ) {
    Fcompleted = 1;
  }

  // B completed
  int colorB = cube[1][4];
  int Bcompleted = 0;
  if (
    (cube[0][3] == colorB) &&
    (cube[0][4] == colorB) &&
    (cube[0][5] == colorB) &&
    (cube[1][3] == colorB) &&
    (cube[1][5] == colorB) &&
    (cube[2][3] == colorB) &&
    (cube[2][4] == colorB) &&
    (cube[2][5] == colorB)
  ) {
    Bcompleted = 1;
  }

  // L completed
  int colorL = cube[4][1];
  int Lcompleted = 0;
  if (
    (cube[3][0] == colorL) &&
    (cube[3][1] == colorL) &&
    (cube[3][2] == colorL) &&
    (cube[4][0] == colorL) &&
    (cube[4][2] == colorL) &&
    (cube[5][0] == colorL) &&
    (cube[5][1] == colorL) &&
    (cube[5][2] == colorL)
  ) {
    Lcompleted = 1;
  }

  // R completed
  int colorR = cube[4][7];
  int Rcompleted = 0;
  if (
    (cube[3][6] == colorR) &&
    (cube[3][7] == colorR) &&
    (cube[3][8] == colorR) &&
    (cube[4][6] == colorR) &&
    (cube[4][8] == colorR) &&
    (cube[5][6] == colorR) &&
    (cube[5][7] == colorR) &&
    (cube[5][8] == colorR)
  ) {
    Rcompleted = 1;
  }

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

  if (
    (Dcompleted == 1) &&
    (Fcompleted == 1) &&
    (Bcompleted == 1) &&
    (Lcompleted == 1) &&
    (Rcompleted == 1) &&
    (Ucompleted == 1)
  ) {
    return 1;
  }
  return 0;
}

int solverStage5(int cube[9][12], int consecutiveY, int consecutiveFormula) {
  int stage5Complete = 0;

  // First check if stage5 is needed
  if (isStage5Complete(cube) == 1) {
    stage5Complete = 1;
  }

  if (stage5Complete == 0) {
    // One well placed and oriented corners and FUL
    // But the corner FUR is NOT
    if (
      (cube[5][0] == cube[4][1]) &&
      (cube[8][3] == cube[7][4]) &&
      (cube[5][11] == cube[4][10]) &&
      ((cube[8][5] != cube[7][4]) ||
        (cube[5][8] != cube[4][7]) ||
        (cube[5][9] != cube[4][10]))
    ) {
        s5formula(cube);
        return solverStage5(cube, 0, 0);
    } else {
      if (consecutiveY < 3) {
          // Y
          Y(cube);
          return solverStage5(cube, consecutiveY + 1, 0);
      } else {
        if (consecutiveFormula < 3) {
            s5formula(cube);
            return solverStage5(cube, 0, consecutiveFormula + 1);
        } else {
          // Unreached case
          return 0;
        }
      }
    }
  } else {
    //----- STAGE 5 END -----
      addToCombination(50, 0);
    return 1;
  }
}
