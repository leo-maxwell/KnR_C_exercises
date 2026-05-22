#include <stdio.h>

int main () {
	short blflag = 0;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (blflag) {
				;
			} else {
				blflag = 1;
				putchar(c);
			}
		} else {
			blflag = 0;
			putchar(c);
		}		
	}
	return 0;
}
