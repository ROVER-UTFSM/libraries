#include <stdio.h>
#include <wiringPi.h>
#include <time.h>
#include <sys/types.h>								// clockid_t

#define PIN 1									// PIN for encoderZ


/*** Global variables ***/

/* State of driver */
volatile struct timespec t0, t1;				// t0: pulse start time t1: pulse end time
volatile const clockid_t c = CLOCK_REALTIME;	// Real-time clock (not CPU time)

/* Measurements */
const int K_cm_to_ns = 58000					// Linear transformation : x[cm] = t[ns] / 58000


/*** Definitions ***/

/* Interrupts */
void pulse_period(void);						// Both edge detection

/* functions */
long distance(long nanoseconds)					// f(t) : t[s] -> x[cm]


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

long distance(long nanoseconds){
	// Needs calibration : +20 ????? minimum measurement by datasheet
	// Resolution of 1[cm]. Test!
	return nanoseconds / K_cm_to_ns;
}

/*** Implementations ***/
// A timer interruptions is needed to send a 0[cm] distant measurment after some time t without measurment (kind of a watchdog for de pulse)

/* Pulse Interruption -- PIN 1 (12 BOARD) */
void pulse_period(void){
	/* Hipotesis : Despues de un canto de subida siempre sigue un canto de bajada */

	if(digitalRead(PIN) == HIGH ){
		clock_gettime(c, &t0);

	}else{
		clock_gettime(c, &t1);
		printf("x : %ld\n",  distance(t1.tv_nsec - t0.tv_nsec));
	}

	/* Publish message ROS */
}