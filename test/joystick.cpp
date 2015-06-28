#include <iostream>

#include "../joystick.h"
#include "../rovermisc.h"

int main(int argc, char *argv[]){
	rover::joystick  Joystick;
	rover::command_t command;

	if(Joystick.opened())
		std::cout << "Is open\n";

	while(1){
		Joystick.get_command(command);
		//std::cout << "printed\n";
		rover::wait(100000);
	}

	return 0;
}