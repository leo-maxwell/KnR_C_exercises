#include <stdio.h>

void append(char s[], int c) {
    int i = 0;
    while(s[i] != '\0') i++;
    s[i++] = c;
    s[i] = '\0';
}

void itoa_rcr(unsigned u, char *s) {
    if (u / 10)
        itoa_rcr(u / 10, s);
    append(s, (int)u % 10 + '0');
}

void itoa(int n, char s[]) {
    int i = 0;
    unsigned int u;
    if (n < 0) {
        s[i++] = '-';
        u = (unsigned int)(-(n + 1)) + 1;
    } else {
        u = (unsigned int)n;
    }
    s[i] = '\0';
    itoa_rcr(u, s);
}

int main(void) {
    char s[1024];
    itoa(12345, s);
    printf("%s\n", s);
    return 0;
}
