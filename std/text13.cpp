#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 1000000
int main() {
	srand(time(NULL));
	int x = 0;
	double y = 0.0;
	for (register int i = 1; i <= N; i++)
		x += (rand() % 6 + 1);
	y = (double)x / N;
	printf("%llf\n", y);
	return 0;
}
