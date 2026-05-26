#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "calc.h"

int main() {
    int type;
    double var[26];
    bool var_init[26] = {false};
    double ans;
    bool ans_init = false;
    int last_var = -1;
    double op2;
    char s[OPSIZE];

    while ((type = getop(s)) != EOF) {
        matching:
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case VARIABLE:
                last_var = s[0];
                type = getop(s);
                if (type == EOF) {
                    printf("error: unfinished input\n");
                    return 0;
                }
                if (type == EQA) {
                    var_init[last_var - 'a'] = true;
                    var[last_var - 'a'] = pop();
                } else {
                    if (var_init[last_var - 'a']) {
                        push(var[last_var - 'a']);
                    } else {
                        printf("error: trying to use an unintialized variable %c\n", last_var);
                    }
                    goto matching;
                }
                break;
            case ANS:
                if (!ans_init) {
                    printf("error: no previous answer!\n");
                } else {
                    push(ans);
                }
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
                ans_init = true;
                ans = pop();
                printf("\t%.8g\n", ans);
                break;
            case ERR_ILLEGAL_COMMAND: default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
