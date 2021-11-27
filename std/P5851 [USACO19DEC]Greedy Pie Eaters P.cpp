/*
n ����, m ����ţ
f[l][r][i] ��ʾ�� i ������δ����ʱ�ܳԵ������ܳԵ������� [l,r] ����ţ(��)��������� 
d[l][r] ��ʾ�� [l,r] ȫ���Ե���������ţ������ 

����ÿһ�� f[l][r][i], �� i ֻ����λ����������/�ұߵ�(��ΪҪ�Ծͱ���� [l,r] ȫ�Ե�), ���ǿɵó�:
f[l][r][i] = max(f[l+1][r][i], f[l][r+1][i]), l <= i <= r

��������ÿһ�� d[l][r] ��ȡֵ��� 
1. d[l][r] ����������������ϲ����� d[l][r] = d[l][k] + d[k+1][r], ���� l<=k<r, 
2. d[l][r] ������һ��û�б��Թ����ɺ�ʣ��������� d[l][r] = f[l][r][k] + d[l][k - 1] + d[k + 1][l], ���� l<=k<=r 
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
			// 1. ����������ϲ����� 
			for (int k = l; k < r; k++)
				d[l][r] = std:: max(d[l][r], d[l][k] + d[k + 1][r]);
			// 2. һ��δ�Թ����� k ��ʣ�ಿ����� 
			for (int k = l; k <= r; k++) 
				d[l][r] = std:: max(d[l][r], d[l][k - 1] + f[l][r][k] + d[k + 1][r]);
		}
	printf("%d\n", d[1][n]);
	return 0;
}
