#include buffer_ring.h

using namespace rover;

template <class X>
void buffer_ring::push(X item){
    ring[end_index++] = item;

    end_index = (end_index == size)? 0: end_index;
}

template <class X>
X buffer_ring::pull(){
    X returned = ring[index++];

    index = (index == size)? 0: index;

    return returned;
}
