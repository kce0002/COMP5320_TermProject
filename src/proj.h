#ifndef PROJ_H
#define PROJ_H

// Constants:
#define BUFFER_SIZE 10
#define NUM_PACKETS 10000

// Type definitions:
typedef enum {false, true} bool;
typedef struct {
	bool inBuff;
	bool inServer;
} PacketInfo;

// Function prototypes:
bool isFull(PacketInfo *buff);
void bufferInit(PacketInfo *buff1, PacketInfo *buff2);
void packetInit(PacketInfo *packets);
void printInfo(PacketInfo *buff1, PacketInfo *buff2);
int genRandom();

#endif
