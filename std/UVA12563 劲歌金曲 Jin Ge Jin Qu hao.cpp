#include <stdio.h>
#include <string.h> 
#include <algorithm>

int n, m, mm;
int a[53];
int d[1000003];

inline void kagari (int t) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		d[i] = -0x3F3F3F3F;
	d[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = m - 1; j >= a[i]; j--)
			d[j] = std:: max(d[j], d[j - a[i]] + 1);
	int ans1 = 0, ans2 = 0;
	for (int j = 0; j < m; j++)
		if (d[j] >= ans1)
			ans1 = d[j], ans2 = std:: max(ans2, j + 678);
	printf("Case %d: %d %d\n", t, ans1 + 1, ans2);
}

int main () {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
		kagari(i);
	return 0;
}
