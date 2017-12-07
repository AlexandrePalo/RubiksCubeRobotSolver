#include "driverlib.h"

// ----------- STRUCT DEFINITION -----------
typedef struct carterStateStruct carterStateStruct;
typedef struct motorState motorState;

struct carterStateStruct {
                      int F;
                      int B;
                      int R;
                      int L;
                      int U;
                      int D;
};
struct motorStateStruct {
                     uint16_t enable_port;
                     uint16_t enable_pin;
                     int id;
};

// ----------- GLOBAL VARIABLES -----------
extern struct carterStateStruct carterState;
extern struct motorStateStruct stpr1;
extern struct motorStateStruct stpr2;
extern struct motorStateStruct stpr3;
extern struct motorStateStruct stpr4;
extern struct motorStateStruct stpr5;
extern struct motorStateStruct stpr6;

extern int stepCounter;

struct motorStateStruct motorById(int id);
int motorIdByFunction(char function);
struct motorStateStruct motorByFunction(char function);
char functionByIdAndState(int motorId, struct carterStateStruct carterStruct);
