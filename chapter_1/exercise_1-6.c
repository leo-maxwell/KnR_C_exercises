#include <stdio.h>

int main() {
	int c;
	while((c = getchar()) != EOF)
		printf("%d\n", c != EOF);
	printf("%d\n", c != EOF);
	return 0;
}
