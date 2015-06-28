#ifndef __ROVERMISC_H_
#define __ROVERMISC_H_

#ifdef __linux__

#include <time.h>

namespace rover{

int wait(unsigned int useconds){
    //TODO: case useconds > 1[s].

    timespec sleep;
    sleep.tv_sec = 0;
    sleep.tv_nsec = useconds*1000;

    return nanosleep(&sleep, &sleep);
}

}

#endif // __linux__

#ifdef __MINGW32__

//#include

namespace rover{
// ...
}

#endif // __MINGW32__

#endif // ROVERMISC
