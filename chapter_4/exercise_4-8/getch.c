#include <stdio.h>
#include "calc.h"

int buf = EOF;

int getch(void) {
    if (buf != EOF) {
        int ans = buf;
        buf = EOF;
        return ans;
    } else {
        return getchar();
    }
}

void ungetch(int c) {
    if (c == EOF)
        return;
    else if (buf == EOF)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}
