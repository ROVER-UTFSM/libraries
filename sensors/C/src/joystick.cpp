#include "../headers/joystick.h"


using namespace rover;

#ifdef __linux__

bool joystick::failed(){
	return fp < 0;
}

bool joystick::get_command(command_t &c){
	js_event event;

	if(read(fp, &event, sizeof(js_event)) != sizeof(js_event))
		return false;

	if(event.type == JS_EVENT_AXIS){
		//Left Analog axis
		if(event.number == 1){
			c.type  = VEL_R_COMMAND;
			c.value = -((float)event.value)/32767.0;	//Transform to counter-clockwise.
		}else if(event.number == 2){
			c.type  = VEL_A_COMMAND;
			c.value = -((float)event.value)/32767.0;	//Forward is positive.
		}

		//Right Analog axis not in used (VEL_A is reported as event.number ==2 :S)

		// Digital axis
		else if(event.number == 4){
			c.type  = VEL_A_COMMAND;
			c.value = -((float)event.value)/32767;	//Transform to counter-clockwise.
		}else if(event.number == 5){
			c.type  = VEL_R_COMMAND;
			c.value = -((float)event.value)/32767;	//Forward is positive.
		}
	}else if(event.type == JS_EVENT_BUTTON){
		if(event.number == 4 && event.value == 1){
			c.type  = EXIT_COMMAND;
			c.value = 1.0;
		}
	}else if( (event.type & JS_EVENT_INIT) > 0){}
	else{}

	return true;
}

void joystick::test(){
	js_event event;		// read event

	while(1){
		if(read(fp, &event, sizeof(js_event)) == sizeof(js_event))
			std::cout << "Type :" << (int)event.type << "  number: " << (int)event.number << "  value: " << event.value << "\n";
		wait(sample_period);
	}
}

#endif //__linux__