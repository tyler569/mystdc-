
#ifndef MYSTD_UTILITY_H
#define MYSTD_UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

namespace my_std {

template <typename T>
static inline T max(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
static inline T min(T a, T b) {
    return a < b ? a : b;
}

static void panic(const char *message) {
    printf("PANIC: %s\n", message);
    exit(1);
}

static inline void assert(bool cond) {
    if (!cond) {
        panic("Assertion failed");
    }
}

template <typename T>
//__attribute__((malloc)) // TODO: macro this? // TODO: do this?
static inline T *alloc(size_t n) {
    void *result = ::malloc(n * sizeof(T));
    if (!result) {
        panic("Malloc failed! OOM?\n");
    }
    return reinterpret_cast<T *>(result);
}

template <typename T>
static inline T *realloc(T *ptr, size_t n) {
    void *result = ::realloc((void *)ptr, n * sizeof(T));
    if (!result) {
        panic("Realloc failed! OOM?\n");
    }
    return reinterpret_cast<T *>(result);
}

template <typename T>
static inline void free(T *ptr) {
    ::free(ptr);
}

// Wrap those allocation functions up into something useful.
// Some sort of static class probably.

} // namespace my_std

#endif
