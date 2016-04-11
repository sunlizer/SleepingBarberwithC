/*
 * barber.c
 *
 *  Created on: 9 Kas 2014
 *      Author: sunlizer
 */

#include "main.h"
void barberThread(void * tmp) {
	int myNext, C;
	while (1)
	{
		PrintStatus(0);
		sem_wait(&barbers);//Wait for new customer.
		PrintStatus(0);
		sem_wait(&mutex);
		serveMeNext = (++serveMeNext) % 5;
		myNext = serveMeNext;
		C = seatPocket[myNext];
		seatPocket[myNext] = 0;
		sem_post(&mutex);
		sem_post(&customers);
		PrintStatus(1);
		sleep(waitRandom(5));
	}
}
