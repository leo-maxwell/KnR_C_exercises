#include <stdio.h>
#include "calc.h"

int stack_p = 0;
double stack[STACKSIZE];

void push(double f) {
    if (stack_p < STACKSIZE) {
        stack[stack_p++] = f;
    } else {
        printf("push: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (stack_p > 0) {
        return stack[--stack_p];
    } else {
        printf("pop: stack empty");
        return 0.0;
    }
}
