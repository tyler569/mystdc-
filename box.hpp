
#ifndef MYSTD_BOX_H
#define MYSTD_BOX_H

#include "basic.hpp"

namespace my_std {

template <typename T>
struct Box {
    T *data;
    
    Box() {
        data = alloc<T>(sizeof(T));
    }

    Box(T d) {
        data = alloc<T>(sizeof(T));
        *data = d;
    }

    ~Box() {
        free(data);
    }

    T& operator *() {
        return *data;
    }
};

} // namespace my_std

#endif
