#include <stdio.h>

int setbits(int x, int p, int n, int y) {
    int r = p-n+1;
    int mask = ~0u << (p+1) | ~(~0u << r);
    int cleared_x = x & mask;
    int aligned_y = (y & ~(~0u << n)) << r;
    return aligned_y | cleared_x;
}

int main() {
    int test_x = 0b10110011;
    int test_y = 0b01001010;
    printf(setbits(test_x, 5, 3, test_y) == 0b10010011 ? "passed\n" : "failed\n");
}
