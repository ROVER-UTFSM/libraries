#include <stdio.h>

#include "../../common_types/typedef.h"
#include "../../headers/joystick.h"
#include "../../miscellaneous/rovermisc.h"

int main(int argc, char *argv[]){
	rover::command *Joystick = new rover::joystick();
	rover::command_t command;


	//Rover State
	int tvel = 0, avel = 0;

	if( ((rover::joystick*)Joystick)->failed() ){
		printf("No se encontro joystick\n");
		return -1;
	}

	while(1){
		if(Joystick->get_command(command)){

			if(command.type == rover::VEL_A_COMMAND){
				avel = (int)(command.value*100.0);
			}
			if(command.type == rover::VEL_R_COMMAND){
				tvel = (int)(command.value*100.0);
			}
			if(command.type == rover::EXIT_COMMAND){
				break;
			}

			printf("Estado: \n\tvelocida tangencial: %d\n\tvelocidad angular: %d\n", tvel, avel);
		}

		rover::wait(10000);
	}

	delete Joystick;

	return 0;
}