#include <limits.h>
#include <stdio.h>

int main () {
    char c = 0;
    unsigned char uc = 0;
    short s = 0;
    unsigned short us = 0;
    int i = 0;
    unsigned int ui = 0;
    long l = 0;
    unsigned long ul = 0;
    while((unsigned char)(uc + 1) > uc) uc++;
    while((unsigned short)(us + 1) > us) us++;

    unsigned int addendum = (int)us;
    while(1) {
        if (ui + addendum > ui) ui += addendum;
        else if (addendum <= 1) break;
        else addendum/=2;
        // printf("%d\n", addendum);
    }

    unsigned long ul_addendum = (unsigned long)ui*us;
    while(1) {
        if (ul + ul_addendum > ul) ul += ul_addendum;
        else if (ul_addendum <= 1) break;
        else ul_addendum/=2;
        // printf("%ld+%ld\n", ul, ul_addendum);
    }

    printf("upper limit of char: %d, actual: %d\n", uc/2, CHAR_MAX);
    printf("upper limit of short: %d, actual: %d\n", us/2, SHRT_MAX);
    printf("upper limit of int: %d, actual: %d\n", ui/2, INT_MAX);
    printf("upper limit of long: %ld, actual: %ld\n", ul/2, LONG_MAX);

    printf("lower limit of char: %d, actual: %d\n", -uc/2-1, CHAR_MIN);
    printf("lower limit of short: %d, actual: %d\n", -us/2-1, SHRT_MIN);
    printf("lower limit of int: %d, actual: %d\n", -(ui/2)-1, INT_MIN);
    printf("lower limit of long: %ld, actual: %ld\n", -(ul/2)-1, LONG_MIN);
}
