#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#ifdef __linux__

#include <fcntl.h>
#include <unistd.h>
#include <linux/joystick.h>

#include <iostream>
#include <string>

#include "typedef.h"
#include "rovermisc.h"

#endif // __linux__


namespace rover{

#ifdef __linux__

	class joystick: public command{
	private:
		int fp;
		const unsigned int sample_period = 5000;

	public:
		/*
		 * Constructor por defecto. Llama a constructor con cadena "/dev/input/js0".
		 */
		joystick():
			joystick("/dev/input/js0")
			{}							// Ojo! compilar con -std=c++11, si no llamar otro constructor!!
		/*
		 * Abre archivo indicado en la cadena
		 *
		 * @param s 	Cadena con dirección con archivo de dispositivo.
		 */
		joystick(std::string s):
			command(){
			fp = open(s.c_str(), O_RDONLY | O_NONBLOCK);
		}
		~joystick(){
			close(fp);
		}

		/*
		 * Comprueba si se indicó problema en la apertura del archivo.
		 * @return True if the devices was not opened. False otherwise.
		 */
		bool failed();

		/**
		 * Otiene que tipo de evento se generó para obtener, o un rango númerico entre [-32767, 32767] normalizado mapeado proposionalmente [-1,1],
		 * o un botón con valor {0,1} mapeado a algún comando.
		 *
		 * @params c 	Comando leido.
		 * @return	True si se lee un comando. Falso de otra manera.
		 */
		bool get_command(command_t &c);

		/*
		 * Test Linux Joystick's API
		 */
		void test();
	};

#endif // __linux__

}

#endif // __JOYSTICK_H__