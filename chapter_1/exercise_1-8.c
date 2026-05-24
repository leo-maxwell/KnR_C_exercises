#include <stdio.h>

int main () {
	long nc = 0;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') nc++;		
	}
	printf("%ld\n", nc);
	return 0;
}
