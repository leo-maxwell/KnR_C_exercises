#include <stdio.h>

int main() {
    int i = 0;
    int lim = 1024;
    int c;
    int s[lim];
    while(i < lim - 1) {
        if ((c = getchar()) != '\n') {
            if (c != EOF) {
                s[i++] = c;
            }
        }
    }
}
