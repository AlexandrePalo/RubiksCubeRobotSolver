#include "transformations.h"
#include "configCombination.h"

void formulaULCornerULF(int cube[9][12]) {
  //formula LD'L'DLD'L'
  L(cube);
  Dc(cube);
  Lc(cube);
  D(cube);
  L(cube);
  Dc(cube);
  Lc(cube);
}

void formulaULCornerURF(int cube[9][12]) {
  //formula LDL'D'R'D2RD'R'DR
  L(cube);
  D(cube);
  Lc(cube);
  Dc(cube);
  Rc(cube);
  D(cube);
  D(cube);
  R(cube);
  Dc(cube);
  Rc(cube);
  D(cube);
  R(cube);
}

void formulaULCornerULB(int cube[9][12]) {
  //formula F'BD'B'F
  Fc(cube);
  B(cube);
  Dc(cube);
  Bc(cube);
  F(cube);
}

void formulaULCornerURB(int cube[9][12]) {
  //formula LDL'BDB'RD'R'
  L(cube);
  D(cube);
  Lc(cube);
  B(cube);
  D(cube);
  Bc(cube);
  R(cube);
  Dc(cube);
  Rc(cube);
}

void formulaURCornerULF(int cube[9][12]) {
  //formula R'DRD'D'F'DF
  Rc(cube);
  D(cube);
  R(cube);
  Dc(cube);
  Dc(cube);
  Fc(cube);
  D(cube);
  F(cube);
}

void formulaURCornerURF(int cube[9][12]) {
  //formula FD'2F'R'D2R
  F(cube);
  Dc(cube);
  Dc(cube);
  Fc(cube);
  Rc(cube);
  D(cube);
  D(cube);
  R(cube);
}

void formulaURCornerULB(int cube[9][12]) {
  //formula R'DRDL'DL
  Rc(cube);
  D(cube);
  R(cube);
  D(cube);
  Lc(cube);
  D(cube);
  L(cube);
}

void formulaURCornerURB(int cube[9][12]) {
  //formula R'DRB'DB
  Rc(cube);
  D(cube);
  R(cube);
  Bc(cube);
  D(cube);
  B(cube);
}

void formulaDLCornerULF(int cube[9][12]) {
  //formula DLD'L'
  D(cube);
  L(cube);
  Dc(cube);
  Lc(cube);
}

void formulaDLCornerURF(int cube[9][12]) {
  //formula D2FD'F'
  D(cube);
  D(cube);
  F(cube);
  Dc(cube);
  Fc(cube);
}

void formulaDLCornerULB(int cube[9][12]) {
  //formula BD'B'
  B(cube);
  Dc(cube);
  Bc(cube);
}

void formulaDLCornerURB(int cube[9][12]) {
  //formula D'RD'R'
  Dc(cube);
  R(cube);
  Dc(cube);
  Rc(cube);
}

void formulaDRCornerULF(int cube[9][12]) {
  //formula D'2F'DF
  Dc(cube);
  Dc(cube);
  Fc(cube);
  D(cube);
  F(cube);
}

void formulaDRCornerURF(int cube[9][12]) {
  //formula D'R'DR
  Dc(cube);
  Rc(cube);
  D(cube);
  R(cube);
}

void formulaDRCornerULB(int cube[9][12]) {
  //formula DL'DL
  D(cube);
  Lc(cube);
  D(cube);
  L(cube);
}

void formulaDRCornerURB(int cube[9][12]) {
  //formula B'DB
  Bc(cube);
  D(cube);
  B(cube);
}

void formulaUnderRCornerULF(int cube[9][12]) {
  //formula LD'2L'DLD'L'
  L(cube);
  Dc(cube);
  Dc(cube);
  Lc(cube);
  D(cube);
  L(cube);
  Dc(cube);
  Lc(cube);
}

void formulaUnderRCornerURF(int cube[9][12]) {
  //formula DF'D'FR'DR
  D(cube);
  Fc(cube);
  Dc(cube);
  F(cube);
  Rc(cube);
  D(cube);
  R(cube);
}

