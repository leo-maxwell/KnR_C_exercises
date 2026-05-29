#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);

int getfloat(double *pn) {
    int c, sign;
    double fractional = 0.0, power = 1;

    // remove whitespace
    while(isspace(c = getch()));

    // bad number screening
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    if (c == '.') {
        int next_c = getch();
        if (!isdigit(next_c)) {
            if(next_c != EOF) ungetch(next_c);
            ungetch(c);
            return 0;
        } else {
            ungetch(next_c);
        }
    }

    // symbol parsing
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int next_c = getch();
        if (next_c == '.') {
        // if decimal follow sign
            int nnext_c = getch();
            if (!isdigit(nnext_c)) {
            // if no digit follows the sign, bad number
                if(nnext_c != EOF) ungetch(nnext_c);
                ungetch(next_c);
                ungetch(c);
                return 0;
            } else {
            // set current char to decimal point to enter the fractional part processing afterwards
                ungetch(nnext_c);
                c = '.';
            }
        }
        else if (!isdigit(next_c)) {
        // if no decimal follows the sign, then must be a digit, or bad number
            if(next_c != EOF) ungetch(next_c);
            ungetch(c);
            return 0;
        } else {
        // set current char to be the first digit to enter the integral part processing afterwards
            c = next_c;
        }
    }

    // number parsing
    *pn = 0; // in case of absence of integral part
    for(*pn = 0; isdigit(c); c = getch()) *pn = 10 * *pn + (c - '0');
    if (c == '.') {
        c = getch();
        for (fractional = 0.0; isdigit(c); c = getch()) {
            power *= 10;
            fractional = 10 * fractional + (c - '0');
        }
    }
    *pn += fractional / power;
    *pn *= sign;
    if(c != EOF) ungetch(c);
    return c;
}
