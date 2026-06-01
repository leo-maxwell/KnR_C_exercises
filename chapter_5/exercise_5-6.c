#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

long getline_(char *s, long lim) {
	long length = 0;
	long i = 0;
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (i < lim - 1) {
			*s++ = c;
			i++;
		}
		length++;
	}
	*s = '\0';
	return length;
}

void reverse_(char *s) {
    size_t n = strlen(s);
    char temp;
    for (int i = 0; i < n/2; i++) {
        temp = *(s + i);
        *(s + i) = *(s + n - 1 - i);
        *(s + n - 1 - i) = temp;
    }
}

void itoa_(int n, char *s) {
    int sign = 1;
    char *start = s;
    unsigned int u;
    // make n positive and within bound, decide the sign
    if (n < 0) {
        sign = -1;
        u = (unsigned int)(-(n + 1)) + 1;
    } else u = (unsigned int)n;
    do {
        *s++ = u % 10 + '0';
    } while ((u /= 10) > 0);
    if (sign < 0) *s++ = '-';
    *s = '\0';
    reverse_(start);
}

int atoi_(const char *s) {
    int n = 0;
    int sign = 1;

    while(isspace(*s)) s++;

    if (*s == '-' || *s == '+') {
        sign = *s == '-' ? -1 : 1;
        s++;
    }

    while (isdigit(*s)) {
        n = n*10 + (*s - '0');
        s++;
    }

    return n * sign;
}

int strindex_(char *s, char *t) {
    int i, j, k = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
