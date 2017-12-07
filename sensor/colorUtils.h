#define ORANGE 0
#define WHITE 1
#define GREEN 2
#define BLUE 3
#define RED 4
#define YELLOW 5

/*
 * Defined by tests
 * With: gain = 0, integration time 0xC0
 * Distance between sensor and color: 5 mm
 * Average over 10 points
 */
#define ORANGE_AVE_R 140.5//168.8
#define ORANGE_AVE_G 64.8//44.6
#define ORANGE_AVE_B 48.6//40.7
#define WHITE_AVE_R 96.0//83.8
#define WHITE_AVE_G 96.0//90.0
#define WHITE_AVE_B 61.9//80.2
#define GREEN_AVE_R 76.2//51.9
#define GREEN_AVE_G 118.5//136.1
#define GREEN_AVE_B 59.3//65.9
#define BLUE_AVE_R 78.1//35.4
#define BLUE_AVE_G 97.7//90.4
#define BLUE_AVE_B 78.1//128.2
#define RED_AVE_R 121.5//162.8
#define RED_AVE_G 77.3//46.0
#define RED_AVE_B 55.2//45.4
#define YELLOW_AVE_R 100.3//95.8
#define YELLOW_AVE_G 104.8//110.4
#define YELLOW_AVE_B 47.6//47.8

int colorFromRaw (float r, float g, float b);
char * colorTextFromColorInt (int colorInt);
