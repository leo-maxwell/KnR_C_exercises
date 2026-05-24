#include <stdio.h>
#include <stdbool.h>

void squeeze(char s1[], char s2[]) {
    int i = 0, j = 0, k = 0;
    bool has;
    while (s1[i] != '\0') {
        k = 0;
        has = false;
        while (s2[k++] != '\0') {
            if (s1[i] == s2[k]) {
                has = true;
                break;
            }
        }
        if (!has) {
            s1[j++] = s1[i];
        }
        i++;
    }
    s1[j] = '\0';
}

int main() {
    char s1[] = "Hello World!";
    char s2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    squeeze(s1, s2);
    printf("%s\n", s1);
}
