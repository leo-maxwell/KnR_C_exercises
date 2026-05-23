#include <stdio.h>

// very vulnerable to overflow, intended

void expand(char s1[], char s2[]) {
    int i = 0, j = 0;
    while(s1[i] != '\0') {
        if (s1[i] == '-') {
            if (i == 0 || s1[i+1] == '\0') {
            // handle the case where it is a starting / trailing dash
                s2[j++] = s1[i];
            } else {
            // actually expands (we only expand the missing parts denoted by the dash, without head and tail)
                int s = s1[i-1];
                int e = s1[i+1];
                if ((s >= 'a' && s <= 'z' && e >= 'a' && e <= 'z' && s <= e) ||
                    (s >= 'A' && s <= 'Z' && e >= 'A' && e <= 'Z' && s <= e) ||
                    (s >= '0' && s <= '9' && e >= '0' && e <= '9' && s <= e)) {
                    for (int c = s+1; c <= e-1; c++) {
                        s2[j++] = c;
                    }
                } else {
                // if an expansion is not possible, copy the dash as is
                    s2[j++] = s1[i];
                }
            }
        } else {
            s2[j++] = s1[i];
        }
        i++;
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "-a-zA-Z0-9a-b-ca-zA-Z-";
    char s2[1024];
    expand(s1, s2);
    printf("%s\n", s2);
}
