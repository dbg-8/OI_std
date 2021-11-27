/*
n 个派, m 个奶牛
f[l][r][i] 表示第 i 个派尚未被吃时能吃掉它和能吃掉派区间 [l,r] 的奶牛(们)的最大体重 
d[l][r] 表示派 [l,r] 全被吃掉后最大的奶牛总体重 

对于每一个 f[l][r][i], 派 i 只能是位于区间最左/右边的(因为要吃就必须把 [l,r] 全吃掉), 于是可得出:
f[l][r][i] = max(f[l+1][r][i], f[l][r+1][i]), l <= i <= r

分类讨论每一个 d[l][r] 的取值情况 
1. d[l][r] 可以由两个子区间合并而成 d[l][r] = d[l][k] + d[k+1][r], 其中 l<=k<r, 
2. d[l][r] 可以由一块没有被吃过的派和剩余区间组成 d[l][r] = f[l][r][k] + d[l][k - 1] + d[k + 1][l], 其中 l<=k<=r 
*/

#include <stdio.h>
#include <algorithm>

int n, m;
int f[303][303][303];
int d[303][303];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) { 
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z); 
		for (int j = y; j <= z; j++)
			f[y][z][j] = x;
	}
	for (int len = 1; len <= n; len++)
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			for (int k = l; k <= r; k++)
				f[l][r][k] = std:: max(f[l][r][k], f[l][r - 1][k]),
				f[l][r][k] = std:: max(f[l][r][k], f[l + 1][r][k]);
		}
	for (int len = 1; len <= n; len++)
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			// 1. 两个子区间合并而成 
			for (int k = l; k < r; k++)
				d[l][r] = std:: max(d[l][r], d[l][k] + d[k + 1][r]);
			// 2. 一个未吃过的派 k 与剩余部分组成 
			for (int k = l; k <= r; k++) 
				d[l][r] = std:: max(d[l][r], d[l][k - 1] + f[l][r][k] + d[k + 1][r]);
		}
	printf("%d\n", d[1][n]);
	return 0;
}
