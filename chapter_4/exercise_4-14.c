#define swap(t,x,y) do {t __mytmp__; __mytmp__  = x; x = y; y = __mytmp__;} while(0)

#include <stdio.h>

int main(void) {
    size_t x = 42;
    size_t y = 24;
    swap(size_t, x, y);
    printf("x = %zu, y = %zu\n", x, y);
    return 0;
}
