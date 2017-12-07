#include <math.h>
#include <stdio.h>
#include "colorUtils.h"

float aveRGB[6][3] = {
                      {ORANGE_AVE_R, ORANGE_AVE_G, ORANGE_AVE_B},
                      {WHITE_AVE_R, WHITE_AVE_G, WHITE_AVE_B},
                      {GREEN_AVE_R, GREEN_AVE_G, GREEN_AVE_B},
                      {BLUE_AVE_R, BLUE_AVE_G, BLUE_AVE_B},
                      {RED_AVE_R, RED_AVE_G, RED_AVE_B},
                      {YELLOW_AVE_R, YELLOW_AVE_G, YELLOW_AVE_B}
};

int colorFromRaw (float r, float g, float b) {
    // Calculate the distance in the 3D space R-G-B
    // Get the minimal distance
    // Return the color value corresponding
    float distances3DRGB[6] = {};
    int i;
    int min = 0;

    for (i=0; i<6; i++) {
        distances3DRGB[i] = sqrt((r-aveRGB[i][0])*(r-aveRGB[i][0]) + (g-aveRGB[i][1])*(g-aveRGB[i][1]) + (b-aveRGB[i][2])*(b-aveRGB[i][2]));
        if (i != 0) {
            if (distances3DRGB[i] < distances3DRGB[min]) {
                min = i;
            }
        }
    }

    return min;
}

char * colorTextFromColorInt (int colorInt) {
    switch (colorInt) {
        case ORANGE:
            return "orange";
        case WHITE:
            return "white";
        case GREEN:
            return "green";
        case BLUE:
            return "blue";
        case RED:
            return "red";
        case YELLOW:
            return "yellow";
        default:
            return "undefined";
    }
}
