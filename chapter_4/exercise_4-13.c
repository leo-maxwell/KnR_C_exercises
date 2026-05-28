#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int n;
    int temp;
    n = strlen(s);
    if (n <= 1) {
        return;
    }
    temp = s[0];
    s[0] = s[n - 1];
    s[n - 1] = '\0';
    reverse(s + 1);
    s[n - 1] = temp;
}

int main(void) {
    char s[] = "hello world!";
    reverse(s);
    printf("%s\n", s);
    return 0;
}
