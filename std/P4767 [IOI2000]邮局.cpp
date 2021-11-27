#include <stdio.h>
#include <string.h>
#include <algorithm>

int n, m;
int a[3003];
int s[3003][3003];	// ��ׯ���� [l,r] ��ֻ�� 1 ���ʾ�ʱ����С���� 
int d[3003][303];	// ǰ i ����ׯ���� j ���ʾ�ʱ����С���� 
int f[3003][303];	// ������һ��ע���������ĵ� j ���ʾ�λ�� 

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	memset(d, 0x3F, sizeof(d));
	std:: sort(a + 1, a + n + 1);
	for (int l = 1; l <= n; l++)	// Ԥ���� s 
		for (int r = l + 1; r <= n; r++) 
			s[l][r] = s[l][r - 1] + a[r] - a[(l + r) / 2];
	
	d[0][0] = 0; 
	for (int j = 1; j <= m; j++) {
		f[n + 1][j] = n;
		for (int i = n; i >= 1; i--) {	// ע��Ҫ������ 
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
