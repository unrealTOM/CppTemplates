#include "case_study_1.hpp"
#include "SwitchCase.h"
#include<vector>

double epsilon() {
    return 5.0;
}

void do_nothing() {
    printf("do nothing.\n");
}

void use_my_cool_struct(MyCoolStruct *foo) {
    printf("MyCoolStruct a: %d, b: %d, f: %f.2\n", foo->a, foo->b, foo->f);
}

void do_test(int x) {
    printf("do test: x(%d)\n", x);
}

#if SWITCH_CASE == 1
int main() {
    
    MyCoolStruct foo;
    api_exec(mandrake, &foo, 1, 2);
    api_exec(jack, &foo, 3, 4);
    api_exec(dmitri, &foo);
    api_exec(major, &foo, 5, 6, 7);
    
    // This is a compiler error:
    // api_exec(epsilon); 

    printf("------<<------\n");

    api_exec(mandrake, do_nothing, print_error, &foo, 8, 9);
    api_exec(mandrake, use_my_cool_struct, print_error, &foo, 10, 11);
    api_exec(mandrake, do_test, print_error, 3, &foo, 1, 0);

    printf("------>>------\n");

    api_exec(
    dmitri,
    [](const MyCoolStruct* foo){
        printf("Success!\n");
    },
    [](int err){
        printf("Calling all cool lambdas!\n");
    },
    &foo);
    
    api_exec(
    major,
    [](int){
        printf("Yee-haw!\n");
    },
    [](int err){
        printf("Another cool lambda!\n");
    },
    1, &foo, 8, 9, 10);

    int a[10];
    NoSubscriptOp(a);

    getchar();
    return 0;
}

#endif