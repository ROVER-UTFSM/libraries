#ifndef __ROVERMISC_H_
#define __ROVERMISC_H_


#ifdef __linux__

#include <time.h>

namespace rover{

	/*
	 * Sólo implimentado en Linux por ahora.
	 * @param useconds	Microsegundos a dormir.
	 */
	int wait(unsigned int useconds);

}

#endif // __linux__



#ifdef __MINGW32__
#endif // __MINGW32__



#endif // __ROVERMISC_H_
