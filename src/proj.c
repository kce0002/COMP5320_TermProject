#include <stdio.h>
#include <stdlib.h>
#include <proj.h>


int main() {
	PacketInfo buff1[BUFFER_SIZE];
	PacketInfo buff2[BUFFER_SIZE];
	bufferInit(buff1, buff2);
	printInfo(buff1, buff2);
	return 0;
}

bool isFull(PacketInfo *buff) {
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		if (!buff[i].inBuff && !buff[i].inServer) {
			return false;
		}
	}
	return true;
}

void bufferInit(PacketInfo *buff1, PacketInfo *buff2) {
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		buff1[i].inBuff = false;
		buff1[i].inServer = false;
		buff1[i].priority = 0;
		buff2[i].inBuff = false;
		buff2[i].inServer = false;
		buff2[i].priority = 0;
	}
}

void printInfo(PacketInfo *buff1, PacketInfo *buff2) {
	int i;
	printf("\nBuffer 1:\n");
	for (i = 0; i < BUFFER_SIZE; i++) {
		printf("%d - inBuff: %d, inServer: %d, priority: %d\n", i, buff1[i].inBuff, buff1[i].inServer, buff1[i].priority);	
	}
	printf("isFull: %d\n", isFull(buff1));
	printf("\nBuffer 2:\n");
	for (i = 0; i < BUFFER_SIZE; i++) {
		printf("%d - inBuff: %d, inServer: %d, priority: %d\n", i, buff2[i].inBuff, buff2[i].inServer, buff2[i].priority);	
	}
	printf("isFull: %d\n", isFull(buff2));
}
