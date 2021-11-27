#include <stdio.h>
#define M114514 19650827
int n;
int a[1003];
int d[1003][1003];	// 最后一个人从左边插入时区间[l,r]的方案个数 
int f[1003][1003];	// 最后一个人从右边插入时区间[l,r]的方案个数 

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), d[i][i] =  1;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			
			// 计算 d, 插入者为 l 
			if (a[l] < a[l + 1])	// 前一个插入者为 l + 1
				d[l][r] += d[l + 1][r];
			if (a[l] < a[r])	// 前一个插入者为 r
				d[l][r] += f[l + 1][r];
			d[l][r] %= M114514;
			
			// 计算 f, 插入者为 r 
			if (a[l] < a[r])	// 前一个插入者为 l
				f[l][r] += d[l][r - 1];
			if (a[r - 1] < a[r])	// 前一个插入者为 r - 1
				f[l][r] += f[l][r - 1];
			f[l][r] %= M114514;
		}
	}
	printf("%d\n", (d[1][n] + f[1][n]) % M114514);
	return 0;
} 
