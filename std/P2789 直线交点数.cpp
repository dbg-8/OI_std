#include <stdio.h>

int d[30][30];

int main () {
	d[1][0] = d[1][1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i][i] = 0;
		for (int j = i - 1; j >= 0; j--)
		
	}
	int n;
	scanf("%d", &n);
	int ans = 1;
	for (int i = 2; i <= n; i++)
		ans += i;
	printf("%d\n", ans >> 1);
	return 0;
}
