#include <stdio.h>
#include <wiringPi.h>
#include <time.h>
#include <sys/types.h>							// for clockid_t

#define PIN 1									// PIN for encoder
#define EDGE_DETECTION INT_EDGE_BOTH			// Using both edges
#define PI 3.1415

/*** Global variables ***/

/* State of driver */
volatile struct timespec t0, t1;
volatile clockid_t c    = CLOCK_MONOTONIC;		// Real-time clock (not CPU time)
volatile int last_timer = 0;					// 0: t0 has last time measurment ; 1: t1 has last time measurment

/* Measurements */
const int n_ranuras   = 10;
const float theta_min = 2.0*PI / (2*10);		// 2* when using both edges
const float omega     = 0.0;

/* Definitions */
void pulse_period(void);						// Interruption


int main(){
	/* Wiring setups */
	wiringPiSetup();
	wiringPiISR(PIN, EDGE_DETECTION, &pulse_period);
	// TODO : capture errors

	/* Clock setup */
	clock_settime(c, &t0);
	clock_settime(c, &t1);
	clock_gettime(c, &t0);	// initial value
	clock_gettime(c, &t1);	// initial value

	/* Infinite Loop */
	while(1);

	return 0;
}


/* Pulse Interruption -- PIN 1 (12 BOARD) */
void pulse_period(void){
	/* Hipotesis : Despues de un canto de subida siempre sigue un canto de bajada :O */
	float delta = 0.0;

	if(last_timer){
		clock_gettime(c, &t1);
		delta = t1.tv_sec-t0.tv_sec + (t1.tv_nsec - t0.tv_nsec)/1000000000.0;
		printf("delta t : %.3f[m] -> velocidad : %.1f[cm/s]\n", delta, theta_min*4/delta);

		last_timer = 0;		// t0 has the last time
	}else{
		clock_gettime(c, &t0);
		delta = t0.tv_sec-t1.tv_sec + (t0.tv_nsec - t1.tv_nsec)/1000000000.0;
		printf("delta t : %.3f[m] -> velocidad : %.1f[cm/s]\n", delta, theta_min*4/delta);

		last_timer = 1;		// t1 has the last time
	}

	/* Publish message ROS */
}
