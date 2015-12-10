#include <stdio.h>
#include <unistd.h>


#include <wiringPi.h>

#define PWM_PIN 			1				// unico pin para pwm
#define PWM_CLOCK_DIVISOR	16				// 19.2[MHz] /16 = 1.2[MHz]
#define PWM_RANGE			1024			// 1.2[MHz] /1024 = 1.171875[KHz]

int main(){
	/* Wiring setups */
	wiringPiSetup();
	pinMode(PWM_PIN, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(PWM_CLOCK_DIVISOR);
	pwmSetRange(PWM_RANGE);

	int i;
	for(i=0; i<PWM_RANGE; i+=20){
		pwmWrite(PWM_PIN, i);
		usleep(10000);
	}

	/**/

	return 0;
}
