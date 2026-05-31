#include <stddef.h>
#include <assert.h>

size_t strlen(const char *s) {
    size_t i = 0;
    while(*s++ != '\0') i++;
    return i;
}

void strncpy(char *s, const char *t, size_t n) {
    size_t i;
    for (i = 0; i < n && t[i] != '\0'; i++) {
        s[i] = t[i];
    }
    while (i < n)
        s[i++] = '\0';
}

void strncat(char *s, const char *t, size_t n) {
    size_t i, j;
    for (i = strlen(s), j = 0; j < n && t[j] != '\0'; i++, j++) {
        s[i] = t[j];
    }
    s[i] = '\0';
}

int strncmp(const char *s, const char *t, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            return s[i] > t[i] ? 1 : -1;
        }
        if(s[i] == '\0') return 0;
    }
    return 0;
}
