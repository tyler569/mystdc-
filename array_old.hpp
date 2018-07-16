
#ifndef MYSTD_ARRAY_H
#define MYSTD_ARRAY_H

#include "basic.hpp"

namespace my_std {

template <typename T>
struct Array {
    T *data;
    size_t len;
    size_t count;

    Array(size_t = 16);
    ~Array();
    T at(size_t);
    T *at_ptr(size_t);
    void push(T);
    T pop();
    void set(size_t, T);
    void print();

    // For foreach construct
    T *begin();
    T *end();
};

/* TODO
 * custom allocators
 */

template <typename T>
Array<T>::Array(size_t initial) {
    printf("Allocated array");
    this->count = initial;
    this->len = 0;
    this->data = alloc<T>(initial);
    printf(" : data = %p\n", this->data);
}

template <typename T>
Array<T>::~Array() {
    printf("Deallocated array : data = %p\n", this->data);
    free(this->data);
}

template <typename T>
T Array<T>::at(size_t n) {
#ifndef NDEBUG
    if (n >= this->len) {
        panic("Out-of-bounds access");
    }
#endif
    return this->data[n];
}

template <typename T>
T *Array<T>::at_ptr(size_t n) {
#ifndef NDEBUG
    if (n >= this->len) {
        panic("Out-of-bounds access");
    }
#endif
    return &this->data[n];
}

template <typename T>
void Array<T>::push(T value) {
    if (this->count >= this->len) {
        // Need to allocate!
    }
    this->data[this->len] = value;
    this->len += 1;
}

template <typename T>
T Array<T>::pop() {
    this->len -= 1;
    // reallocate smaller?
    return this->data[this->len];
}

template <typename T>
void Array<T>::set(size_t n, T value) {
#ifndef NDEBUG
    if (n >= this->len) {
        panic("Out-of-bounds access");
    }
#endif
    this->data[n] = value;
}

template <>
void Array<int>::print() {
    printf("Array{ ");
    for (size_t i=0; i<this->len - 1; i++) {
        printf("%d, ", this->at(i));
    }
    printf("%d }\n", this->at(this->len - 1));
}

template <typename T>
T *Array<T>::begin() {
    return this->data;
}

template <typename T>
T *Array<T>::end() {
    return this->data + this->len;
}

} // namespace my_std

#endif
