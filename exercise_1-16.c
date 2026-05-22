#include <stdio.h>

#define MAX_PRINT_LEN 1000


long get_line(char line[], long lim);
void copy(char to[], char from[]);

int main () {
	long len, max;
	char line[MAX_PRINT_LEN], longest[MAX_PRINT_LEN];
	
	max = 0;

	while ((len = get_line(line, MAX_PRINT_LEN)) != 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) {
		printf("%ld, %s\n", max, longest);
	}
	return 0;
}


long get_line(char s[], long lim) {
	long length = 0;
	long i = 0;
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (i < lim - 1) {
			s[i] = c;
			i++;
		}
		length++;
	}
	s[i] = '\0';
	return length;
}

void copy(char to[], char from[]) {
	long i = 0;
	while ((to[i] = from[i]) != '\0') i++;
}
