#include <stdio.h>

int main () {
	float cel, fahr;
	int lower, upper, step;

	lower = 5;
	upper = 100;
	step = 5;

	cel = lower;

	while (cel <= upper) {
		printf("%3.0f\t%6.3f\n", cel, cel * 9.0 / 5.0 + 32.0);
		cel += step;
	}
	return 0;
}
