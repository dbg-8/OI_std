#include <stdio.h>
#include <algorithm>

int n, h;
int l[200003], r[200003];
int sum[200003];
int ans = 0;

int main() {
	scanf("%d %d", &n, &h);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &l[i], &r[i]), sum[i] = sum[i - 1] + l[i] - r[i - 1];
	for (int i = 1; i <= n; i++) {
		int x = std:: lower_bound(sum + i + 1, sum + n + 1, sum[i] + h) - sum - 1;
		ans = std:: max(ans, h - sum[x] + sum[i] + r[x] - l[i] );
	}
	printf("%d\n", ans);
	return 0;
} 
