#include <stdio.h>
#include <algorithm>

int n, m, q;
int x[10003], y[10003];
int low[10003], high[10003];	// 区间 [low[i],high[i]] 可以通过
bool iswall[10003]; 
int d[10003][1003]; 

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		low[i] = 1, high[i] = m;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			d[i][j] = 0x3F3F3F3F; 
	d[0][0] = 0x3F3F3F3F;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	for (int i = 1; i <= q; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		low[a] = b + 1;
		high[a] = c - 1;
		iswall[a] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) 
			if (j - x[i - 1] >= 0) {
				d[i][j] = std:: min(d[i][j], d[i - 1][j - x[i - 1]] + 1);
				d[i][j] = std:: min(d[i][j], d[i][j - x[i - 1]] + 1);
			}
		for (int k = m - x[i - 1]; k <= m; k++) {
			d[i][m] = std:: min(d[i][m], d[i - 1][k] + 1);
			d[i][m] = std:: min(d[i][m], d[i][k] + 1);
		}
		for (int j = low[i]; j <= high[i]; j++)
			if (j + y[i - 1] <= m)
				d[i][j] = std:: min(d[i][j], d[i - 1][j + y[i - 1]]); 
		for (int j = 1; j <= m; j++)
			if (!(low[i] <= j && j <= high[i]))
				d[i][j] = 0x3F3F3F3F;
	}
	int ans1 = 0, ans2 = 0x3F3F3F3F;
	for (int j = 1; j <= m; j++)
		if (d[n][j] < ans2)
			ans2 = d[n][j], ans1 = 1;
	if (ans1 == 0) {
		ans2 = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (d[i][j] != 0x3F3F3F3F && iswall[i]) {
					ans2++;
					break;
				}
	}
	printf("%d\n%d\n", ans1, ans2);
	return 0;
}
