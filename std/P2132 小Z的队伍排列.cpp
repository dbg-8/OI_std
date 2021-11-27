#include <stdio.h>

int m;
int a[7];
int d[31][31][31][31][31];

int main() {
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	d[0][0][0][0][0] = 1;
	for (int i = 0; i <= a[1]; i++)
		for (int j = 0; j <= a[2]; j++)
			for (int k = 0; k <= a[3]; k++)
				for (int l = 0; l <= a[4]; l++)
					for (int p = 0; p <= a[5]; p++) {
						if (i > j)
							d[i][j][k][l][p] += d[i - 1][j][k][l][p];
						if (j > k)
							d[i][j][k][l][p] += d[i][j - 1][k][l][p];
						if (k > l)
							d[i][j][k][l][p] += d[i][j][k - 1][l][p];
						if (l > p)
							d[i][j][k][l][p] += d[i][j][k][l - 1][p];
						if (p > 0)
							d[i][j][k][l][p] += d[i][j][k][l][p - 1];
					}
	printf("%u\n", d[a[1]][a[2]][a[3]][a[4]][a[5]]);
	return 0;
} 
