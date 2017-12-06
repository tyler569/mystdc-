
#include <stdio.h> // TODO: replace print
#include "basic.hpp"
#include "array.hpp"

using namespace tyler_std;

// TODO generic print then generic prints for data structures
void print_arr(Array<int> *arr) {
    printf("Array { ");
    for (usize i=0; i<arr->len - 1; i++) {
        printf("%d, ", arr->at(i));
    }
    printf("%d }\n", arr->at(arr->len - 1));
}

// Personal coding style questions:
// Do I like references?
//
// They're implicit, which is bad,
// but raw pointers also require weird shit like ->
// everywhere.
//
// I might actually accept them.
void print_arr(Array<int>& arr) {
    printf("Array { ");
    for (usize i=0; i<arr.len - 1; i++) {
        printf("%d, ", arr.at(i));
    }
    printf("%d }\n", arr.at(arr.len - 1));
}

int postfix_eval(const char *program) {
    Array<int> stack(1);

    for (auto c=program; *c!=0; c++) {
        if (*c >= '0' && *c <= '9') {
            stack.push(*c - '0');
        } else if (*c == '+') {
            auto tmp1 = stack.pop();
            auto tmp2 = stack.pop();
            stack.push(tmp1 + tmp2);
        } else if (*c == '-') {
            auto tmp1 = stack.pop();
            auto tmp2 = stack.pop();
            stack.push(tmp1 - tmp2);
        } else if (*c == '*') {
            auto tmp1 = stack.pop();
            auto tmp2 = stack.pop();
            stack.push(tmp1 * tmp2);
        } else if (*c == '/') {
            auto tmp1 = stack.pop();
            auto tmp2 = stack.pop();
            stack.push(tmp1 / tmp2);
        } else if (*c == '=') {
            auto tmp1 = stack.pop();
            return tmp1;
        } else {
            // ignore
        }
        // print_arr(stack);
    }
    return stack.pop();
}

int main() {

    const int cnt = 3;

    printf("max(1, 2) == %d\n", max(1, 2));

    int *x = alloc<int>(cnt);
    for (int i=0; i<cnt; i++) {
        x[i] = i * 3;
    }
    for (int i=0; i<cnt; i++) {
        printf("x[%i] == %i\n", i, x[i]);
    }

    Array<int> a(100);

    for (int i=0; i<cnt; i++) {
        a.push(i * 27);
    }
    for (int i=0; i<cnt; i++) {
        printf("a.at(%i) == %i\n", i, a.at(i));
    }

    for (auto i : a) {
        printf("foreach %i is in a\n", i);
    }
    print_arr(&a);

    printf("1 2 3 + * => %i\n", postfix_eval("1 2 3 + *"));
    printf("1 2 3 * + => %i\n", postfix_eval("1 2 3 * +"));

    Array<int> foo(1);
    for (int i=0; i<100; i++) {
        foo.push(i / 2);
    }

    auto bar = Array<int>(5);
    bar.len = 5;
    for (auto& b : bar) {
        b = 10;
    }
    print_arr(bar);

}
