#include "transformations.h"
#include "configCombination.h"

void s3formulaB(int cube[9][12]) {
  //formula b (RUR'URU2R')
  R(cube);
  U(cube);
  Rc(cube);
  U(cube);
  R(cube);
  U(cube);
  U(cube);
  Rc(cube);
}

int isStage3CompleteB(int cube[9][12]) {
  // Be careful, the cube was returned with X2

  // D completed
  int colorD = cube[4][4];
  int Dcompleted = 1;
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

  // U edges well oriented
  int UEdgesWellOriented = 0;
  if (
    (cube[4][0] == cube[4][1]) &&
    (cube[4][8] == cube[4][7]) &&
    (cube[8][4] == cube[7][4]) &&
    (cube[0][4] == cube[1][4])
  ) {
    UEdgesWellOriented = 1;
  }

  if (
    (Dcompleted == 1) &&
    (firstAndSecondRowsLcompleted == 1) &&
    (firstAndSecondRowsRcompleted == 1) &&
    (firstAndSecondRowsFcompleted == 1) &&
    (firstAndSecondRowsBcompleted == 1) &&
    (crossUcompleted == 1) &&
    (UEdgesWellOriented == 1)
  ) {
    return 1;
  }

  return 0;
}

int solverStage3b(int cube[9][12]) {
  int stage3CompleteB = 0;

  // First check if stage3 is needed
  if (isStage3CompleteB(cube) == 1) {
    stage3CompleteB = 1;
  }

  if (stage3CompleteB == 0) {
    int edgeLOK = 0;
    if (cube[4][0] == cube[4][1]) {
        edgeLOK = 1;
    }
    int edgeROK = 0;
    if (cube[4][8] == cube[4][7]) {
        edgeROK = 1;
    }
    int edgeFOK = 0;
    if (cube[8][4] == cube[7][4]) {
        edgeFOK = 1;
    }
    int edgeBOK = 0;
    if (cube[0][4] == cube[1][4]) {
        edgeBOK = 1;
    }
    
    if (
      ((edgeROK == 1) && (edgeBOK == 1)) || 
      ((edgeBOK == 1) && (edgeFOK == 1)) || 
      ((edgeLOK == 1) && (edgeROK == 1))
    ) {
      // Edge R and Edge B well oriented
      // Or 2 well oriented edges face each others
      s3formulaB(cube);
      return solverStage3b(cube);
    } else if (
      ((edgeFOK == 1) && (edgeROK == 1)) ||
      ((edgeFOK == 1) && (edgeLOK == 1)) ||
      ((edgeBOK == 1) && (edgeLOK == 1))
    ) {
        // Y
        Y(cube);
        return solverStage3b(cube);
    } else {
        // U
        U(cube);
        return solverStage3b(cube);
    }
  } else {
    //----- STAGE 3b END -----
      addToCombination(32, 0);
    return 1;
  }
}
