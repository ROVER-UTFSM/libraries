#include "rovermisc.h"


#ifdef __linux__



int rover::wait(unsigned int useconds){
    //TODO: case useconds > 1[s].

    timespec sleep;
    sleep.tv_sec = 0;
    sleep.tv_nsec = useconds*1000;

    return nanosleep(&sleep, &sleep);
}


#endif // __linux__
