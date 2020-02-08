#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/mman.h>

void* buildLeft(void* args);
void* buildRight(void* args);

int* semaphore;

int main(int argc, char** argv){
	if (argc != 2) printf("Usage: %s HEIGHT\n", argv[0]);
	else {
		semaphore = (int*) mmap(NULL, 6, PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED, -1, 0);
		*semaphore = 1;

		printf("Clearing screen...\e[2J");
		int h = atoi(argv[1]);
		int w = (h*2)-1;

		pthread_t f1, f2;

		printf("\e[%i;%iHP", 0, w/2);

		pthread_create(&f1, NULL, buildLeft, &h);
		pthread_create(&f2, NULL, buildRight, &h);

		pthread_join(f1, NULL);
		pthread_join(f2, NULL);

		for (int i = 0; i < w; i++) printf("\e[%i;%iHP", h, i);
		printf("\n");
	}
	return 0;
}

void* buildRight(void* args) {
	int h = *(int*)args;
	int w = (h*2)-1;

	int y = 2;

	for (int i = 1; (i < w/2) && (y < h); i++) {
		while (*v != 2);
		printf("\e[%i;%iH2", y, (w/2)+i);
		y++;
		*v = 1;
	}

	pthread_exit(0);
}

void* buildLeft(void* args) {
	int h = *(int*)args;
	int w = (h*2)-1;
	
	int y = 2;

	for (int i = 1; (i < w/2) && (y < h); i++) {
		while (*v != 1);
		printf("\e[%i;%iH1", y, (w/2)-i);
		y++;
	}


	pthread_exit(0);
}

