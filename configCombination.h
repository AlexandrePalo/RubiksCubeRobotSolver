// ----------- GLOBAL COMBINATION VARIABLES -----------
extern int combination[300][2]; // combinations saved
extern int index; // for each combination
extern int mixingMode; // 1 if mixingMode enabled
extern int detectionMode; // 1 if detectionMode enabled

// ----------- COMBINATION FUNCTIONS -----------
void addToCombination(int motorId, int dir);
void readCombination();
void resetCombination();

// ----------- DEBUGGING ONLY -----------------
void humanReadCombination();
