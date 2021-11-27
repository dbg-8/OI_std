#include <stdio.h>

int main () {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n",(int)(0.2 * (double)a + 0.3 * (double)b + 0.5 * (double)c));
	return 0;
}
