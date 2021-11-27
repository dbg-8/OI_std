/*
もぺもぺ！！ 
先生买一朵小蓝花吗? 你看她多可爱啊!

 
n 个花, m 种花瓶 
d i j    表示前 i 种花放在前第 j 个花瓶中, 
且第 i 种花放在第 j 个花瓶中时的最大美化值 
d[i][j] = max(d[i][j], d[i-1][k] + a[i][j]), 
	其中 i∈[2,n], j∈[i,m-n+i], k∈[i-1,j-1] 
	同时可以发现 k 基本∈j, 所以无需枚举 k 
初始化 d[1][i] = a[1][i], 其中 i∈[1,m]
ans = max(d[n][i]), 其中 i∈[n, m] 

你妈的, ∈怎么没有半角 
*/
#include <stdio.h> 
#define ll long long

int n, m;
ll a[103][103];		// Power 值 
ll d[103][103];		// ヂーピー用, 详细信息见上 
int history[103][103];	// 表示第 i 朵花放在花瓶 j 使得 d[i][j] 最大时第 i-1 朵花所放位置 
int ans2[103];

int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%lld", &a[i][j]);
	for (int i = 1; i <= m; i++)
		d[1][i] = a[1][i];
	for (int i = 2; i <= n; i++) {
		ll k = -0x7FFFFFFF;
		int pos;
		for (int j = i; j <= m - n + i; j++) {
			if (k < d[i - 1][j - 1]) {
				k = d[i - 1][j - 1];
				pos = j - 1;
			}
			d[i][j] = k + a[i][j];
			history[i][j] = pos;
		}
	}
	ll ans = -0x7FFFFFFF;
	int pos = n;
	for (int i = n; i <= m; i++) {
		if (d[n][i] > ans) {
			ans = d[n][i];
			pos = i;
		}
	}
	printf("%lld\n", ans);
	for (int i = n; i >= 1; i--) {
		ans2[i] = pos;
		pos = history[i][pos];
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans2[i]);
	printf("\n");
	return 0;
}
