#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "calc.h"

int getop(char s[]) {
    int i, c;
    char cmd[CMDSIZE + 1]; // +1 to make room for terminator '\0'
    cmd[0] = '\0';
    int j = 0; // index of the command string array
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (c == '-') {
    // handle negative numbers or subtract operator
        c = getch();
        if (!isdigit(c) && c != '.') {
        // if it is an operator rather than a prefix
            if (c != EOF)
                ungetch(c);
            return '-';
        } else {
            s[0] = '-';
            s[1] = c;
            i = 1;
        }
    }
    else if (isalpha(c) || c == ANS) {
    // handle commands and variables
        if (c == ANS) return c; // if c is the last answer variable, return it immediately
        cmd[j++] = c;
        int exp_c = getch();
        if (!isalpha(exp_c)) {
        // then it might be a variable
            // reset command buffer
            cmd[0] = '\0';
            j = 0;
            // push back
            if(exp_c != EOF) ungetch(exp_c);
            s[0] = c >= 'a' && c <= 'z' ? c : c - 'A' + 'a'; // we only process lowercase variables internally
            s[1] = '\0';
            return VARIABLE;
        } else {
        // it is interpreted as command as we only prepare for single letter variables at this stage
            bool cmd_overflow = 0;
            cmd[j++] = exp_c;
            while (isalpha(c = getch())) {
            // extract commands of variable length
                if(j < CMDSIZE) cmd[j++] = c;
                else cmd_overflow = 1;
            }
            // overread is guaranteed, push back one
            if(c != EOF) ungetch(c);
            cmd[j] = '\0';
            // if command is too long, throw
            if(cmd_overflow) return ERR_ILLEGAL_COMMAND;
            if (strcmp(cmd, "SIN") == 0 || strcmp(cmd, "sin") == 0) {
                return SIN;
            } else if (strcmp(cmd, "EXP") == 0 || strcmp(cmd, "exp") == 0) {
                return EXP;
            } else if (strcmp(cmd, "COS") == 0 || strcmp(cmd, "cos") == 0) {
                return COS;
            } else if (strcmp(cmd, "TAN") == 0 || strcmp(cmd, "tan") == 0) {
                return TAN;
            } else if (strcmp(cmd, "POW") == 0 || strcmp(cmd, "pow") == 0) {
                return POW;
            } else if (strcmp(cmd, "EQA") == 0 || strcmp(cmd, "eqa") == 0) {
                return EQA;
            } else {
                printf("getop: illegal command\n");
                return ERR_ILLEGAL_COMMAND;
            }
        }
    }
    else if (!isdigit(c) && c != '.') {
    // the c is just an operator '+' '*' '/' or '%'
        return c;
    } else i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch())); // s[0] is already the first digit in this case, hence s[++i] used
    if (c == '.')
        while (isdigit(s[++i] = c = getch())); // s[i] is the decimal point, hence s[++i] used
    s[i] = '\0'; // if the last character is junk, this just overwrites it
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}
