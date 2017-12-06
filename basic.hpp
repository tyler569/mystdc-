
#ifndef MYSTD_UTILITY_H
#define MYSTD_UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

namespace tyler_std {

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef size_t usize;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef intmax_t isize;

typedef float f32;
typedef double f64;

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
//__attribute__((malloc)) // TODO: macro this?
static inline T *alloc(usize n) {
    void *result = ::malloc(n * sizeof(T));
    if (!result) {
        panic("Malloc failed! OOM?\n");
    }
    return reinterpret_cast<T *>(result);
}

template <typename T>
static inline T *realloc(T *ptr, usize n) {
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

} // namespace tyler_std

#endif
