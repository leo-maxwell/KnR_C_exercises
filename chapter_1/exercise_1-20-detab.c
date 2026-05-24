#include <stdio.h>

#define TAB_SIZE 4

int main() {
	int c;
	int column = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			column = 0;
			putchar(c);
		}
		else if (c == '\t') {
			for (int i = 0; i < TAB_SIZE - (column % TAB_SIZE); i++) {
				putchar(' ');
				column++;
			}
		} else {
			putchar(c);
			column++;
		}
	}
	return 0;
}
