#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void my_strcat(char *s, const char *t) {
    while(*s != '\0') s++;
    while(*t != '\0') *s++ = *t++;
    *s = '\0';
}

int main(void) {
    char *s = malloc(sizeof(*s) * 1024);
    if(s == NULL) return 1;
    strcpy(s, "hello ");
    const char *t = "world!";
    my_strcat(s, t);
    printf("%s\n", s);
    free(s);
    return 0;
}
