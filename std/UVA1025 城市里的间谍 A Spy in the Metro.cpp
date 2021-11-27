#include <stdio.h>
#include <string.h>
#include <algorithm>

int n, m;
int c[53];
int m1, m2, a[53], b[53];
bool canlr[403][53][2];		// canlr [time][pos][left/right]
int d[403][53];				// d[time][pos]

inline void kagari (int t) {
	memset(canlr, false, sizeof(canlr));
	memset(d, 0x3F, sizeof(d));
	scanf("%d", &m);
	for (int i = 1; i < n; i++)
		scanf("%d", &c[i]);
	scanf("%d", &m1);
	for (int i = 1; i <= m1; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m2);
	for (int i = 1; i <= m2; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= m1; i++) {
		int cnt = a[i];
		for (int j = 1; j < n; j++) {
			canlr[cnt][j][1] = true;
			cnt += c[j];
		}
	}
	for (int i = 1; i <= m2; i++) {
		int cnt = b[i];
		for (int j = n; j > 1; j--) {
			canlr[cnt][j][0] = true;
			cnt += c[j - 1];
		}
	}
	d[0][1] = 0;
	for (int i = 0; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] != 0x3F3F3F3F) { 
				d[i + 1][j] = std:: min(d[i + 1][j], d[i][j] + 1);	// 留在原地
				if (canlr[i][j][1])	// 可以往右走 
					d[i + c[j]][j + 1] = std:: min(d[i + c[j]][j + 1], d[i][j]);
				if (canlr[i][j][0])	// 可以往左走
					d[i + c[j - 1]][j - 1] = std:: min(d[i + c[j - 1]][j - 1], d[i][j]);
			}
		}
	}
	printf("Case Number %d: ", t);
	if (d[m][n] == 0x3F3F3F3F)
		printf("impossible\n");
	else
		printf("%d\n", d[m][n]);
	return;
}

int main () {
	int t = 1;
	while (~scanf("%d", &n) && n)
		kagari(t++);
	return 0;
}
