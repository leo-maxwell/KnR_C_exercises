#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define ALLOCSIZE 1048576

static char *p = NULL;
static char *membuf = NULL;

char *alloc(size_t size) {
    if (!membuf) {
        membuf = malloc(ALLOCSIZE);
        if (!membuf) {
            fprintf(stderr, "error: out of memory\n");
            return NULL;
        }
        p = membuf;
    }
    size_t available = ALLOCSIZE - (p - membuf);
    if (available < size) {
        fprintf(stderr, "error: out of buffer\n");
        return NULL;
    } else {
        p += size;
        return p - size;
    }
}

void afree(char *fp) {
    if (fp >= membuf && fp < p) {
        p = fp;
    } else {
        printf("error: cannot free an invalid pointer\n");
    }
}

void destroy() {
    free(membuf);
    membuf = NULL;
    p = NULL;
}
