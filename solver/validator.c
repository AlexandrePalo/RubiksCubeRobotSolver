#include "./sensor/colorUtils.h"

// DO NOT DECLARE THEM GLOBALLY BECAUSE CONFLIC WITH R IN DRIVERLIB
#define O ORANGE
#define W WHITE
#define G GREEN
#define B BLUE
#define R RED
#define Y YELLOW

int validatorColor(int c[9][12], int color) {
    int nbAp = 0;
    int i, j;
    for (i=0; i<9; i++) {
        for(j=0; j<12; j++) {
            if (c[i][j] == color) {
                nbAp ++;
            }
        }
    }
    if (nbAp == 9) {
        return 1;
    } else {
        return 0;
    }
}

int validatorEdges(int cube[9][12]) {
    /*
     * There are 12 edges listed in:
     * (W, R), (W, G), (W, B), (W, O)
     * (Y, R), (Y, G), (Y, B), (Y, O)
     * (G, R), (G, O), (B, R), (B, O)
     */
    int countEdges = 0;
    int edges[12][2] = {
                        {W, R}, {W, G}, {W, B}, {W, O},
                        {Y, R}, {Y, G}, {Y, B}, {Y, O},
                        {G, R}, {G, O}, {B, R}, {B, O}
    };
    int edgesCube[12][4] = {
                            {0, 4, 3, 10}, {1, 3, 3, 1}, {1, 5, 3, 7}, {2, 4, 3, 4},
                            {6, 4, 5, 4}, {7, 3, 5, 1}, {7, 5, 5, 7}, {8, 4, 5, 10},
                            {4, 0, 4, 11}, {4, 2, 4, 3}, {4, 5, 4, 6}, {4, 8, 4, 9}
    };

    // Check if all edges in edgesCube are only once in edges
    // Better to do it by checking in edges and not edgesCube
    int i, j;
    for (i=0; i<12; i++) {
        for (j=0; j<12; j++) {
            if (((edges[i][0] == cube[edgesCube[j][0]][edgesCube[j][1]])
                  && (edges[i][1] == cube[edgesCube[j][2]][edgesCube[j][3]])) ||
                 ((edges[i][0] == cube[edgesCube[j][2]][edgesCube[j][3]])
                  && (edges[i][1] == cube[edgesCube[j][0]][edgesCube[j][1]]))) {
                countEdges ++;
                break;
            }
        }
    }

    // Ok if countEdges = 12
    if (countEdges == 12) {
        return 1;
    } else {
        return 0;
    }
}

int validatorCorners(int cube[9][12]) {
    /*
     * There are 8 corners listed in:
     * (W, R, G), (W, R, B), (W, O, G), (W, O, B)
     * (Y, R, G), (Y, R, B), (Y, O, G), (Y, O, B)
     */
    int countCorners = 0;
    int corners[8][3] = {
                        {W, R, G}, {W, R, B}, {W, O, G}, {W, O, B},
                        {Y, R, G}, {Y, R, B}, {Y, O, G}, {Y, O, B}
    };
    int cornersCube[8][6] = {
                            {0, 3, 3, 0, 3, 11}, {0, 5, 3, 8, 3, 9}, {2, 3, 3, 2, 3, 3}, {2, 5, 3, 5, 3, 6},
                            {5, 0, 8, 3, 5, 11}, {8, 5, 5, 8, 5, 9}, {5, 2, 5, 3, 6, 3}, {5, 5, 5, 6, 6, 5}
    };

    // Check if all edges in edgesCube are only once in edges
    // Better to do it by checking in edges and not edgesCube
    int i, j;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            if (((corners[i][0] == cube[cornersCube[j][0]][cornersCube[j][1]])
                  && (corners[i][1] == cube[cornersCube[j][2]][cornersCube[j][3]])
                  && (corners[i][2] == cube[cornersCube[j][4]][cornersCube[j][5]])) ||
                 ((corners[i][0] == cube[cornersCube[j][0]][cornersCube[j][1]])
                  && (corners[i][1] == cube[cornersCube[j][4]][cornersCube[j][5]])
                  && (corners[i][2] == cube[cornersCube[j][2]][cornersCube[j][3]])) ||
                 ((corners[i][0] == cube[cornersCube[j][4]][cornersCube[j][5]])
                  && (corners[i][1] == cube[cornersCube[j][2]][cornersCube[j][3]])
                  && (corners[i][2] == cube[cornersCube[j][0]][cornersCube[j][1]])) ||
                 ((corners[i][0] == cube[cornersCube[j][2]][cornersCube[j][3]])
                  && (corners[i][1] == cube[cornersCube[j][0]][cornersCube[j][1]])
                  && (corners[i][2] == cube[cornersCube[j][4]][cornersCube[j][5]])) ||
                 ((corners[i][0] == cube[cornersCube[j][4]][cornersCube[j][5]])
                  && (corners[i][1] == cube[cornersCube[j][0]][cornersCube[j][1]])
                  && (corners[i][2] == cube[cornersCube[j][2]][cornersCube[j][3]])) ||
                 ((corners[i][0] == cube[cornersCube[j][2]][cornersCube[j][3]])
                  && (corners[i][1] == cube[cornersCube[j][4]][cornersCube[j][5]])
                  && (corners[i][2] == cube[cornersCube[j][0]][cornersCube[j][1]]))) {
                countCorners ++;
                break;
            }
        }
    }

    // Ok if countCorners = 8
    if (countCorners == 8) {
        return 1;
    } else {
        return 0;
    }
}

int validatorAllColor(int c[9][12]) {
    if ((validatorColor(c, RED) == 1) &&
        (validatorColor(c, GREEN) == 1) &&
        (validatorColor(c, YELLOW) == 1) &&
        (validatorColor(c, BLUE) == 1) &&
        (validatorColor(c, ORANGE) == 1) &&
        (validatorColor(c, WHITE) == 1)) {
        return 1;
    } else {
        return 0;
    }
}

int validatorCube(int c[9][12]) {
    /*
     * Check if the cube is valid.
     * Be careful, this function only check if corners, edges and colors are valid.
     * Another condition around position of edges and corners is needed, but cannot be easily implemented.
     * Thus, if this function is false the cube is not solvable. If it's true, it "could" be solvable.
     */
    if ((validatorAllColor(c) == 1) && (validatorEdges(c) == 1) && (validatorCorners(c) == 1)) {
        return 1;
    } else {
        return 0;
    }
}
