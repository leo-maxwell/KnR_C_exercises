#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b) {
    int i = 0, sign;
    // make n positive, decide the sign
    sign = n < 0 ? -1 : 1;
    n *= sign;
    do {
        s[i++] = n % b < 10 ? n % b + '0' : n % b - 10 + 'A';
    } while ((n /= b) > 0);
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[1024];
    itob(INT_MAX, s, 16);
    printf("%s\n", s);
}
