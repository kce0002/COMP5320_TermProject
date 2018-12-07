#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <proj.h>

// Global variables:
int lostPackets = 0;
int avgQLength = 0;

int main() {
	int arrivalRate;
	int serviceRate;
	prompt(arrivalRate, serviceRate);

	bool buff1[BUFFER_SIZE];
	bool buff2[BUFFER_SIZE];
	bool packets[NUM_PACKETS];
	packetInit(packets);
	bufferInit(buff1, buff2);
	minQAssign(packets, buff1, buff2);
	lostPackets = 0;
	bufferInit(buff1, buff2);
	randomAssign(packets, buff1, buff2);
	return 0;
}

bool isFull(bool *buff) {
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		if (!buff[i]) {
			return false;
		}
	}
	return true;
}

void bufferInit(bool *buff1, bool *buff2) {
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		buff1[i] = false;
		buff2[i] = false;
	}
}

int genRandom() {
	return rand() % 2;
}

void packetInit(bool *packets) {
	int i;
	for (i = 0; i < NUM_PACKETS; i++) {
		packets[i] = true;
	}
}

void randomAssign(bool *packets, bool *buff1, bool *buff2) {
	int i;
	for (i = 0; i < NUM_PACKETS; i++) {	
		int selection = genRandom();
		if (selection) {
			// Buffer 1
			if (isFull(buff1)) {
				lostPackets++;
			}
			else {
				// put packet in last opening in buffer:
				int a = lastOpen(buff1);
				buff1[a] = packets[i];
			}
		}
		else {
			// Buffer 2
			if (isFull(buff2)) {
				lostPackets++;
			}
			else {
				// put packet in last opening in buffer:
				int b = lastOpen(buff2);
				buff2[b] = packets[i];
			}
		}
	}
	printf("\nLost packets: %d", lostPackets);
}

int lastOpen(bool *buff) {
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		if (buff[i]) {
			return i - 1;
		}
	}
	return 9;
}

int smallerBuff(bool *buff1, bool *buff2) {
	int a = 0;
	int b = 0;
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		if (buff1[i]) {
			a++;
		}
		if (buff2[i]) {
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

void minQAssign(bool *packets, bool *buff1, bool *buff2) {
	int i;
	for (i = 0; i < NUM_PACKETS; i++) {
		int selection = smallerBuff(buff1, buff2);
		// buff1
		if (selection) {
			if (isFull(buff1)) {
				lostPackets++;
			}
			else {			
				buff1[lastOpen(buff1)] = packets[i];
			}
		}
		// buff2
		else {
			if (isFull(buff2)) {
				lostPackets++;
			}
			else {
				buff2[lastOpen(buff2)] = packets[i];
			}
		}
	}
	printf("Lost Packets: %d", lostPackets);
}

void prompt(int lambda, int mu) {
	printf("\nEnter arrival rate: ");
	scanf("%d", &lambda);
	printf("\nEnter service rate: ");
	scanf("%d", &mu);
}