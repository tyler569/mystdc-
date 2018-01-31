
#ifndef MYSTD_ARRAY_H
#define MYSTD_ARRAY_H

#include "basic.hpp"

namespace my_std {

template <typename T>
struct Array {
    T *data;
    usize len;
    usize count;

    Array(usize initial = 16) {
        count = initial;
        len = 0;
        data = alloc<T>(initial);
    }

    ~Array() {
        free(data);
    }

    T at(usize n) {
#ifndef NDEBUG
        if (n >= len) {
            panic("Out-of-bounds access");
        }
#endif
        return data[n];
    }

    T *at_ptr(usize n) {
#ifndef NDEBUG
        if (n >= len) {
            panic("Out-of-bounds access");
        }
#endif
        return &data[n];
    }

    void push(T value) {
        if (count <= len) {
            printf("Diagnostic: allocating %lu -> %lu\n", count, count * 2);
            T *new_data = realloc(data, count * 2);
            data = new_data;
            count = count * 2;
        }
        data[len] = value;
        len += 1;
    }

    T pop() {
        len -= 1;
        // reallocate smaller?
        return data[len];
    }

    void set(usize n, T value) {
#ifndef NDEBUG
        if (n >= len) {
            panic("Out-of-bounds access");
        }
#endif
        data[n] = value;
    }

    T *begin() {
        return data;
    }

    T *end() {
        return data + len;
    }

};

/* TODO
 * custom allocators
 */

} // namespace my_std

#endif
