#include <stdio.h>
#include <time.h>
#include <sys/types.h>

#define NTIMES 10

long factor(long x){
	long r = 1;
	int i;
	for(i=0;i<x;i++) x *= i;
	return r;
}

int main(){
	long tprom = 0;
	clockid_t c = CLOCK_REALTIME;
	struct timespec t0, t1;
	clock_settime(c, &t0);
	clock_settime(c, &t1);

	int i;
	for(i=0;i<NTIMES;i++){
		clock_gettime(c, &t0);
		factor(10);
		clock_gettime(c, &t1);
		tprom += t1.tv_nsec-t0.tv_nsec;
	}
	printf("Delta: %.1f[ns]\n", tprom*1.0 / NTIMES);


	return 0;
}