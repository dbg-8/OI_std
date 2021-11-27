#include <stdio.h>
#define ll long long

int n, m, p;
int a[200003], b[200003];
int hk[200003];		// 往右看(含)最近的可以去的 hiko 店 
int sc[200003][53];		// sc[i]: i 右侧 (含) 共有多少颜色为 j 的旅馆 
ll ans = 0;

int main () {
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i], &b[i]);
	for (int i = n; i >= 1; i--)
		for (int j = 0; j < m; j++)
			sc[i][j] = sc[i + 1][j] + (a[i] == j ? 1 : 0);
	hk[n + 1] = -1;
	for (int i = n; i >= 1; i--)
		if (b[i] <= p)	hk[i] = i;
		else			hk[i] = hk[i + 1];
	for (int co = 0; co < m; co++) {
		for (int i = 1; i <= n; i++)
			if (a[i] == co) {
				if (hk[i] == -1)
					continue;
				ans += sc[hk[i]][co];
				if (hk[i] == i)
					ans--;
			}
	}
	printf("%lld\n", ans);
	return 0;
}
