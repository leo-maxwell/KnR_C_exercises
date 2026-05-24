#include <stdio.h>

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else
            return mid;
    }
    return -1;
}

int binsearch2(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n-1;
    while (low < high) {
        mid = (high + low) / 2;
        if (v[mid] < x) {
            low = mid + 1;
        } else
            high = mid;
    }
    if (v[low] == x) return low;
    return -1;
}

int main() {
    int v[] = {1, 3, 4, 6, 7, 9, 10, 13, 13, 13, 13, 17, 19, 23, 25};
    printf("%d\n", binsearch(13, v, 15));
    printf("%d\n", binsearch2(13, v, 15));
}
