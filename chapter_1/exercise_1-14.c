#include <stdio.h>

#define MAX_WORDLEN 30

int main () {
	int c;
	short in = 0;
	long wordlen = 0, histogram[MAX_WORDLEN];
	for (int i = 0; i < MAX_WORDLEN; i++) {
		histogram[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') {
			if (in == 0) {
				in = 1;
				wordlen = 1;
			} else {
				wordlen++;
			}
		} else {
			in = 0;
			if (wordlen > 0 && wordlen < MAX_WORDLEN) {
				histogram[wordlen]++;
			}
		}
	}
	// the last word
	if (in == 1 && wordlen > 0) {
		histogram[wordlen]++;
	}
	printf("\n");	// to make output pretty, make a dedicated line from the input
	for (int i = 1; i < MAX_WORDLEN; i++) {
		long histo_len = histogram[i];
		printf("%d : ", i);
		for (int j = 0; j < histo_len; j++) {
			printf("-");
		}
		printf(" | %ld\n", histo_len);
	}
	return 0;
}
