#include <stdio.h>

unsigned long long htoi(char s[]) {
    int i = 0;
    unsigned long long n = 0;
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
        i = 2;
    }
    for(; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = n*16 + (s[i] - '0');
        }
        if (s[i] >= 'a' && s[i] <= 'f') {
            n = n*16 + (s[i] - 'a' + 10);
        }
        if (s[i] >= 'A' && s[i] <= 'F') {
            n = n*16 + (s[i] - 'A' + 10);
        }
    }
    return n;
}

int main() {
    char test_hex[] = "0xdeadbeef";
    printf("%lld\n", htoi(test_hex));
    return 0;
}
