#include <stdio.h>
#include <limits.h>

unsigned int rightrot(unsigned int x, int n) {
    unsigned int bitlen = sizeof(unsigned int) * CHAR_BIT;
    unsigned int rightmask = ~(~0u << n);
    unsigned int rtt_bits = x & rightmask;
    rtt_bits <<= bitlen - n;
    x = x >> n;
    return x | rtt_bits;
}

int main() {
    unsigned int x =       0b00000000000000001011010110100110;
    unsigned int final_x = 0b11000000000000000001011010110100;
    printf(rightrot(x, 3) == final_x ? "passed\n" : "failed\n");
}
