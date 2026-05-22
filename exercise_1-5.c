#include <stdio.h>

/* prints Fahrenheit-Celcius table */

int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = upper;

	while (fahr >= lower) {
		celsius = 5.0 * (fahr-32.0) / 9.0;
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr - step;
	}
	return 0;
}
