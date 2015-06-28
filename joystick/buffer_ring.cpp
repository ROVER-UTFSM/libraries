#include "buffer_ring.h"

using namespace rover;

template <typename X>
void buffer_ring<X>::push(X item){
    ring[end_index++] = item;

    end_index = (end_index == nsize)? 0: end_index;
}

template <typename X>
X buffer_ring<X>::pull(){
    X returned = ring[index++];

    index = (index == nsize)? 0: index;

    return returned;
}
