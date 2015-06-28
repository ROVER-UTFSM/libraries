#ifndef ROVERMISC
#define ROVERMISC

#ifdef __linux__

#include <time.h>

namespace rover{

int wait(unsigned int useconds){
    //TODO: case useconds > 1[s].

    timespec sleep;
    sleep.tv_sec = 0;
    sleep.tv_nsec = useconds*1000;

    return nsleep(sleep);
}

}

#endif // __linux__


#endif // ROVERMISC
