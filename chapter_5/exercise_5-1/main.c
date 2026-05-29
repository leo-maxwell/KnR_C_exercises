#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);

int getint(int *pn) {
    int c, sign;
    while(isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int next_c = getch();
        if (!isdigit(next_c)) {
            if(next_c != EOF) ungetch(next_c);
            ungetch(c);
            return 0;
        }
        c = next_c;
    }
    for(*pn = 0; isdigit(c); c = getch()) *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if(c != EOF) ungetch(c);
    return c;
}
