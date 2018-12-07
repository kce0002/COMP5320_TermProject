#ifndef PROJ_H
#define PROJ_H

// Constants:
#define BUFFER_SIZE 10
#define NUM_PACKETS 10000

// Type definitions:
typedef enum {false, true} bool;

// Function prototypes:
bool isFull(bool *buff);
void bufferInit(bool *buff1, bool *buff2);
void packetInit(bool *packets);
int lastOpen(bool *buff);
int genRandom();
void randomAssign(bool *packets, bool *buff1, bool *buff2);
int smallerBuff(bool *buff1, bool *buff2);
void minQAssign(bool *packets, bool *buff1, bool *buff2);
void prompt(int lambda, int mu);
void removePackets(int mu, bool *buff);
void shift(bool *buff);

#endif