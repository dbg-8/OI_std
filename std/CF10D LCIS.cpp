#include <stdio.h>

int n, m;
int a[503], b[503];
int d[503][503];
int h[503][503];
int ans2[503];

int main() {
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	a[0] = b[0] = -9;
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) 
			if (a[i] == b[j]) {
				for (int k = 0; k < j; k++)
					if (b[j] > b[k] && d[i][j] < d[i - 1][k] + 1)
						d[i][j] = d[i - 1][k] + 1,
						h[i][j] = k;
			}
			else {
				d[i][j] = d[i - 1][j];
				h[i][j] = h[i - 1][j]; 
			}
	int ans = 0, p;
	for (int i = 1; i <= n; i++)
		if (d[m][i] > ans) {
			ans = d[m][i];
			p = i;
		}
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++) {
		ans2[i] = b[p];
		p = h[m][p];
	}
	for (int i = ans; i >= 1; i--)
		printf("%d ", ans2[i]);
	printf("\n");
	return 0;
}
