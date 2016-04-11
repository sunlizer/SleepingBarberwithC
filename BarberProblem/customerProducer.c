#include "main.h"

void ProduceCustomer() {

	while (1) {
		if (rand() % 3 != 1) {
			pthread_t customer;
			int status = 0;
			status = pthread_create(&customer, NULL, (void *) customerThread,
			NULL);
			if (status != 0)
				perror("No Customers Yet!!!\n");
		}
		sleep(waitRandom(3));

	}
}
