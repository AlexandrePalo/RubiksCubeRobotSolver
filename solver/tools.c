void printfCube(int cube[9][12]) {
    int i, j;
    printf("------------\n");
    for (i=0; i<9; i++) {
        for (j=0; j<12; j++) {
            printf("|%d|", cube[i][j]);
        }
        printf("\n");
    }
}