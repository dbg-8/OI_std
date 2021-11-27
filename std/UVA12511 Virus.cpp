#include <stdio.h>
#include <string.h>
#include <algorithm>

int n, m;
int a[1003], b[1003];
int d[1003][1003];

inline void sovle() {
	memset(d, 0, sizeof(d));
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	a[0] = b[0] = -9;
	for (int i = 1; i <= m; i++) {
		int k = 0;
		for (int j = 1; j <= n; j++) {
			d[i][j] = d[i - 1][j];
			if (a[i] == b[j]) 
				d[i][j] = k + 1;
			if (a[i] > b[j])
				k = std:: max(k, d[i - 1][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = std:: max(ans, d[m][i]);
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		sovle();
	return 0;
}
