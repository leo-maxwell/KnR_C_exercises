#include <limits.h>
#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[], int min_width) {
    int i = 0, sign, min_flag = 0;
    // make n positive and within bound, decide the sign
    if (n == INT_MIN) {
        n = INT_MAX;
        min_flag = 1;
        sign = -1;
    } else {
        sign = n < 0 ? -1 : 1;
        n *= sign;
    }
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (min_flag) s[0] += 1; // the last digit cannot be 9 as it is not dividable by 2
    if (sign < 0) s[i++] = '-';
    while (i < min_width - 1) s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[1024];
    itoa(INT_MIN, s, 16);
    printf("%d\n", INT_MIN);
    printf("%s\n", s);
}
