#include "./configState.h"
#include "./configCombination.h"

/*
        0    1   2  3   4   5   6    7  8    9  10   11

  0    {00, 00, 00, 01, 02, 03, 00, 00, 00, 00, 00, 00},
  1    {00, 00, 00, 04, 05, 06, 00, 00, 00, 00, 00, 00},
  2    {00, 00, 00, 07, 08, 09, 00, 00, 00, 00, 00, 00},
  3    {10, 11, 12, 19, 20, 21, 28, 29, 30, 37, 38, 39},
  4    {13, 14, 15, 22, 23, 24, 31, 32, 33, 40, 41, 42},
  5    {16, 17, 18, 25, 26, 27, 34, 35, 36, 43, 44, 45},
  6    {00, 00, 00, 46, 47, 48, 00, 00, 00, 00, 00, 00},
  7    {00, 00, 00, 49, 50, 51, 00, 00, 00, 00, 00, 00},
  8    {00, 00, 00, 52, 53, 54, 00, 00, 00, 00, 00, 00}
  */

void U(int c[9][12]) {
  // Add to combination
  addToCombination(motorIdByFunction('U'), 0);

  // Transform cube
  int map[20][4] = {
    {3, 0, 0, 5},
    {4, 0, 0, 4},
    {5, 0, 0, 3},

    {0, 3, 3, 8},
    {0, 4, 4, 8},
    {0, 5, 5, 8},

    {3, 8, 8, 5},
    {4, 8, 8, 4},
    {5, 8, 8, 3},

    {8, 3, 3, 0},
    {8, 4, 4, 0},
    {8, 5, 5, 0},

    {3, 9, 5, 9},
    {3, 10, 4, 9},
    {3, 11, 3, 9},
    {4, 9, 5, 10},
    {4, 11, 3, 10},
    {5, 9, 5, 11},
    {5, 10, 4, 11},
    {5, 11, 3, 11}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void Uc(int c[9][12]) {
    // Add to combination
    addToCombination(motorIdByFunction('U'), 1);

    // Transform cube
  int map[20][4] = {
    {3, 0, 8, 3},
    {4, 0, 8, 4},
    {5, 0, 8, 5},

    {0, 3, 5, 0},
    {0, 4, 4, 0},
    {0, 5, 3, 0},

    {8, 3, 5, 8},
    {8, 4, 4, 8},
    {8, 5, 3, 8},

    {3, 8, 0, 3},
    {4, 8, 0, 4},
    {5, 8, 0, 5},

    {3, 9, 3, 11},
    {3, 10, 4, 11},
    {3, 11, 5, 11},
    {4, 9, 3, 10},
    {4, 11, 5, 10},
    {5, 9, 3, 9},
    {5, 10, 4, 9},
    {5, 11, 5, 9}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void L(int c[9][12]) {
    // Add to combination
    addToCombination(motorIdByFunction('L'), 0);

    // Transform cube
  int map[20][4] = {
      {0, 3, 5, 11},
      {1, 3, 4, 11},
      {2, 3, 3, 11},

      {3, 3, 0, 3},
      {4, 3, 1, 3},
      {5, 3, 2, 3},

      {6, 3, 3, 3},
      {7, 3, 4, 3},
      {8, 3, 5, 3},

      {3, 11, 8, 3},
      {4, 11, 7, 3},
      {5, 11, 6, 3},

      {3, 0, 5, 0},
      {3, 1, 4, 0},
      {3, 2, 3, 0},
      {4, 0, 5, 1},
      {4, 2, 3, 1},
      {5, 0, 5, 2},
      {5, 1, 4, 2},
      {5, 2, 3, 2}
    };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void Lc(int c[9][12]) {
    // Add to combination
    addToCombination(motorIdByFunction('L'), 1);

    // Transform cube
  int map[20][4] = {
    {0, 3, 3, 3},
    {1, 3, 4, 3},
    {2, 3, 5, 3},

    {3, 3, 6, 3},
    {4, 3, 7, 3},
    {5, 3, 8, 3},

    {6, 3, 5, 11},
    {7, 3, 4, 11},
    {8, 3, 3, 11},

    {3, 11, 2, 3},
    {4, 11, 1, 3},
    {5, 11, 0, 3},

    {3, 0, 3, 2},
    {3, 1, 4, 2},
    {3, 2, 5, 2},
    {4, 0, 3, 1},
    {4, 2, 5, 1},
    {5, 0, 3, 0},
    {5, 1, 4, 0},
    {5, 2, 5, 0}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void F(int c[9][12]) {
    // Add to combination
    addToCombination(motorIdByFunction('F'), 0);

    // Transform cube
  int map[20][4] = {
    {5, 0, 5, 9},
    {5, 1, 5, 10},
    {5, 2, 5, 11},

    {5, 3, 5, 0},
    {5, 4, 5, 1},
    {5, 5, 5, 2},

    {5, 6, 5, 3},
    {5, 7, 5, 4},
    {5, 8, 5, 5},

    {5, 9, 5, 6},
    {5, 10, 5, 7},
    {5, 11, 5, 8},

    {6, 3, 8, 3},
    {6, 4, 7, 3},
    {6, 5, 6, 3},
    {7, 3, 8, 4},
    {7, 5, 6, 4},
    {8, 3, 8, 5},
    {8, 4, 7, 5},
    {8, 5, 6, 5}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void Fc(int c[9][12]) {
    // Add to combination
    addToCombination(motorIdByFunction('F'), 1);

    // Transform cube
  int map[20][4] = {
    {5, 0, 5, 3},
    {5, 1, 5, 4},
    {5, 2, 5, 5},

    {5, 3, 5, 6},
    {5, 4, 5, 7},
    {5, 5, 5, 8},

    {5, 6, 5, 9},
    {5, 7, 5, 10},
    {5, 8, 5, 11},

    {5, 9, 5, 0},
    {5, 10, 5, 1},
    {5, 11, 5, 2},

    {6, 3, 6, 5},
    {6, 4, 7, 5},
    {6, 5, 8, 5},
    {7, 3, 6, 4},
    {7, 5, 8, 4},
    {8, 3, 6, 3},
    {8, 4, 7, 3},
    {8, 5, 8, 3}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void R(int c[9][12]) {
    // Add to combination
    addToCombination(motorIdByFunction('R'), 0);

    // Transform cube
  int map[20][4] = {
    {6, 5, 5, 9},
    {7, 5, 4, 9},
    {8, 5, 3, 9},

    {3, 9, 2, 5},
    {4, 9, 1, 5},
    {5, 9, 0, 5},

    {0, 5, 3, 5},
    {1, 5, 4, 5},
    {2, 5, 5, 5},

    {3, 5, 6, 5},
    {4, 5, 7, 5},
    {5, 5, 8, 5},

    {3, 6, 5, 6},
    {3, 7, 4, 6},
    {3, 8, 3, 6},
    {4, 6, 5, 7},
    {4, 8, 3, 7},
    {5, 6, 5, 8},
    {5, 7, 4, 8},
    {5, 8, 3, 8}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void Rc(int c[9][12]) {
    // Add to combination
    addToCombination(motorIdByFunction('R'), 1);

    // Transform cube
  int map[20][4] = {
    {0, 5, 5, 9},
    {1, 5, 4, 9},
    {2, 5, 3, 9},

    {3, 9, 8, 5},
    {4, 9, 7, 5},
    {5, 9, 6, 5},

    {6, 5, 3, 5},
    {7, 5, 4, 5},
    {8, 5, 5, 5},

    {3, 5, 0, 5},
    {4, 5, 1, 5},
    {5, 5, 2, 5},

    {3, 6, 3, 8},
    {3, 7, 4, 8},
    {3, 8, 5, 8},
    {4, 6, 3, 7},
    {4, 8, 5, 7},
    {5, 6, 3, 6},
    {5, 7, 4, 6},
    {5, 8, 5, 6}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void B(int c[9][12]) {
    // Add to combination
    addToCombination(motorIdByFunction('B'), 0);

    // Transform cube
  int map[20][4] = {
    {3, 0, 3, 3},
    {3, 1, 3, 4},
    {3, 2, 3, 5},

    {3, 3, 3, 6},
    {3, 4, 3, 7},
    {3, 5, 3, 8},

    {3, 6, 3, 9},
    {3, 7, 3, 10},
    {3, 8, 3, 11},

    {3, 9, 3, 0},
    {3, 10, 3, 1},
    {3, 11, 3, 2},

    {0, 3, 2, 3},
    {0, 4, 1, 3},
    {0, 5, 0, 3},
    {1, 3, 2, 4},
    {1, 5, 0, 4},
    {2, 3, 2, 5},
    {2, 4, 1, 5},
    {2, 5, 0, 5}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void Bc(int c[9][12]) {
    // Add to combination
    addToCombination(motorIdByFunction('B'), 1);

    // Transform cube
  int map[20][4] = {
    {3, 0, 3, 9},
    {3, 1, 3, 10},
    {3, 2, 3, 11},

    {3, 3, 3, 0},
    {3, 4, 3, 1},
    {3, 5, 3, 2},

    {3, 6, 3, 3},
    {3, 7, 3, 4},
    {3, 8, 3, 5},

    {3, 9, 3, 6},
    {3, 10, 3, 7},
    {3, 11, 3, 8},

    {0, 3, 0, 5},
    {0, 4, 1, 5},
    {0, 5, 2, 5},
    {1, 3, 0, 4},
    {1, 5, 2, 4},
    {2, 3, 0, 3},
    {2, 4, 1, 3},
    {2, 5, 2, 3}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void D(int c[9][12]) {
    // Add to combination
    addToCombination(motorIdByFunction('D'), 0);

    // Transform cube
  int map[20][4] = {
    {3, 2, 6, 3},
    {4, 2, 6, 4},
    {5, 2, 6, 5},

    {2, 3, 5, 2},
    {2, 4, 4, 2},
    {2, 5, 3, 2},

    {3, 6, 2, 3},
    {4, 6, 2, 4},
    {5, 6, 2, 5},

    {6, 3, 5, 6},
    {6, 4, 4, 6},
    {6, 5, 3, 6},

    {3, 3, 5, 3},
    {3, 4, 4, 3},
    {3, 5, 3, 3},
    {4, 3, 5, 4},
    {4, 5, 3, 4},
    {5, 3, 5, 5},
    {5, 4, 4, 5},
    {5, 5, 3, 5}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void Dc(int c[9][12]) {
    // Add to combination
    addToCombination(motorIdByFunction('D'), 1);

    // Transform cube
  int map[20][4] = {
    {3, 2, 2, 5},
    {4, 2, 2, 4},
    {5, 2, 2, 3},

    {2, 3, 3, 6},
    {2, 4, 4, 6},
    {2, 5, 5, 6},

    {3, 6, 6, 5},
    {4, 6, 6, 4},
    {5, 6, 6, 3},

    {6, 3, 3, 2},
    {6, 4, 4, 2},
    {6, 5, 5, 2},

    {3, 3, 3, 5},
    {3, 4, 4, 5},
    {3, 5, 5, 5},
    {4, 3, 3, 4},
    {4, 5, 5, 4},
    {5, 3, 3, 3},
    {5, 4, 4, 3},
    {5, 5, 5, 3}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<20; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }
}

void Y(int c[9][12]) {
    // DEBUG ONLY
    // Add to combination
    addToCombination(9, 0);

  int map[54][4] = {
    {0, 3, 3, 8},
    {0, 4, 4, 8},
    {0, 5, 5, 8},
    {1, 3, 3, 7},
    {1, 4, 4, 7},
    {1, 5, 5, 7},
    {2, 3, 3, 6},
    {2, 4, 4, 6},
    {2, 5, 5, 6},

    {3, 0, 0, 5},
    {3, 1, 1, 5},
    {3, 2, 2, 5},
    {4, 0, 0, 4},
    {4, 1, 1, 4},
    {4, 2, 2, 4},
    {5, 0, 0, 3},
    {5, 1, 1, 3},
    {5, 2, 2, 3},

    {3, 3, 3, 5},
    {3, 4, 4, 5},
    {3, 5, 5, 5},
    {4, 3, 3, 4},
    {4, 4, 4, 4},
    {4, 5, 5, 4},
    {5, 3, 3, 3},
    {5, 4, 4, 3},
    {5, 5, 5, 3},

    {3, 6, 6, 5},
    {3, 7, 7, 5},
    {3, 8, 8, 5},
    {4, 6, 6, 4},
    {4, 7, 7, 4},
    {4, 8, 8, 4},
    {5, 6, 6, 3},
    {5, 7, 7, 3},
    {5, 8, 8, 3},

    {3, 9, 5, 9},
    {3, 10, 4, 9},
    {3, 11, 3, 9},
    {4, 9, 5, 10},
    {4, 10, 4, 10},
    {4, 11, 3, 10},
    {5, 9, 5, 11},
    {5, 10, 4, 11},
    {5, 11, 3, 11},

    {6, 3, 3, 2},
    {6, 4, 4, 2},
    {6, 5, 5, 2},
    {7, 3, 3, 1},
    {7, 4, 4, 1},
    {7, 5, 5, 1},
    {8, 3, 3, 0},
    {8, 4, 4, 0},
    {8, 5, 5, 0}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<54; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }

  // Map motor ids
  struct carterStateStruct bufferState = {
                                     carterState.F,
                                     carterState.B,
                                     carterState.R,
                                     carterState.L,
                                     carterState.U,
                                     carterState.D
  };
  carterState.F = bufferState.R;
  carterState.R = bufferState.B;
  carterState.B = bufferState.L;
  carterState.L = bufferState.F;
}

void Yc(int c[9][12]) {
    // DEBUG ONLY
    // Add to combination
    addToCombination(9, 1);

  int map[54][4] = {
    {0, 3, 5, 0},
    {0, 4, 4, 0},
    {0, 5, 3, 0},
    {1, 3, 5, 1},
    {1, 4, 4, 1},
    {1, 5, 3, 1},
    {2, 3, 5, 2},
    {2, 4, 4, 2},
    {2, 5, 3, 2},

    {3, 0, 8, 3},
    {3, 1, 7, 3},
    {3, 2, 6, 3},
    {4, 0, 8, 4},
    {4, 1, 7, 4},
    {4, 2, 6, 4},
    {5, 0, 8, 5},
    {5, 1, 7, 5},
    {5, 2, 6, 5},

    {3, 3, 5, 3},
    {3, 4, 4, 3},
    {3, 5, 3, 3},
    {4, 3, 5, 4},
    {4, 4, 4, 4},
    {4, 5, 3, 4},
    {5, 3, 5, 5},
    {5, 4, 4, 5},
    {5, 5, 3, 5},

    {3, 6, 2, 3},
    {3, 7, 1, 3},
    {3, 8, 0, 3},
    {4, 6, 2, 4},
    {4, 7, 1, 4},
    {4, 8, 0, 4},
    {5, 6, 2, 5},
    {5, 7, 1, 5},
    {5, 8, 0, 5},

    {3, 9, 3, 11},
    {3, 10, 4, 11},
    {3, 11, 5, 11},
    {4, 9, 3, 10},
    {4, 10, 4, 10},
    {4, 11, 5, 10},
    {5, 9, 3, 9},
    {5, 10, 4, 9},
    {5, 11, 5, 9},

    {6, 3, 5, 6},
    {6, 4, 4, 6},
    {6, 5, 3, 6},
    {7, 3, 5, 7},
    {7, 4, 4, 7},
    {7, 5, 3, 7},
    {8, 3, 5, 8},
    {8, 4, 4, 8},
    {8, 5, 3, 8}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<54; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }

  // Map motor ids
  struct carterStateStruct bufferState = {
                                     carterState.F,
                                     carterState.B,
                                     carterState.R,
                                     carterState.L,
                                     carterState.U,
                                     carterState.D
  };
  carterState.F = bufferState.L;
  carterState.R = bufferState.F;
  carterState.B = bufferState.R;
  carterState.L = bufferState.B;
}

void X(int c[9][12]) {
  int map[54][4] = {
    {0, 3, 3, 3},
    {0, 4, 3, 4},
    {0, 5, 3, 5},
    {1, 3, 4, 3},
    {1, 4, 4, 4},
    {1, 5, 4, 5},
    {2, 3, 5, 3},
    {2, 4, 5, 4},
    {2, 5, 5, 5},

    {3, 0, 3, 2},
    {3, 1, 4, 2},
    {3, 2, 5, 2},
    {4, 0, 3, 1},
    {4, 1, 4, 1},
    {4, 2, 5, 1},
    {5, 0, 3, 0},
    {5, 1, 4, 0},
    {5, 2, 5, 0},

    {3, 3, 6, 3},
    {3, 4, 6, 4},
    {3, 5, 6, 5},
    {4, 3, 7, 3},
    {4, 4, 7, 4},
    {4, 5, 7, 5},
    {5, 3, 8, 3},
    {5, 4, 8, 4},
    {5, 5, 8, 5},

    {3, 6, 5, 6},
    {3, 7, 4, 6},
    {3, 8, 3, 6},
    {4, 6, 5, 7},
    {4, 7, 4, 7},
    {4, 8, 3, 7},
    {5, 6, 5, 8},
    {5, 7, 4, 8},
    {5, 8, 3, 8},

    {3, 9, 2, 5},
    {3, 10, 2, 4},
    {3, 11, 2, 3},
    {4, 9, 1, 5},
    {4, 10, 1, 4},
    {4, 11, 1, 3},
    {5, 9, 0, 5},
    {5, 10, 0, 4},
    {5, 11, 0, 3},

    {6, 3, 5, 11},
    {6, 4, 5, 10},
    {6, 5, 5, 9},
    {7, 3, 4, 11},
    {7, 4, 4, 10},
    {7, 5, 4, 9},
    {8, 3, 3, 11},
    {8, 4, 3, 10},
    {8, 5, 3, 9}
  };
  int i, j;
  int buffer[9][12];
  for (i=0; i<9; i++) {
    for (j=0; j<12; j++) {
      buffer[i][j] = c[i][j];
    }
  }
  for (i=0; i<54; i++) {
    c[map[i][2]][map[i][3]] = buffer[map[i][0]][map[i][1]];
  }

  // Map motor ids
  struct carterStateStruct bufferState = {
                                     carterState.F,
                                     carterState.B,
                                     carterState.R,
                                     carterState.L,
                                     carterState.U,
                                     carterState.D
  };
  carterState.F = bufferState.D;
  carterState.U = bufferState.F;
  carterState.B = bufferState.U;
  carterState.D = bufferState.B;
}
