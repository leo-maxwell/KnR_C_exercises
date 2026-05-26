#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "calc.h"

int getop(char *s) {
    int n = strlen(s);
    int k = 0; // current intra-token cursor position
    int c; // handy cache
    // handle the edge cases first
    if (s[0] == EOF || s[0] == '\0') return EOF;
    if (s[0] == '\n') return '\n';
    // first handle single character case
    if (n == 1) {
        c = s[0];
        if (!isdigit(c) && !isalpha(c) && c != ANS) {
        // not number, not letter, not ANS, only single char possible
            return ONECHAROP;
        } else if (isalpha(c)) {
        // single char variables
            return VARIABLE;
        } else if (c == ANS) {
            return ANS;
        } else if (isdigit(c)) {
            return NUMBER;
        } else {
            printf("getop: character not supported %c\n", c);
            return ERR_ILLEGAL_OP;
        }
    } else {
    // commands and numbers
        c = s[0];
        if (isalpha(s)) {
        // if longer than one char and starts with letter, then it must be commands
            if (strcmp(s, "sin") == 0) {
            return SIN;
            } else if (strcmp(s, "exp") == 0) {
            return EXP;
            } else if (strcmp(s, "cos") == 0) {
            return COS;
            } else if (strcmp(s, "tan") == 0) {
            return TAN;
            } else if (strcmp(s, "pow") == 0) {
            return POW;
            } else if (strcmp(s, "eqa") == 0) {
            return EQA;
            } else {
                printf("getop: illegal command %s\n", s);
                return ERR_ILLEGAL_COMMAND;
            }
        } else {
        // can only be numbers
            if (s[0] == '-') {
                c = s[1];
                if (c == '.') {
                    k = 2;
                } else if (isdigit(c)) {
                    k = 1;
                } else {
                    printf("getop: illegal number %s\n", s);
                    return ERR_ILLEGAL_NUMBER;
                }
            }
            for(; k < n && isdigit(s[k]); k++);
            if (s[k] == '.') for(k++; k < n && isdigit(s[k]); k++); // allow for a single decimal point
            if (s[k] == '\0') {
            // if every char is digit, then it's a number
                return NUMBER;
            }
            else {
                printf("getop: illegal number %s\n", s);
                return ERR_ILLEGAL_NUMBER;
            }
        }
    }

}
