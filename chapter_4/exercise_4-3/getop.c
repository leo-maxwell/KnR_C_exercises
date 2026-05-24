#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; // not a number, may be an operator
    i = 0;
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
