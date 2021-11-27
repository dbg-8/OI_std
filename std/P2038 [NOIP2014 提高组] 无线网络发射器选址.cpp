#include <stdio.h>
#include <algorithm>

int d, k, n = 128, m = 128;
int a[203][203];
int ans1 = 0, ans2 = 0;

int main() {
	scanf("%d %d", &d, &k);
	for (int i = 1; i <= k; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[x][y] = z;
	}
	for (register int i = 0; i <= n; i++) {
		for (register int j = 0; j <= m; j++) {
			register int sum = 0;
			for (register int x = std:: max(0, i - d); x <= std:: min(n, i + d); x++)
				for (register int y = std:: max(0, j - d); y <= std:: min(m, j + d); y++)
					sum += a[x][y];
			if (sum == ans2)
				ans1++;
			else if (sum > ans2) {
				ans2 = sum;
				ans1 = 1;
			}
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}