void formulaUnderRCornerULB(int cube[9][12]) {
  //formula BDB'DBD'B'
  B(cube);
  D(cube);
  Bc(cube);
  D(cube);
  B(cube);
  Dc(cube);
  Bc(cube);
}

void formulaUnderRCornerURB(int cube[9][12]) {
  //formula LDL'D'R'D2RD'R'DR
  L(cube);
  D(cube);
  Lc(cube);
  Dc(cube);
  Rc(cube);
  D(cube);
  D(cube);
  R(cube);
  Dc(cube);
  Rc(cube);
  D(cube);
  R(cube);
}

void formulaUnderLCornerULF(int cube[9][12]) {
  //formula DLD'2L'DLD'L'
  D(cube);
  L(cube);
  Dc(cube);
  Dc(cube);
  Lc(cube);
  D(cube);
  L(cube);
  Dc(cube);
  Lc(cube);
}

void formulaUnderLCornerURF(int cube[9][12]) {
  //formula R'D2RD'R'DR
  Rc(cube);
  D(cube);
  D(cube);
  R(cube);
  Dc(cube);
  Rc(cube);
  D(cube);
  R(cube);
}

void formulaUnderLCornerULB(int cube[9][12]) {
  //formula DL'D'LD'L'DL
  D(cube);
  Lc(cube);
  Dc(cube);
  L(cube);
  Dc(cube);
  Lc(cube);
  D(cube);
  L(cube);
}

void formulaUnderLCornerURB(int cube[9][12]) {
  //formula B'D'BD'B'DB
  Bc(cube);
  Dc(cube);
  B(cube);
  Dc(cube);
  Bc(cube);
  D(cube);
  B(cube);
}

int isStage1bComplete(int cube[9][12]){
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

  // First row of L, R, F, & B completed and centers aligned
  int colorL = cube[4][1];
  int firstRowLcompleted = 0;
  if ((cube[3][0] == colorL) && (cube[4][0] == colorL) && (cube[5][0] == colorL)) {
    firstRowLcompleted = 1;
  }

  int colorR = cube[4][7];
  int firstRowRcompleted = 0;
  if ((cube[3][8] == colorR) && (cube[4][8] == colorR) && (cube[5][8] == colorR)) {
    firstRowRcompleted = 1;
  }

  int colorF = cube[7][4];
  int firstRowFcompleted = 0;
  if ((cube[8][3] == colorF) && (cube[8][4] == colorF) && (cube[8][5] == colorF)) {
    firstRowFcompleted = 1;
  }
  
  int colorB = cube[1][4];
  int firstRowBcompleted = 0;
  if ((cube[0][3] == colorB) && (cube[0][4] == colorB) && (cube[0][5] == colorB)) {
    firstRowBcompleted = 1;
  }

  if (
    (Ucompleted == 1) &&
    (firstRowLcompleted == 1) &&
    (firstRowRcompleted == 1) &&
    (firstRowBcompleted == 1) &&
    (firstRowFcompleted == 1)
  ) {
    return 1;
  }
  return 0;
}

