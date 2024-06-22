#include <stdio.h>

int
main(void) {
	int c, nl = 0, nb = 0, nt = 0;

	while((c = getchar()) != EOF) {
		if (c == '\n') {
			nl++;
		} else if (c == ' ') {
			nb++;
		} else if (c == '\t') {
			nt++;
		}
	}

	printf("number of blanks: %d\n", nb);
	printf("number of tabs: %d\n", nt);
	printf("number of newlines: %d\n", nl);

	return 0;
}
