#ifndef BUFFER_RING
#define BUFFER_RING

#include <vector>
#include <cstring>

//TODO: Optimization in case size is 1 (template matching)

namespace rover{

template<typename X>
class buffer_ring{
private:
    std::vector<X> ring;
    unsigned int   index, end_index;
    const unsigned int nsize;

public:
    buffer_ring(unsigned int size){
        nsize = size;
        index = 0, end_index = 0;

        ring.resize(size);
        std::fill(ring.begin(), ring.end(), 0);
    }
    ~buffer_ring(){}

    unsigned int size() const;

    void push(X item);
    X pull();
};

}

#endif // BUFFER_RING

