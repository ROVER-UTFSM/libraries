#ifndef JOYSTICK
#define JOYSTICK

#include <iostream>

#include "buffer_ring.h"
#include "rovermisc.h"

namespace rover{

/**
  * Constants
  */
// ...


/**
 * @brief General configurations for joystick interaction and button mapping
 */
struct configuration{
    unsigned int num_of_buttons;    // buttons only has boolean values
    unsigned int num_of_dig_axis;   // digital axis have 0 or 1 as values
    unsigned int num_of_ang_axis;   // analog axis have a range of values

    unsigned int sampling_period;           // in [ms]
    unsigned int macro_sampling_period;     // in [ms]
};


/**
 * @brief Abstraction for any kind of joystick.
 * All buttons are mapped to an unique natural number.
 */
class joystick{
private:
    buffer_ring<unsigned int> buttons;
    configuration conf;

    const unsigned int macro_factor = 10;

public:

    joystick(){
        joystick(12, 10);
    }
    joystick(unsigned int num_of_buttons, unsigned int sampling_period){

        conf.num_of_buttons  = num_of_buttons;
        conf.sampling_period = sampling_period;
        conf.macro_sampling_period = conf.sampling_period * macro_factor;

        buttons(conf.num_of_buttons);   // max. number of buttons to generate a macro/combo
    }
    ~joystick(){}

    virtual bool         was_pressed();
    virtual unsigned int button();
    virtual std::vector<unsigned int> macro();

    unsigned int test(){
        for(int i=0;i<conf.num_of_buttons;i++){
            while(!was_pressed())
                wait(conf.sampling_period);
            std::cout << button() << " was pressed\n";
        }
    }

};

}

#endif // JOYSTICK

