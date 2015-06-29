#include <stdio.h>

#include "../joystick.h"
#include "../rovermisc.h"

int main(int argc, char *argv[]){
	rover::joystick Joystick;
	rover::command_t command;


	if(Joystick.opened()){
		printf("Joystick abierto\n");
	}

	//Joystick.test();
	
	//Rover State
	int tvel = 0, avel = 0;
	
	while(1){
		Joystick.get_command(command);

		if(command.type == rover::VEL_A_COMMAND){
			avel = (int)command.value*100.0;
		}
		if(command.type == rover::VEL_R_COMMAND){
			tvel = (int)command.value*100.0;
		}
		if(command.type == rover::EXIT_COMMAND){
			break;
		}

		printf("Estado: \n\tvelocida tangencial: %d\n\tvelocidad angular: %d\n", tvel, avel);

		rover::wait(10000);
	}

	return 0;
}