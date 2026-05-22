#include <stdio.h>

#define MAX_LINE_LEN 1000

char line[MAX_LINE_LEN];

int main() {
	int c;
	int count = 0;
	while (count < MAX_LINE_LEN - 1 && (c = getchar()) != EOF) {
		if (c != '\n') {
			line[count++] = c;
		} else {
			line[count] = '\0';
			count = 0;
			printf("%s\n", line);
		}
	}
	if (count) printf("%s\n", line);
	return 0;
}
