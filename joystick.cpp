#include "joystick.h"

#include <iostream>

using namespace rover;

#ifdef __linux__

bool joystick::opened(){
	return fp != -1;
}

bool joystick::get_command(command_t &c){
	js_event event;
	int bytes = read(fp, &event, sizeof(js_event));


	if(bytes != sizeof(js_event))
		return false;

	
	std::cout << "Type :" << event.type << "number: " << event.number << "value: " << event.value << "\n";

	return true;
}

#endif //__linux__