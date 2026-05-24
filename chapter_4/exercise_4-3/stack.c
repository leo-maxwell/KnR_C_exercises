#include <stdio.h>
#include "calc.h"

int sp = 0;
double stack[STACKSIZE];

void push(double f) {
    if (sp < STACKSIZE) {
        stack[sp++] = f;
    } else {
        printf("push: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        return stack[--sp];
    } else {
        printf("pop: stack empty");
        return 0.0;
    }
}
