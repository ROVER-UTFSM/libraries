#ifndef __REMOTE_COMMAND_H_
#define __REMOTE_COMMAND_H_


namespace rover{
	
	typedef enum {
		EXIT_COMMAND, VEL_R_COMMAND, VEL_A_COMMAND
	} command_type_t;

	typedef struct {
		command_type_t 	type;
		float 			value;
	} command_t;

	/**
	 * Uses the Command pattern to generate from each input equivalences to the Rover's instructions.
	 */
	class remote_command{

	public:
		remote_command(){}
		~remote_command(){}

		virtual bool get_command(command_t &c) = 0;		// False for no or incorrect command. True otherwise.
	};

}

#endif // __REMOTE_COMMAND_H_