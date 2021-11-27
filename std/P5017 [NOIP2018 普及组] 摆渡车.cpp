#include <stdio.h>
#include <algorithm>
#define min(x, y) (x < y ? x : y) 

int n, m, cnt = 0;
int a[503];
int b[503];
int s[503][503];	// 第 i 人与 第 j 人的时间差 
int d[503][503];
int ans = 0x3F3F3F3F;

int dfs (int ci, int cj, int lcu, int sc) {	// 前 i 人, 前 j 人送走了, 下次能用车时间为 lcu 
	if (ci > cnt)
		return 0;
//	if (d[ci][cj] < sc)
//		return d[ci][cj];
	#define nt b[ci]	// 当前时间 
	int score = 0;
	for (int i = cj + 1; i <= ci; i++)
		score += s[i][ci];
	// 送 
	if (nt >= lcu) {
		int re = dfs(ci + 1, ci, nt + m, d[ci][cj] + score);
		d[ci][cj] = min(d[ci][cj], re);
	}
	// 不送
	int re = dfs(ci + 1, cj, lcu, d[ci][cj]);
	d[ci][cj] = min(d[ci][cj], re);
	return d[ci][cj];
}

int main () {
	scanf("%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	std:: sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		if (a[i] != a[i - 1])
			b[++cnt] = a[i];
	for (int i = 1; i <= cnt; i++)
		for (int j = i + 1; j <= cnt; j++)
			s[i][j] = b[j] - b[i];
	for (int i = 1; i <= cnt; i++)
		for (int j = 1; j <= cnt; j++)
			d[i][j] = 0x3F3F3F3F;
	dfs(1, 0, 1, 0);
	for (int i = 1; i <= n; i++)
		printf("%d\n", d[cnt][i]);
	printf("%d\n", d[cnt][cnt]);
	return 0;
}
