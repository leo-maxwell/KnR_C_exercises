#include <stdio.h>
#include "calc.h"

static int stack_p = 0;
static double stack[STACKSIZE];

double peek(void) {
    if (stack_p > 0) {
        return stack[stack_p - 1];
    } else {
        printf("peek: stack empty\n");
        return 0.0;
    }
}

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
        printf("pop: stack empty\n");
        return 0.0;
    }
}

void print_top(void) {
    if (stack_p > 0)
        printf("%g\n", peek());
    else
        printf("print_top: stack empty\n");
}

void dup_top(void) {
    if (stack_p > 0)
        push(peek());
    else
        printf("dup_top: stack empty\n");
}

void clear(void) {
    stack_p = 0;
}

void swap_top(void) {
    if (stack_p < 2) {
        printf("swap_top: not enough items in the stack\n");
        return;
    }
    double top = stack[stack_p - 1];
    stack[stack_p - 1] = stack[stack_p - 2];
    stack[stack_p - 2] = top;
}
