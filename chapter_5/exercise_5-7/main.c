#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINES 5000
#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines);
int readlines2(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort_(char *v[], int left, int right);
void destroy();

static long long ns_diff(struct timespec a, struct timespec b)
{
    return (b.tv_sec - a.tv_sec) * 1000000000LL
         + (b.tv_nsec - a.tv_nsec);
}

int main1() {
    char *lineptr[MAXLINES];
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort_(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        destroy();
        return 0;
    } else {
        fprintf(stderr, "error: too many or too few lines\n");
        destroy();
        return -1;
    }
}

int main2() {
    char *lineptr[MAXLINES];
    for (int i = 0; i < MAXLINES; i++) {
        lineptr[i] = malloc(sizeof(*lineptr[i]) * MAXLEN);
    }
    int nlines;
    if ((nlines = readlines2(lineptr, MAXLINES)) >= 0) {
        qsort_(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        for (int i = 0; i < MAXLINES; i++) {
            free(lineptr[i]);
        }
        return 0;
    } else {
        fprintf(stderr, "error: too many or too few lines\n");
        for (int i = 0; i < MAXLINES; i++) {
            free(lineptr[i]);
        }
        return -1;
    }
}

int main(void)
{
    struct timespec start, end;
    long long t1, t2;

    clock_gettime(CLOCK_MONOTONIC, &start);
    main1();
    clock_gettime(CLOCK_MONOTONIC, &end);
    t1 = ns_diff(start, end);

    rewind(stdin);

    clock_gettime(CLOCK_MONOTONIC, &start);
    main2();
    clock_gettime(CLOCK_MONOTONIC, &end);
    t2 = ns_diff(start, end);

    fprintf(stderr, "main1: %lld ns\n", t1);
    fprintf(stderr, "main2: %lld ns\n", t2);

    return 0;
}
