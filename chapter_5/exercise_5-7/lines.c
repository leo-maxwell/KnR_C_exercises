#include <stddef.h>
#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

char *alloc(size_t);
void afree(char *);
int getline_(char *, int);

int readlines2(char *lineptr[], int maxlines) {
    int len, nlines;
    char line[MAXLEN];
    nlines = 0;

    while ((len = getline_(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || lineptr[nlines] == NULL) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(lineptr[nlines++], line);
        }
    }
    return nlines;
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p;
    char line[MAXLEN];
    nlines = 0;

    while ((len = getline_(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len + 1)) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    for(int i = 0; i < nlines; i++) printf("%s\n", lineptr[i]);
}