int solverStage1b(int cube[9][12], int consecutiveY) {
  int stage1bComplete = 0;

  // First check if stage1b is needed
  if (isStage1bComplete(cube) == 1) {
    stage1bComplete = 1;
  }

  if (stage1bComplete == 0) {
    // BE CAREFUL, center rows MUST be aligned with top rows
    // stage1a aligns the row, you need to keep it align in stage1b
    int colorU = cube[4][10];
    int colorF = cube[7][4];
    int colorB = cube[1][4];
    int colorR = cube[4][7];
    int colorL = cube[4][1];

    if ((cube[8][3] == colorU) && (cube[5][0] == colorF) && (cube[5][11] == colorL)) {
      formulaULCornerULF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[8][3] == colorU) &&
      (cube[5][0] == colorR) &&
      (cube[5][11] == colorF)
    ) {
      formulaULCornerURF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[8][3] == colorU) &&
      (cube[5][0] == colorL) &&
      (cube[5][11] == colorB)
    ) {
      formulaULCornerULB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[8][3] == colorU) &&
      (cube[5][0] == colorB) &&
      (cube[5][11] == colorR)
    ) {
      formulaULCornerURB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[8][5] == colorU) &&
      (cube[5][9] == colorF) &&
      (cube[5][8] == colorL)
    ) {
      formulaURCornerULF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[8][5] == colorU) &&
      (cube[5][9] == colorR) &&
      (cube[5][8] == colorF)
    ) {
      formulaURCornerURF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[8][5] == colorU) &&
      (cube[5][9] == colorL) &&
      (cube[5][8] == colorB)
    ) {
      formulaURCornerULB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[8][5] == colorU) &&
      (cube[5][9] == colorB) &&
      (cube[5][8] == colorR)
    ) {
      formulaURCornerURB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[6][3] == colorU) &&
      (cube[5][2] == colorL) &&
      (cube[5][3] == colorF)
    ) {
      formulaDLCornerULF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[6][3] == colorU) &&
      (cube[5][2] == colorF) &&
      (cube[5][3] == colorR)
    ) {
      formulaDLCornerURF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[6][3] == colorU) &&
      (cube[5][2] == colorB) &&
      (cube[5][3] == colorL)
    ) {
      formulaDLCornerULB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[6][3] == colorU) &&
      (cube[5][2] == colorR) &&
      (cube[5][3] == colorB)
    ) {
      formulaDLCornerURB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[6][5] == colorU) &&
      (cube[5][5] == colorL) &&
      (cube[5][6] == colorF)
    ) {
      formulaDRCornerULF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[6][5] == colorU) &&
      (cube[5][5] == colorF) &&
      (cube[5][6] == colorR)
    ) {
      formulaDRCornerURF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[6][5] == colorU) &&
      (cube[5][5] == colorB) &&
      (cube[5][6] == colorL)
    ) {
      formulaDRCornerULB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[6][5] == colorU) &&
      (cube[5][5] == colorR) &&
      (cube[5][6] == colorB)
    ) {
      formulaDRCornerURB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[5][5] == colorU) &&
      (cube[6][5] == colorF) &&
      (cube[5][6] == colorL)
    ) {
      formulaUnderRCornerULF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[5][5] == colorU) &&
      (cube[6][5] == colorR) &&
      (cube[5][6] == colorF)
    ) {
      formulaUnderRCornerURF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[5][5] == colorU) &&
      (cube[6][5] == colorL) &&
      (cube[5][6] == colorB)
    ) {
      formulaUnderRCornerULB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[5][5] == colorU) &&
      (cube[6][5] == colorB) &&
      (cube[5][6] == colorR)
    ) {
      formulaUnderRCornerURB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[5][3] == colorU) &&
      (cube[5][3] == colorF) &&
      (cube[6][3] == colorL)
    ) {
      formulaUnderLCornerULF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[5][3] == colorU) &&
      (cube[5][3] == colorR) &&
      (cube[6][3] == colorF)
    ) {
      formulaUnderLCornerURF(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[5][3] == colorU) &&
      (cube[5][3] == colorL) &&
      (cube[6][3] == colorB)
    ) {
      formulaUnderLCornerULB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[5][3] == colorU) &&
      (cube[5][3] == colorB) &&
      (cube[6][3] == colorR)
    ) {
      formulaUnderLCornerURB(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[5][11] == colorU) &&
      ((cube[8][3] != colorF) || (cube[5][0] != colorL))
    ) {
      // Blocked case 1
      // Down the UFL block
      L(cube);
      D(cube);
      Lc(cube);
      return solverStage1b(cube, 0);
    } else if (
      (cube[5][9] == colorU) &&
      ((cube[8][5] != colorF) || (cube[5][8] != colorR))
    ) {
      // Blocked case 2
      // Down the UFR block
      Rc(cube);
      Dc(cube);
      R(cube);
      return solverStage1b(cube, 0);
    } else {
      if (consecutiveY < 3) {
        // Y
        Y(cube);
        return solverStage1b(cube, consecutiveY + 1);
      } else {
        // Unreached case
        return 0;
      }
    }
  } else {
    //----- STAGE 1B END -----
    addToCombination(12, 0);
    //printfCube(cube);
    return 1;
  }
}
