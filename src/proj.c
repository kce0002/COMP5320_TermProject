#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <proj.h>

// Global variables:
int lostPackets = 0;
int avgQLength = 0;
long avgWaitTime = 0;
long totalWaitTime = 0;
int arrivalRate = 1;
int serviceRate = 1;

int main() {
	prompt(&arrivalRate, &serviceRate);

	packet buff1[BUFFER_SIZE];
	packet buff2[BUFFER_SIZE];

	bufferInit(buff1, buff2);

	minQAssign(buff1, buff2);

	lostPackets = 0;
	avgQLength = 0;
	bufferInit(buff1, buff2);

	randomAssign(buff1, buff2);

	return 0;
}

bool isFull(packet *buff) {
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		if (!buff[i].inQ) {
			return false;
		}
	}
	return true;
}

void bufferInit(packet *buff1, packet *buff2) {
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		buff1[i].inQ = false;
		buff1[i].entryTime = 0;
		buff2[i].inQ = false;
		buff2[i].entryTime = 0;
	}
}

int genRandom() {
	return rand() % 2;
}

void randomAssign(packet *buff1, packet *buff2) {
	int qLen = 0;
	int sent = 0;
	int i;
	while (sent < NUM_PACKETS) {
		for (i = 0; i < arrivalRate; i++) {
			int selection = genRandom();
			if (selection) {
				qLen += qLength(buff1);
				if (isFull(buff1)) {
					lostPackets++;
				}
				else {
					buff1[lastOpen(buff1)].inQ = true;
				}
			}
			else {
				qLen += qLength(buff2);
				if (isFull(buff2)) {
					lostPackets++;
				}
				else {
					buff2[lastOpen(buff2)].inQ = true;
				}
			}
			sent++;
			//printf("\nSENT: %d\n", sent);
			if (sent > NUM_PACKETS) {
				break;
			}
		}
		servicePackets(serviceRate, buff1);
		servicePackets(serviceRate, buff2);	
		
	}
	printf("\nLost packets: %d\n", lostPackets);
	avgQLength = qLen / NUM_PACKETS;
	printf("\nAvg Q Len: %d\n", avgQLength);
}

int lastOpen(packet *buff) {
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		if (buff[i].inQ) {
			return i - 1;
		}
	}
	return 9;
}

int smallerBuff(packet *buff1, packet *buff2) {
	int a = 0;
	int b = 0;
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		if (buff1[i].inQ) {
			a++;
		}
		if (buff2[i].inQ) {
			b++;
		}
	}
	if (a < b) {
		return 1;
	}
	else {
		return 0;
	}
}


void minQAssign(packet *buff1, packet *buff2) {
	int qLen = 0;
	int sent = 0;
	int i;
	while (sent < NUM_PACKETS) {
		for (i = 0; i < arrivalRate; i++) {
			int selection = smallerBuff(buff1, buff2);
			if (selection) {
				qLen += qLength(buff1);
				if (isFull(buff1)) {
					lostPackets++;
				}
				else {
					buff1[lastOpen(buff1)].inQ = true;
				}
			}
			else {
				qLen += qLength(buff2);
				if (isFull(buff2)) {
					lostPackets++;
				}
				else {
					buff2[lastOpen(buff2)].inQ = true;
				}
			}
			sent++;
			//printf("\nSENT: %d\n", sent);
			if (sent >= NUM_PACKETS) {
				break;
			}
		}
		servicePackets(serviceRate, buff1);
		servicePackets(serviceRate, buff2);	
		
	}
	printf("\nLost packets: %d\n", lostPackets);
	avgQLength = qLen / NUM_PACKETS;
	printf("\nAvg Q Len: %d\n", avgQLength);
}

void prompt(int *lambda, int *mu) {
	printf("\nEnter arrival rate: ");
	scanf("%d", lambda);
	printf("\nEnter service rate: ");
	scanf("%d", mu);
	
}

void servicePackets(int mu, packet *buff) {
	int i;
	for (i = 0; i < mu; i++) {
		shift(buff);
	}
}

void shift(packet *buff) {
	int i;
	//bool temp = buff[BUFFER_SIZE - 1];
	for (i = BUFFER_SIZE - 1; i > 0; i--) {
		buff[i] = buff[i - 1];
	}
	buff[0].inQ = false;
	buff[0].entryTime = 0;
}

int qLength(packet *buff) {
	int i;
	int length = 0;
	for (i = 0; i < BUFFER_SIZE; i++) {
		if (buff[i].inQ) {
			length++;
		}
	}
	return length;
}