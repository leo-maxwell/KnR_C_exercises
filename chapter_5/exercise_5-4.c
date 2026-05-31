#include <assert.h>
#include <stdlib.h>
#include <string.h>

int strend(const char *s, const char *t) {
    size_t ns = strlen(s), nt = strlen(t);
    if(nt > ns) return 0;
    for (int i = ns - 1, j = nt - 1; j >= 0; i--, j--) {
        if(s[i] != t[j]) return 0;
    }
    return 1;
}

int main() {
    char *s = malloc(sizeof(*s) * 512);
    char *t = malloc(sizeof(*t) * 512);
    char *u = malloc(sizeof(*u) * 512);
    strcpy(s, "hello world");
    strcpy(t, "world");
    strcpy(u, "hello");
    assert(strend(s, t) == 1);
    assert(strend(s, u) == 0);
    free(s);
    free(t);
    free(u);
    return 0;
}
