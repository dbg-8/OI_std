#include <stdio.h>
#include <string.h>
#include <algorithm>

int n, m;
int a[3003];
int s[3003][3003];	// 村庄区间 [l,r] 中只有 1 个邮局时的最小距离 
int d[3003][303];	// 前 i 个村庄建设 j 个邮局时的最小距离 
int f[3003][303];	// 满足上一行注释中条件的第 j 个邮局位置 

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	memset(d, 0x3F, sizeof(d));
	std:: sort(a + 1, a + n + 1);
	for (int l = 1; l <= n; l++)	// 预处理 s 
		for (int r = l + 1; r <= n; r++) 
			s[l][r] = s[l][r - 1] + a[r] - a[(l + r) / 2];
	
	d[0][0] = 0; 
	for (int j = 1; j <= m; j++) {
		f[n + 1][j] = n;
		for (int i = n; i >= 1; i--) {	// 注意要倒过来 
			int minn = 0x3F3F3F3F, minp = 0;
			for (int k = f[i][j - 1]; k <= f[i + 1][j]; k++) 
				if (d[k][j - 1] + s[k + 1][i] < minn)
					minn = d[k][j - 1] + s[k + 1][i], minp = k;
			d[i][j] = minn;
			f[i][j] = minp;
		}
	}
	
	printf("%d\n", d[n][m]);
	return 0;
}
