#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include "remote_command.h"

#ifdef __linux__

#include <fcntl.h>
#include <unistd.h>
#include <linux/joystick.h>

#include <string>

#endif // __linux__


namespace rover{

#ifdef __linux__

class joystick: public remote_command{
private:
	int fp;

public:
	joystick(std::string s):
		remote_command(){
		fp = open(s.c_str(), O_RDONLY | O_NONBLOCK);
	}
	joystick(){
		joystick("/dev/input/js0");
	}
	~joystick(){
		close(fp);
	}

	bool opened();
	virtual bool get_command(command_t &c);
};

#endif // __linux__

}

#endif // __JOYSTICK_H__