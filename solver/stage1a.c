#include "transformations.h"
#include "configCombination.h"

void formulaUEdgeUL(int cube[9][12]) {
  //formula F'L'
  Fc(cube);
  Lc(cube);
}

void formulaUEdgeUR(int cube[9][12]) {
  //formula FR'
  F(cube);
  R(cube);
}

void formulaUEdgeUB(int cube[9][12]) {
  //formula F'U'L'U
  Fc(cube);
  Uc(cube);
  Lc(cube);
  U(cube);
}

void formulaUEdgeUF(int cube[9][12]) {
  //formula F'UL'U'
  Fc(cube);
  U(cube);
  Lc(cube);
  Uc(cube);
}

void formulaREdgeUL(int cube[9][12]) {
  //formula U'RU2
  Uc(cube);
  R(cube);
  U(cube);
  U(cube);
}

void formulaREdgeUR(int cube[9][12]) {
  //formula R
  R(cube);
}

void formulaREdgeUB(int cube[9][12]) {
  //formula URU'
  U(cube);
  R(cube);
  Uc(cube);
}

void formulaREdgeUF(int cube[9][12]) {
  //formula U'RU
  Uc(cube);
  R(cube);
  U(cube);
}

void formulaDEdgeUL(int cube[9][12]) {
  //formula FL'F'
  F(cube);
  Lc(cube);
  Fc(cube);
}

void formulaDEdgeUR(int cube[9][12]) {
  //formula UF'R
  U(cube);
  Fc(cube);
  R(cube);
}

void formulaDEdgeUB(int cube[9][12]) {
  //formula U2FUL'U
  U(cube);
  U(cube);
  F(cube);
  U(cube);
  Lc(cube);
  U(cube);
}

void formulaDEdgeUF(int cube[9][12]) {
  //formula F'UL'U'
  Fc(cube);
  U(cube);
  Lc(cube);
  Uc(cube);
}

void formulaLEdgeUL(int cube[9][12]) {
  //formula L'
  Lc(cube);
}

void formulaLEdgeUR(int cube[9][12]) {
  //formula U2L'U'U'
  U(cube);
  U(cube);
  Lc(cube);
  Uc(cube);
  Uc(cube);
}

void formulaLEdgeUB(int cube[9][12]) {
  //formula U'L'U
  Uc(cube);
  Lc(cube);
  U(cube);
}

void formulaLEdgeUF(int cube[9][12]) {
  //formula UL'U'
  U(cube);
  Lc(cube);
  Uc(cube);
}

void formulaUnderDEdgeUL(int cube[9][12]) {
  //formula D'L'2
  Dc(cube);
  Lc(cube);
  Lc(cube);
}

void formulaUnderDEdgeUR(int cube[9][12]) {
  //formula DR2
  D(cube);
  R(cube);
  R(cube);
}

void formulaUnderDEdgeUB(int cube[9][12]) {
  //formula D2B2
  D(cube);
  D(cube);
  B(cube);
  B(cube);
}

void formulaUnderDEdgeUF(int cube[9][12]) {
  //formula F2
  F(cube);
  F(cube);
}


int isStage1aComplete(int cube[9][12]) {
  // cross U completed
  int colorU = cube[4][10];
  int crossUcompleted = 0;
  if (
    (cube[3][10] == colorU) &&
    (cube[4][9] == colorU) &&
    (cube[4][11] == colorU) &&
    (cube[5][10] == colorU) &&
    (cube[4][0] == cube[4][1]) &&
    (cube[0][4] == cube[1][4]) &&
    (cube[8][4] == cube[7][4]) &&
    (cube[4][8] == cube[4][7])
  ) {
    crossUcompleted = 1;
  }

  if (crossUcompleted == 1) {
    return 1;
  }
  return 0;
}

int solverStage1a(int cube[9][12], int consecutiveY) {
  int stage1aComplete = 0;

  // First check if stage1a is needed
  if (isStage1aComplete(cube) == 1) {
    stage1aComplete = 1;
  }

  if (stage1aComplete != 1) {
    // BE CAREFUL, center rows MUST be aligned with top rows

    int colorU = cube[4][10];
    int colorF = cube[7][4];
    int colorB = cube[1][4];
    int colorR = cube[4][7];
    int colorL = cube[4][1];

    if ((cube[8][4] == colorU) && (cube[5][10] == colorL)) {
      formulaUEdgeUL(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[8][4] == colorU) && (cube[5][10] == colorR)) {
      formulaUEdgeUR(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[8][4] == colorU) && (cube[5][10] == colorB)) {
      formulaUEdgeUB(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[8][4] == colorU) && (cube[5][10] == colorF)) {
      formulaUEdgeUF(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[7][5] == colorU) && (cube[5][7] == colorL)) {
      formulaREdgeUL(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[7][5] == colorU) && (cube[5][7] == colorR)) {
      formulaREdgeUR(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[7][5] == colorU) && (cube[5][7] == colorB)) {
      formulaREdgeUB(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[7][5] == colorU) && (cube[5][7] == colorF)) {
      formulaREdgeUF(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[6][4] == colorU) && (cube[5][4] == colorL)) {
      formulaDEdgeUL(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[6][4] == colorU) && (cube[5][4] == colorR)) {
      formulaDEdgeUR(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[6][4] == colorU) && (cube[5][4] == colorB)) {
      formulaDEdgeUB(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[6][4] == colorU) && (cube[5][4] == colorF)) {
      formulaDEdgeUF(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[7][3] == colorU) && (cube[5][1] == colorL)) {
      formulaLEdgeUL(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[7][3] == colorU) && (cube[5][1] == colorR)) {
      formulaLEdgeUR(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[7][3] == colorU) && (cube[5][1] == colorB)) {
      formulaLEdgeUB(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[7][3] == colorU) && (cube[5][1] == colorF)) {
      formulaLEdgeUF(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[5][4] == colorU) && (cube[6][4] == colorL)) {
      formulaUnderDEdgeUL(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[5][4] == colorU) && (cube[6][4] == colorR)) {
      formulaUnderDEdgeUR(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[5][4] == colorU) && (cube[6][4] == colorB)) {
      formulaUnderDEdgeUB(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[5][4] == colorU) && (cube[6][4] == colorF)) {
      formulaUnderDEdgeUF(cube);
      return solverStage1a(cube, 0);
    } else if ((cube[5][10] == colorU) && (cube[8][4] != colorF)) {
      //Down edge from U
      //F2
      F(cube);
      F(cube);
      return solverStage1a(cube, 0);
    } else {
      if (consecutiveY < 3) {
        //Y
        Y(cube);
        return solverStage1a(cube, consecutiveY + 1);
      } else {
        // Unreached case
        return 0;
      }
    }
  } else {
    //----- STAGE 1A END -----
    addToCombination(11, 0);
    return 1;
  }
}
