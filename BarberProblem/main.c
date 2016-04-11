#include "main.h"
int main() {
	pthread_t barber, customer;
	int status = 0;
	sem_init(&customers, 0, 0);
	sem_init(&barbers, 0, 0);
	sem_init(&mutex, 0, 1);
	printf("!!Barber Shop Opens!!\n");
	status = pthread_create(&barber, NULL, (void *) barberThread, NULL);
	sleep(1);

	ProduceCustomer();

	return 1;
}

int waitRandom(int mod)
{
	srand(time(NULL));
	return  rand() % mod+1;
}

void PrintStatus(int status) {
	int flag=0;
	printf("\n______________________________________________________\n");
	int i = 0;
	for (i = 0; i < 5; i++) {
		printf("%s ", seatPocket[i] == 0 ? "_" : "X");
		if(seatPocket[i] != 0) flag=1;
	}
	printf("\n  %s  ", status ? "X":"_");
	if (flag==0 && status==0 )printf("\n_   ");
	printf("\n");
}
