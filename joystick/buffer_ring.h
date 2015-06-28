#ifndef BUFFER_RING
#define BUFFER_RING

#include <vector>

//TODO: Optimization in case size is 1 (template matching)

namespace rover{

template<class X>
class buffer_ring{
private:
    std::vector<X> ring;
    unsigned int   index;
    const unsigned int size;

public:
    buffer_ring(unsigned int size){
        this->size = size;

        ring.resize(size);
    }
    ~buffer_ring(){}

    unsigned int size() const;

    void push(X item);
    X pull();
};

}

#endif // BUFFER_RING

