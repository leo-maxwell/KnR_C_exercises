#include <stdio.h>

// very vulnerable to overflow, intentional

void escape(char s[], char t[]) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }
    t[j] = '\0';
}

void escape_rev(char s[], char t[]) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '\\':
                if (s[i+1] != '\0') {
                    switch (s[i+1]) {
                        case 'n':
                            t[j++] = '\n';
                            i++;
                            break;
                        case 't':
                            t[j++] = '\t';
                            break;
                            i++;
                        default:
                            t[j++] = s[i];
                            break;
                    }
                }
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }
    t[j] = '\0';
}
