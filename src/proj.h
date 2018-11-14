#ifndef PROJ_H
#define PROJ_H

#define BUFFER_SIZE 10

typedef enum {false, true} bool;
typedef struct {
	bool inUse;
	int priority;
} PacketInfo;

bool isFull(PacketInfo *buff);
void bufferInit(PacketInfo *buff1, PacketInfo *buff2);
void printInfo(PacketInfo *buff1, PacketInfo *buff2);
#endif
