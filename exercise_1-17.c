#include <stdio.h>

#define LEN_CAP 80
#define LINE_CAP 100


long get_line(char line[], long lim);
void copy(char to[], char from[]);

int main () {
	long len, line_no;
	char line[LINE_CAP], lines[LINE_CAP][LEN_CAP+1];
	
	line_no = 0;

	while ((len = get_line(line, LINE_CAP)) != 0) {
		if (len > LEN_CAP && line_no < LINE_CAP) {
			copy(lines[line_no++], line);
		}
	}
	if (line_no > 0) {
		int i = 0;
		while (i < line_no) {
			printf("%s\n", lines[i]);
			i++;
		}
	}
	return 0;
}


long get_line(char s[], long lim) {
	long length = 0;
	long i = 0;
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (i < lim - 1) {
			s[i] = c;
			i++;
		}
		length++;
	}
	s[i] = '\0';
	return length;
}

void copy(char to[], char from[]) {
	long i = 0;
	while ((to[i] = from[i]) != '\0') i++;
}
