#include <stdio.h>
#include <wiringPi.h>
#include <time.h>
#include <types.h>		// clockid_t

#define PIN 1							// PIN for encoder
#define EDGE_DETECTION INT_EDGE_BOTH	// Using both edges


/*** Global variables ***/

/* State of driver */
volatile struct timespec t0, t1;
volatile clockid_t c = CLOCK_REALTIME;			// Real-time clock (not CPU time)
volatile int last_timer = 0;					// 0: t0 has last time measurment ; 1: t1 has last time measurment

/* Measurements */
const int n_ranuras = 10;
const float theta_min = 360.0 / (2.0*n_ranuras);	// 2* when using both edges
const float omega = 0.0;

/* Definitions */
void pulse_period(void);	// Interruption


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
	/* Hipotesis : Despues de un canto de subida siempre sigue un canto de bajada */

	if(last_timer){
		clock_gettime(c, &t1);
		printf("omega : %.2f\n",  theta_min / (t1.tv_nsec - t0.tv_nsec));

		last_timer = 0;		// Pulse goes DOWN
	}else{
		clock_gettime(c, &t0);
		printf("omega : %.2f\n",  theta_min / (t0.tv_nsec - t1.tv_nsec));

		last_timer = 1;		// Pulse goes UP
	}

	/* Publish message ROS */
}