#include <stdio.h>

int getline_(char *lineptr, int maxlen) {
    int c;
    int linelen = 0;
    while(linelen < maxlen - 1 && (c = getchar()) != EOF) {
        linelen++;
        *lineptr++ = c;
        if(c == '\n') break;
    }
    *lineptr = '\0';
    return linelen;
}
