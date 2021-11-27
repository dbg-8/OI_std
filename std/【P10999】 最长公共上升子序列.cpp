#include <stdio.h>
#include <algorithm>

int n;
int a[3003], b[3003];
int d[3003][3003];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j])
				d[i][j] = sum + 1;
			else
				d[i][j] = d[i - 1][j];
			if (a[i] > b[j])
				sum = std:: max(sum, d[i - 1][j]);
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = std:: max(ans, d[n][i]);
	printf("%d\n", ans);
	return 0;
}
