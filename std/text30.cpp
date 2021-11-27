#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main () {
	long s1 = clock();
	for (register int i = 1; i <= 1e8; i++)
		printf("");
	int t = 20;
	while (t--) {
		srand(clock());
		for (int i = 1; i <= 1000000; i++)
			;
		for (int i = 1; i <= 25; i++)
			printf("%d%c", rand(), i == 25 ? '\n' : ' ');
	}
	long s2 = clock();
	printf("%d\n", s2 - s1);
	return 0;
}
