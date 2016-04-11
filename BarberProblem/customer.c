#include "main.h"

void customerThread(void * tmp) {
	int mySeat, B;
	sem_wait(&mutex);
	count++;
	if (numberOfFreeSeats > 0) {
		--numberOfFreeSeats;
		sitHereNext = (++sitHereNext) % 5;
		mySeat = sitHereNext;
		seatPocket[mySeat] = count;
		sem_post(&mutex);
		sem_post(&barbers);
		sem_wait(&customers);
		sem_wait(&mutex);
		B = seatPocket[mySeat];
		numberOfFreeSeats++;
		sem_post(&mutex);
	} else {
		sem_post(&mutex);
		PrintStatus(1);
		printf("Customer-%d Finds No Seat & Leaves.\n", count);

	}
	pthread_exit(0);
}
