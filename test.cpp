
#include <stdio.h> // TODO: replace print
#include "basic.hpp"
#include "box.hpp"
#include "array.hpp"

using namespace my_std;

/*void print_std(Box<int>& box) {
    printf("Box { %i }\n", *box);
}*/

// TODO: Think about whether I like references or not.
// They're clean, but they hide what is actually going on.
void print_std(Array<int>& arr) {
    printf("Array { ");
    for (size_t i=0; i<arr.len - 1; i++) {
        printf("%d, ", arr.at(i));
    }
    printf("%d }\n", arr.at(arr.len - 1));
}

void print_std(Box<int>& box) {
    printf("Box { ");
    printf("%i", *box);
    printf(" }\n");
}

void print_std(Box<int[10]>& box) {
    printf("Box { ");
    for (int i=0; i<10; i++) {
        printf("%i", (*box)[i]);
        if (i != 9)
            printf(", ");
    }
    printf(" }\n");
}

// A thing we can do with dynamic arrays.
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
        // print_std(stack);
    }
    return stack.pop();
}

int main() {
    const int cnt = 3;

    { // max
        printf("max(1, 2) == %d\n", max(1, 2));
    }

    { // raw alloc<T>();
        int *x = alloc<int>(cnt);
        for (int i=0; i<cnt; i++) {
            x[i] = i * 3;
        }
        for (int i=0; i<cnt; i++) {
            printf("x[%i] == %i\n", i, x[i]);
        }
        free(x);
    }

    { // Array<T>
        Array<int> a(100);
        
        // Create and push
        for (int i=0; i<cnt; i++) {
            a.push(i * 27);
        }
        // TODO: think about allowing operator[] accesses.
        for (int i=0; i<cnt; i++) {
            printf("a.at(%i) == %i\n", i, a.at(i));
        }

        // C++11 foreach-style loops
        for (auto i : a) {
            printf("foreach %i is in a\n", i);
        }
        print_std(a);

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
        print_std(bar);
    }

    {
        auto c = Box<int>(10);
        print_std(c);

        auto d = Box<int[10]>();
        for (int i=0; i<10; i++) {
            (*d)[i] = i;
        }
        (*d)[6] = 100;
        printf("%i\n", (*d)[6]);
        print_std(d);
    }
}
