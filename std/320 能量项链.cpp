#include <stdio.h>
#include <algorithm>
#define r l + len - 1

int n;
int a[203];
int d[203][203];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), a[n + i] = a[i];
	for (int len = 3; len <= n * 2; len++)
		for (int l = 1; r <= 2 * n; l++) 
			for (int i = l + 1; i < r; i++)
				d[l][r] = std:: max(d[l][r], d[l][i] + a[l] * a[i] * a[r] + d[i][r]);
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = std:: max(ans, d[i][i + n]);
	printf("%d\n", ans);
	return 0;
}
