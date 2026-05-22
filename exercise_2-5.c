#include <stdio.h>

int any(char s1[], char s2[]) {
    int i = 0, k = 0;
    while (s1[i] != '\0') {
        k = 0;
        while (s2[k++] != '\0') {
            if (s1[i] == s2[k]) {
                return i;
            }
        }
        i++;
    }
    return -1;
}

int main() {
    char s1[] = "Hello World!";
    char s2[] = "/.,;'[]!";
    printf("%d\n", any(s1, s2));
}
