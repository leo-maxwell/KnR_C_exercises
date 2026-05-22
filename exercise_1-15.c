#include <stdio.h>

/* prints Fahrenheit-Celcius table */

float fahr2cel(float fahr);

int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	while (fahr <= upper) {
		printf("%3.0f\t%6.1f\n", fahr, fahr2cel(fahr));
		fahr = fahr + step;
	}
	return 0;
}

float fahr2cel(float fahr) {
    return 5.0 * (fahr-32.0) / 9.0;
}
