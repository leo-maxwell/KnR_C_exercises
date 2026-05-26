#include <ctype.h>
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
    char **s; // token buffer
    char *l = NULL; // line buffer
    size_t linecap = LINESIZE;

    while (getline(&l, &linecap, stdin) != EOF) {
        int i; // line index
        int j; // token index
        int k; // intra-token index
        // initialize token buffer
        s = malloc(sizeof(*s) * LINE_TOKENS);
        for (j = 0; j < LINE_TOKENS; j++)
            s[j] = NULL;

        // strip leading spaces
        for(i = 0; isspace(l[i]); i++);

        // token separation
        for (j = 0, k = 0; l[i] != '\0' && j < LINE_TOKENS; i++) {
            if (isspace(l[i])) {
            // if space, a token is got and being separated
                s[j][k] = '\0';
                k = 0;
                j++;
                // remove extra spaces
                for(; isspace(l[i]); i++);
                i--; // an extra addition is guaranteed, remove it
            } else {
                if (s[j] == NULL) {
                    s[j] = malloc(sizeof(s) * OPSIZE);
                }
                s[j][k++] = l[i];
            }
        }
        if (j >= LINE_TOKENS - 1) {
            if (l[i] != '\0') {
                printf("error: input line too long\n");
                return 0;
            }
        } else {
        // the last newline will be missed by separation above, add it back
            s[j] = "\n";
        }

        // token processing
        int tokens = j;
        for (j = 0; j < tokens; j++) {
            char *token = s[j];
            // lowercase everything
            for (k = 0; s[j][k] != '\0'; k++) {
                s[j][k] = s[j][k] >= 'A' && s[j][k] <= 'Z' ? s[j][k] - 'A' + 'a' : s[j][k];
            }
            type = getop(s[j]);
            matching:
            switch (type) {
                case NUMBER:
                    push(atof(s[j]));
                    break;
                case VARIABLE:
                    last_var = s[j][0];
                    type = getop(s[j+1]);
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
                case ERR_ILLEGAL_NUMBER:
                    printf("getop: illegal number %s\n", s[j]);
                case ERR_ILLEGAL_COMMAND:
                    printf("error: illegal command %s\n", s[j]);
                    break;
                case ERR_ILLEGAL_OP:
                    printf("error: character not supported %s\n", s[j]);
                    break;
                default:
                    printf("error: unknown input %s\n", s[j]);
                    break;
            }
        }

        // destruct everything
        free(l);
        for (j = 0; j < LINE_TOKENS; j++)
            free(s[j]);
        free(s);
    }
    return 0;
}
