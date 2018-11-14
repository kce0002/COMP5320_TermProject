#ifndef PROJ_H
#define PROJ_H

// Constants:
#define BUFFER_SIZE 10

// Type definitions:
typedef enum {false, true} bool;
typedef struct {
	bool inBuff;
	bool inServer;
	int priority;
} PacketInfo;

// Function prototypes:
bool isFull(PacketInfo *buff);
void bufferInit(PacketInfo *buff1, PacketInfo *buff2);
void printInfo(PacketInfo *buff1, PacketInfo *buff2);
int genRandom();

#endif
