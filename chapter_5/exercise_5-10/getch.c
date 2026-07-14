#include <stdio.h>
#include "calc.h"

int buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(const char s[]) {
    int i;
    for(i = 0; s[i] != '\0'; i++);
    i--;
    while(bufp < BUFSIZE && i >= 0) buf[bufp++] = s[i--];
    if (bufp >= BUFSIZE && i >= 0)
        printf("ungets: too many characters\n");
}
