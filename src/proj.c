#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <proj.h>

// Kyle Ehlers and Mitchell Derisio
// COMP 5320

// Global variables:
int lostPackets = 0;
int avgQLength = 0;
double avgWaitTime = 0;
long totalWaitTime = 0;
int arrivalRate = 1;
int serviceRate = 1;

struct timeval a;
struct timeval b;

int main() {
	//prompt(&arrivalRate, &serviceRate);


	packet buff1[BUFFER_SIZE];
	packet buff2[BUFFER_SIZE];
    
	bufferInit(buff1, buff2);

	/*gettimeofday(&a, NULL);
	minQAssign(buff1, buff2);
	gettimeofday(&b, NULL);*/
	//printf("\ntw: %ld", totalWaitTime);
	//avgWaitTime = totalWaitTime / ((long) 100 - (long) lostPackets);
	//printf("a: %ld\nb: %ld\n", a.tv_usec, b.tv_usec);
	//avgWaitTime = ((b.tv_sec * 1000000 + b.tv_usec) - (a.tv_sec * 1000000 + a.tv_usec)) / (NUM_PACKETS - lostPackets);
	/*avgWaitTime = (double) (b.tv_usec - a.tv_usec) / (double) (NUM_PACKETS - lostPackets);
	printf("\navg wait time: %6.5f", avgWaitTime);*/

	/*lostPackets = 0;
	avgQLength = 0;
	avgWaitTime = 0;
	totalWaitTime = 0;
	bufferInit(buff1, buff2);

	gettimeofday(&a, NULL);
	randomAssign(buff1, buff2);
	gettimeofday(&b, NULL);
	//avgWaitTime = totalWaitTime / (NUM_PACKETS - lostPackets);
	avgWaitTime = (double) (b.tv_usec - a.tv_usec) / (double) (NUM_PACKETS - lostPackets);
	printf("\navg wait time: %6.5f", avgWaitTime);
	//printf("a: %ld\nb: %ld\n", a.tv_usec, b.tv_usec);
     */

    
    printf("\nBlocking Probability:\n----------------------\n");
    double randbptotal = 0.0;
    double minbptotal = 0.0;
    lostPackets = 0;
    int z;
	int serviceRate = 2;
    //lambda
    printf("Lambda:\n");
    int y;
    for (y = 1; y < 11; y++) {
        printf("%d\t", y);
    }
    printf("\n");
    
	for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            randomAssign(buff1, buff2);
            randbptotal += lostPackets;
            lostPackets = 0;
        }
        randbptotal /= 10.0;
        randbptotal /= 10000.0;
        printf("%6.5f\t", randbptotal);
        bufferInit(buff1, buff2);
	}
    printf("\n");
    
    //randbptotal = 0.0;
    for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            minQAssign(buff1, buff2);
            minbptotal += lostPackets;
            lostPackets = 0;
        }
        minbptotal /= 10.0;
        minbptotal /= 10000.0;
        printf("%6.5f\t", minbptotal);
        bufferInit(buff1, buff2);
    }
    printf("\n\n");
    printf("Mu:\n");
    
    // mu
    arrivalRate = 4;
    randbptotal = 0.0;
    lostPackets = 0;
    for (y = 1; y < 11; y++) {
        printf("%d\t", y);
    }
    printf("\n");
    for (serviceRate = 1; serviceRate < 11; serviceRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            randomAssign(buff1, buff2);
            randbptotal += lostPackets;
            lostPackets = 0;
        }
        randbptotal /= 10.0;
        randbptotal /= 10000.0;
        printf("%6.5f\t", randbptotal);
        bufferInit(buff1, buff2);
    }
    printf("\n");
    lostPackets = 0;
    minbptotal = 0.0;
    for (serviceRate = 1; serviceRate < 11; serviceRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            minQAssign(buff1, buff2);
            minbptotal += lostPackets;
            lostPackets = 0;
        }
        minbptotal /= 10.0;
        minbptotal /= 10000.0;
        printf("%6.5f\t", minbptotal);
        bufferInit(buff1, buff2);
    }
    
    // rho:
    printf("\n\n");
    printf("Rho:\n");
    double d;
    for (d = 0.25; d <= 2.5; d += 0.25) {
        printf("%3.2f\t", d);
    }
    printf("\n");
    serviceRate = 2;
    randbptotal = 0.0;
    lostPackets = 0;
    for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            randomAssign(buff1, buff2);
            randbptotal += lostPackets;
            lostPackets = 0;
        }
        randbptotal /= 10.0;
        randbptotal /= 10000.0;
        printf("%6.5f\t", randbptotal);
        bufferInit(buff1, buff2);
    }
    printf("\n");
    lostPackets = 0;
    minbptotal = 0.0;
    for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            minQAssign(buff1, buff2);
            minbptotal += lostPackets;
            lostPackets = 0;
        }
        minbptotal /= 10.0;
        minbptotal /= 10000.0;
        printf("%6.5f\t", minbptotal);
        bufferInit(buff1, buff2);
    }
    printf("\n\n\n");
    





    // Queue Length Data:
    printf("\nQueue Length:\n----------------------\n");
    printf("Lambda:\n");
    for (y = 1; y < 11; y++) {
        printf("%d\t", y);
    }
    printf("\n");
    avgQLength = 0;
    int ranqltotal = 0;
    serviceRate = 2;
    for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            randomAssign(buff1, buff2);
            ranqltotal += avgQLength;
            avgQLength = 0;
        }
        ranqltotal /= 10;
        ranqltotal /= 10000;
        printf("%d\t", ranqltotal);
        bufferInit(buff1, buff2);
        avgQLength = 0;
    }
    printf("\n");
    int minqltotal = 0;
    serviceRate = 2;
    avgQLength = 0;
    for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            minQAssign(buff1, buff2);
            minqltotal += avgQLength;
            avgQLength = 0;
        }
        minqltotal /= 10;
        minqltotal /= 10000;
        printf("%d\t", minqltotal);
        bufferInit(buff1, buff2);
        avgQLength = 0;
    }
    printf("\n\nMu:\n");
    for (y = 1; y < 11; y++) {
        printf("%d\t", y);
    }
    printf("\n");
    avgQLength = 0;
    ranqltotal = 0;
    arrivalRate = 4;
    for (serviceRate = 1; serviceRate < 11; serviceRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            randomAssign(buff1, buff2);
            ranqltotal += avgQLength;
            avgQLength = 0;
        }
        ranqltotal /= 10;
        ranqltotal /= 10000;
        printf("%d\t", ranqltotal);
        bufferInit(buff1, buff2);
        avgQLength = 0;
    }
    printf("\n");
    minqltotal = 0;
    //serviceRate = 2;
    avgQLength = 0;
    for (serviceRate = 1; serviceRate < 11; serviceRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            minQAssign(buff1, buff2);
            minqltotal += avgQLength;
            avgQLength = 0;
        }
        minqltotal /= 10;
        minqltotal /= 10000;
        printf("%d\t", minqltotal);
        bufferInit(buff1, buff2);
        avgQLength = 0;
    }
    printf("\n\nRho:\n");
    for (d = 0.25; d <= 2.5; d += 0.25) {
        printf("%3.2f\t", d);
    }
    printf("\n");
    serviceRate = 2;
    avgQLength = 0;
    ranqltotal = 0;
    minqltotal = 0;
    for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            randomAssign(buff1, buff2);
            ranqltotal += avgQLength;
            avgQLength = 0;
        }
        ranqltotal /= 10;
        ranqltotal /= 10000;
        printf("%d\t", ranqltotal);
        bufferInit(buff1, buff2);
        avgQLength = 0;
    }
    printf("\n");
    serviceRate = 2;
    avgQLength = 0;
    for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            minQAssign(buff1, buff2);
            minqltotal += avgQLength;
            avgQLength = 0;
        }
        minqltotal /= 10;
        minqltotal /= 10000;
        printf("%d\t", minqltotal);
        bufferInit(buff1, buff2);
        avgQLength = 0;
    }
    
    
    printf("\n\n\n");
    printf("\nWaiting Time:\n----------------------\n");
    printf("Lambda:\n");
    for (y = 1; y < 11; y++) {
        printf("%d\t", y);
    }
    printf("\n");
    /*gettimeofday(&a, NULL);
    randomAssign(buff1, buff2);
    gettimeofday(&b, NULL);*/
    serviceRate = 2;
    double avgtime = 0.0;
    for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        lostPackets = 0;
        bufferInit(buff1, buff2);
        
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            gettimeofday(&a, NULL);
            randomAssign(buff1, buff2);
            gettimeofday(&b, NULL);
            avgtime += (double) (b.tv_usec - a.tv_usec);
        }
        
        avgtime /= 10.0;
        avgtime /= (100000.0 - (double) lostPackets);
        lostPackets = 0;
        printf("%4.3f\t", avgtime);
        avgtime = 0;
    }
    printf("\n");
    avgtime = 0.0;
    for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        lostPackets = 0;
        bufferInit(buff1, buff2);
        
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            gettimeofday(&a, NULL);
            minQAssign(buff1, buff2);
            gettimeofday(&b, NULL);
            avgtime += (double) (b.tv_usec - a.tv_usec);
        }
        
        avgtime /= 10.0;
        avgtime /= (100000.0 - (double) lostPackets);
        lostPackets = 0;
        printf("%4.3f\t", avgtime);
        avgtime = 0;
    }
    printf("\n\nMu:\n");
    for (y = 1; y < 11; y++) {
        printf("%d\t", y);
    }
    printf("\n");
    arrivalRate = 4;
    avgtime = 0.0;
    for (serviceRate = 1; serviceRate < 11; serviceRate++) {
        lostPackets = 0;
        bufferInit(buff1, buff2);
        
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            gettimeofday(&a, NULL);
            randomAssign(buff1, buff2);
            gettimeofday(&b, NULL);
            avgtime += (double) (b.tv_usec - a.tv_usec);
        }
        
        avgtime /= 10.0;
        avgtime /= (100000.0 - (double) lostPackets);
        lostPackets = 0;
        printf("%4.3f\t", avgtime);
        avgtime = 0;
    }
    printf("\n");
    avgtime = 0.0;
    for (serviceRate = 1; serviceRate < 11; serviceRate++) {
        lostPackets = 0;
        bufferInit(buff1, buff2);
        
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            gettimeofday(&a, NULL);
            minQAssign(buff1, buff2);
            gettimeofday(&b, NULL);
            avgtime += (double) (b.tv_usec - a.tv_usec);
        }
        
        avgtime /= 10.0;
        avgtime /= (100000.0 - (double) lostPackets);
        lostPackets = 0;
        printf("%4.3f\t", avgtime);
        avgtime = 0;
    }
    printf("\n\nRho:\n");
    for (d = 0.25; d <= 2.5; d += 0.25) {
        printf("%3.2f\t", d);
    }
    printf("\n");
    avgtime = 0;
    serviceRate = 2;
    for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        lostPackets = 0;
        bufferInit(buff1, buff2);
        
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            gettimeofday(&a, NULL);
            randomAssign(buff1, buff2);
            gettimeofday(&b, NULL);
            avgtime += (double) (b.tv_usec - a.tv_usec);
        }
        
        avgtime /= 10.0;
        avgtime /= (100000.0 - (double) lostPackets);
        lostPackets = 0;
        printf("%4.3f\t", avgtime);
        avgtime = 0;
    }
    printf("\n");
    avgtime = 0.0;
    for (arrivalRate = 1; arrivalRate < 11; arrivalRate++) {
        lostPackets = 0;
        bufferInit(buff1, buff2);
        
        for (z = 0; z < 10; z++) {
            bufferInit(buff1, buff2);
            gettimeofday(&a, NULL);
            minQAssign(buff1, buff2);
            gettimeofday(&b, NULL);
            avgtime += (double) (b.tv_usec - a.tv_usec);
        }
        
        avgtime /= 10.0;
        avgtime /= (100000.0 - (double) lostPackets);
        lostPackets = 0;
        printf("%4.3f\t", avgtime);
        avgtime = 0;
    }
    printf("\n");
    
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
		//buff1[i].entryTime.tv_usec = 0;
		buff2[i].inQ = false;
		//buff2[i].entryTime.tv_usec = 0;
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
					//struct timeval t;
					//gettimeofday(&buff1[lastOpen(buff1)].entryTime, NULL);
					//gettimeofday(&t, NULL);
					buff1[lastOpen(buff1)].inQ = true;
					//buff1[lastOpen(buff1)].entryTime.tv_usec = t.tv_usec;
					//buff1[lastOpen(buff1)].entryTime = t;
					//printf("\n\nENT TM: %ld", buff1[lastOpen(buff1)].entryTime.tv_usec);
				}
			}
			else {
				qLen += qLength(buff2);
				if (isFull(buff2)) {
					lostPackets++;
				}
				else {
					//struct timeval t;
					//gettimeofday(&buff2[lastOpen(buff2)].entryTime, NULL);
					//gettimeofday(&t, NULL);
					buff2[lastOpen(buff2)].inQ = true;
					//buff2[lastOpen(buff2)].entryTime.tv_usec = t.tv_usec;
					//buff2[lastOpen(buff2)].entryTime = t;
					//printf("\n\nENT TM: %ld", buff2[lastOpen(buff2)].entryTime.tv_usec);
				}
			}
			sent++;
			if (sent > NUM_PACKETS) {
				break;
			}
		}
		servicePackets(serviceRate, buff1);
		servicePackets(serviceRate, buff2);	
		
	}
	//printf("\nLost packets: %d\n", lostPackets);
	//avgQLength = qLen / NUM_PACKETS;
	//printf("\nAvg Q Len: %d\n", avgQLength);
    avgQLength = qLen;
    //printf("\nAQL: %d", avgQLength);
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
					//struct timeval t;
					//gettimeofday(&buff1[lastOpen(buff1)].entryTime, NULL);
					//gettimeofday(&t, NULL);
					buff1[lastOpen(buff1)].inQ = true;
					//buff1[lastOpen(buff1)].entryTime.tv_usec = t.tv_usec;
					//buff1[lastOpen(buff1)].entryTime = t;
					//printf("\n\nENT TM: %ld", buff1[lastOpen(buff1)].entryTime.tv_usec);
				}
			}
			else {
				qLen += qLength(buff2);
				if (isFull(buff2)) {
					lostPackets++;
				}
				else {
					//struct timeval t;
					//gettimeofday(&buff2[lastOpen(buff2)].entryTime, NULL);
					//gettimeofday(&t, NULL);
					buff2[lastOpen(buff2)].inQ = true;
					//buff2[lastOpen(buff2)].entryTime.tv_usec = t.tv_usec;
					//buff2[lastOpen(buff2)].entryTime = t;
					//printf("\n\nENT TM: %ld", buff2[lastOpen(buff2)].entryTime.tv_usec);
				}
			}
			sent++;
			if (sent >= NUM_PACKETS) {
				break;
			}
		}
		servicePackets(serviceRate, buff1);
		servicePackets(serviceRate, buff2);	
		
	}
	//printf("\nLost packets: %d\n", lostPackets);
	//avgQLength = qLen / NUM_PACKETS;
	//printf("\nAvg Q Len: %d\n", avgQLength);
    avgQLength = qLen;
    //printf("\nAQL: %d", qLen);
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
	for (i = BUFFER_SIZE - 1; i > 0; i--) {
		//struct timeval exitTime;
		//gettimeofday(&exitTime, NULL);
		//totalWaitTime += (exitTime.tv_usec - buff[i].entryTime.tv_usec);
		//printf("\n\nET: %ld", exitTime.tv_usec);
		//printf("\n\nEntry: %ld", buff[i].entryTime.tv_usec);
		//printf("\n\nTWT: %ld", totalWaitTime);
		buff[i] = buff[i - 1];		
	}
	buff[0].inQ = false;
	//buff[0].entryTime.tv_usec = 0;
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
