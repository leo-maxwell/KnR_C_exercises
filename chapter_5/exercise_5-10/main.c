#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "calc.h"

int main(int argc, char** argv) {
    int type;
    double var[26];
    bool var_init[26] = {false};
    double ans;
    bool ans_init = false;
    int last_var = -1;
    double op2;

    if (argc < 3) {
        fprintf(stderr, "wrong usage, arguments too few\n");
        return -1;
    }

    int j; // token index
    int k; // intra-token index

    // token processing
    int tokens = argc - 1;
    for (j = 1; j <= tokens; j++) {
        // lowercase everything
        for (k = 0; argv[j][k] != '\0'; k++) {
            argv[j][k] = argv[j][k] >= 'A' && argv[j][k] <= 'Z' ? argv[j][k] - 'A' + 'a' : argv[j][k];
        }
        type = getop(argv[j]);
        switch (type) {
            case NUMBER:
                push(atof(argv[j]));
                break;
            case VARIABLE:
                last_var = argv[j][0];
                if (j < tokens - 1) type = getop(argv[j+1]);
                else {
                    printf("error: unfinished input\n");
                    return 0;
                }
                if (type == EOF) {
                    printf("error: unfinished input\n");
                    return 0;
                }
                if (type == EQA) {
                    var_init[last_var - 'a'] = true;
                    var[last_var - 'a'] = pop();
                    j++; // token EQA has been consumed, jump to next
                } else {
                    if (var_init[last_var - 'a']) {
                        push(var[last_var - 'a']);
                        j--; // the token is not EQA, go back
                    } else {
                        printf("error: trying to use an unintialized variable %c\n", last_var);
                    }
                }
                break;
            case ANS:
                if (!ans_init) {
                    printf("error: no previous answer!\n");
                } else {
                    push(ans);
                }
                break;
            case ONECHAROP:
                switch (argv[j][0]) {
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
                }
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
            case ERR_ILLEGAL_NUMBER:
                printf("getop: illegal number %s\n", argv[j]);
                break;
            case ERR_ILLEGAL_COMMAND:
                printf("error: illegal command %s\n", argv[j]);
                break;
            case ERR_ILLEGAL_OP:
                printf("error: character not supported %s\n", argv[j]);
                break;
            default:
                printf("error: unknown input %s\n", argv[j]);
                break;
        }
    }
    // after operation done, output the results
    ans_init = true;
    ans = pop();
    printf("\t%.8g\n", ans);
    return 0;
}
