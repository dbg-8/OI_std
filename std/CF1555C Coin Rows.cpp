#include <stdio.h>
#include <algorithm>

int n;
int a[4][100003];

inline void sovle () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[1][i]), a[1][i] += a[1][i - 1];
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[2][i]), a[2][i] += a[2][i - 1];
	int ans = 0x3F3F3F3F;
	for (int i = 1; i <= n; i++)
		ans = std:: min(ans, std:: max(a[2][i - 1], a[1][n] - a[1][i]));
	printf("%d\n", ans);
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) 
		sovle();
	return 0;
} 
