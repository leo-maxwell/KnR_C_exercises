#include <stdio.h>

int invert(int x, int p, int n) {
    int r = p-n+1;
    int mask = ~(~0u << n) << r;
    return x ^ mask;
}

int main() {
    int test_x = 0b1011010110100110;
    printf(invert(test_x, 9, 4) == 0b1011011001100110 ? "passed\n" : "failed\n");
}
