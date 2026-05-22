#include <stdio.h>

#define TAB_SIZE 8

void entab(int column, int space_start);

int main() {
	int c;
	int column = -1;
	int space_start = -1;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
		    entab(column+1, space_start);
			column = -1;
			space_start = -1;
			putchar(c);
		}
		else if (c == ' ') {
			column++;
			if (space_start < 0) space_start = column;
		} else {
		    // when a normal character is met
			column++;
			entab(column, space_start);
			putchar(c);
			space_start = -1;
		}
	}
	entab(column+1, space_start);
	return 0;
}

void entab(int column, int space_start) {
    int spaces, tabs;
	if (space_start >= 0) {
	// if it is indeed preceeded with at least one space
	    int far_stop = (space_start / TAB_SIZE + 1) * TAB_SIZE; // get farthest last tab stop
		int last_stop = column - (column % TAB_SIZE); // get nearest last tab stop
		tabs = last_stop >= far_stop ? (last_stop - far_stop) / TAB_SIZE + 1 : 0;
		spaces = tabs ? column - last_stop : column - space_start;
		// printf("%d %d\n", tabs, spaces);
		while (tabs-- > 0) {
			putchar('\t');
		}
		while (spaces-- > 0) {
			putchar(' ');
		}
	}
}
