#ifndef MAINH
#define MAINH


#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

static int count=0;
static int numberOfFreeSeats = 5;
int seatPocket[5];
static int sitHereNext = 0;
static int serveMeNext = 0;

sem_t customers;
sem_t barbers;
sem_t mutex;

void barberThread(void *tmp);
void ProduceCustomer();
void customerThread(void *tmp);
int waitRandom(int mod);
void PrintStatus(int status);

#endif /* MAIN_H_ */
