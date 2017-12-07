#include "configState.h"

void realF();
void realFc();
void realR();
void realRc();
void realL();
void realLc();
void realB();
void realBc();
void realU();
void realUc();
void realD();
void realDc();

void rotateMotor(struct motorStateStruct motor, int dir, int steps);
void rotate90Dir(struct motorStateStruct motor, int dir);
void rotate90CW(struct motorStateStruct motor);
void rotate90CCW(struct motorStateStruct motor);
