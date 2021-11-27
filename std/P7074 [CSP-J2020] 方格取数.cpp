#include <stdio.h>
#include <algorithm>
#define ll long long
#define INF 10000000003

int n, m;
ll a[1030][1030];
ll d[1030][1030][2]; // 0: 从 i+1 到 i, 向上的 

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%lld", &a[i][j]);
	for (int i = 1; i <= m; i++)
		d[0][i][1] = -INF, d[n + 1][i][0] = -INF;
	for (int i = 2; i <= n; i++)
		d[i][0][0] = d[i][0][1] = -INF;
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++)
			d[i][j][0] = d[i][j][1] =
			 a[i][j] + std:: max(d[i][j - 1][0], d[i][j - 1][1]);
		for (int i = n; i >= 1; i--)
			d[i][j][0] = std:: max(d[i][j][0], a[i][j] + d[i + 1][j][0]);
		for (int i = 1; i <= n; i++)
			d[i][j][1] = std:: max(d[i][j][1], a[i][j] + d[i - 1][j][1]);
	}
	printf("%lld\n", std:: max(d[n][m][0], d[n][m][1]));
	return 0;
}
