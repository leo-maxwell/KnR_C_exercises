#include <stdio.h>

unsigned int bitcount(unsigned int x) {
    unsigned int b = 0;
    while(x != 0) {
        x &= (x-1);
        b++;
    }
    return b;
}

int main() {
    unsigned int x = 0b00000000000000001011010110100110;
    printf(bitcount(x) == 9 ? "passed\n" : "failed\n");
}
