#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

int main() {
    int type;
    double op2;
    char s[OPSIZE];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 == 0.0)
                    printf("error: zero divisor\n");
                else
                    push(pop() / op2);
                break;
            case '%':
                op2 = pop();
                if (op2 == 0.0)
                    printf("error: zero divisor\n");
                else
                    push(fmod(pop(), op2));
                break;
            case SIN:
                push(sin(pop()));
                break;
            case COS:
                push(cos(pop()));
                break;
            case TAN:
                push(tan(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case ERR_ILLEGAL_COMMAND: default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
