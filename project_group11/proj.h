#ifndef PROJ_H
#define PROJ_H

// Constants:
#define BUFFER_SIZE 10
#define NUM_PACKETS 10000

#include <sys/time.h>

// Type definitions:
typedef enum {false, true} bool;
typedef struct {
    bool inQ;
    struct timeval entryTime;
    //time_t entryTime;
} packet;

// Function prototypes:
bool isFull(packet *buff);
void bufferInit(packet *buff1, packet *buff2);
int lastOpen(packet *buff);
int genRandom();
void randomAssign(packet *buff1, packet *buff2);
int smallerBuff(packet *buff1, packet *buff2);
void minQAssign(packet *buff1, packet *buff2);
void prompt(int *lambda, int *mu);
void servicePackets(int mu, packet *buff);
void shift(packet *buff);
int qLength(packet *buff);

#endif