#include "transformations.h"
#include "configCombination.h"

void s4formula(int cube[9][12]) {
  //formula (URU'L'UR'U'L)
  U(cube);
  R(cube);
  Uc(cube);
  Lc(cube);
  U(cube);
  Rc(cube);
  Uc(cube);
  L(cube);
}

int isCornerWellPlaced(int cFace1, int cFace2, int cFace3, int color1, int color2, int color3) {
  int colorsArray[3] = {color1, color2, color3};
  int placementFace1 = 0;
  int placementFace2 = 0;
  int placementFace3 = 0;
  int i = 0;
  
  for(i=0; i<3; i++) {
    if (colorsArray[i] == cFace1) {
        placementFace1 = 1;
    }
  }
  for(i=0; i<3; i++) {
    if (colorsArray[i] == cFace2) {
        placementFace2 = 1;
    }      
  }
  for(i=0; i<3; i++) {
    if (colorsArray[i] == cFace3) {
        placementFace3 = 1;
    }      
  }
  
  if ((placementFace1 == 1) && (placementFace2 == 1) && (placementFace3 == 1)) {
      return 1;
  } else {
      return 0;
  }
}

int isStage4Complete(int cube[9][12]) {
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
  int UEdgesWellOriented = 1;
  if (
    (cube[4][0] == cube[4][1]) &&
    (cube[4][8] == cube[4][7]) &&
    (cube[8][4] == cube[7][4]) &&
    (cube[0][4] == cube[1][4])
  ) {
    UEdgesWellOriented = 1;
  }

  // U corners well placed (colors)
  int UCornesWellPlaced = 0;
  if (
    (isCornerWellPlaced(
      cube[3][0],
      cube[0][3],
      cube[3][11],
      cube[4][1],
      cube[1][4],
      cube[4][10]
    ) == 1) &&
    (isCornerWellPlaced(
      cube[5][0],
      cube[8][3],
      cube[5][11],
      cube[4][1],
      cube[7][4],
      cube[4][10]
    ) == 1) &&
    (isCornerWellPlaced(
      cube[0][5],
      cube[3][8],
      cube[3][9],
      cube[1][4],
      cube[4][7],
      cube[4][10]
    ) == 1) &&
    (isCornerWellPlaced(
      cube[8][5],
      cube[5][8],
      cube[5][9],
      cube[7][4],
      cube[4][7],
      cube[4][10]
    ) == 1)
  ) {
    UCornesWellPlaced = 1;
  }

  if (
    (Dcompleted == 1) &&
    (firstAndSecondRowsLcompleted == 1) &&
    (firstAndSecondRowsRcompleted == 1) &&
    (firstAndSecondRowsFcompleted == 1) &&
    (firstAndSecondRowsBcompleted == 1) &&
    (crossUcompleted == 1) &&
    (UEdgesWellOriented == 1) &&
    (UCornesWellPlaced == 1)
  ) {
    return 1;
  }
  return 0;
}

int solverStage4(int cube[9][12]) {
  int stage4Complete = 0;

  // First check if stage4 is needed
  if (isStage4Complete(cube) == 1) {
    stage4Complete = 1;
  }

  if (stage4Complete == 0) {
    int nbCornersPlaced = 0;
    int cornerULBPlaced = isCornerWellPlaced(
      cube[3][0],
      cube[0][3],
      cube[3][11],
      cube[4][1],
      cube[1][4],
      cube[4][10]
    );
    int cornerUFLPlaced = isCornerWellPlaced(
      cube[5][0],
      cube[8][3],
      cube[5][11],
      cube[4][1],
      cube[7][4],
      cube[4][10]
    );
    int cornerUBRPlaced = isCornerWellPlaced(
      cube[0][5],
      cube[3][8],
      cube[3][9],
      cube[1][4],
      cube[4][7],
      cube[4][10]
    );
    int cornerUFRPlaced = isCornerWellPlaced(
      cube[8][5],
      cube[5][8],
      cube[5][9],
      cube[7][4],
      cube[4][7],
      cube[4][10]
    );
    nbCornersPlaced = cornerULBPlaced + cornerUFLPlaced + cornerUBRPlaced + cornerUFRPlaced;
    if (nbCornersPlaced == 1) {
      if (cornerUFRPlaced == 1) {
          s4formula(cube);
          return solverStage4(cube);
      } else {
          // Y
          Y(cube);
          return solverStage4(cube);
      }
    } else if (nbCornersPlaced == 0) {
        s4formula(cube);
        return solverStage4(cube);
    }
  } else {
    //----- STAGE 4 END -----
      addToCombination(40, 0);
    return 1;
  }
}
