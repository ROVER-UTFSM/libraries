#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include "remote_command.h"

#ifdef __linux__

#include <fcntl.h>
#include <unistd.h>
#include <linux/joystick.h>

#include <iostream>
#include <string>

#include "rovermisc.h"

#endif // __linux__


namespace rover{

#ifdef __linux__

class joystick: public remote_command{
private:
	int fp;
	const unsigned int sample_period = 5000;

public:
	joystick():
		joystick("/dev/input/js0")
		{}							// Ojo! compilar con -std=c++11, si no llamar otro constructor!!
	joystick(std::string s):
		remote_command()
		{
		fp = open(s.c_str(), O_RDONLY | O_NONBLOCK);
	}
	~joystick(){
		close(fp);
	}

	bool opened();
	bool get_command(command_t &c);

	void test();
};

#endif // __linux__

}

#endif // __JOYSTICK_H__