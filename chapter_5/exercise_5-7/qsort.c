#include <string.h>

void swap_(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort_(char *v[], int left, int right) {
    int i, last;

    if (left >= right) return;
    swap_(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap_(v, ++last, i);
        }
    }
    swap_(v, left, last);
    qsort_(v, left, last-1);
    qsort_(v, last+1, right);
}
