#include <stdio.h>
#include <iostream>

int m, n;
int a[103][103];
int last[103][103];
int d[103][103];

inline void print2 (int x, int y) {
	if (y > n)
		return;
	printf("%d ", x);
	print2(last[x][y], y + 1);
}

inline void kagari () {
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]),
			d[i][j] = ( j == n ? a[i][j] :0x3F3F3F3F); 
	for (int j = n - 1; j >= 1; j--)
		for (int i = 1; i <= m; i++) {
			int pos[3] = {i - 1, i, i + 1};
			if (i == 1)	pos[0] = 1, pos[1] = 2, pos[2] = m;
			if (i == m)	pos[0] = 1, pos[1] = m - 1, pos[2] = m;
			#define nx pos[k]
			#define ny j + 1
			for (int k = 0; k < 3; k++)
				if (d[nx][ny] + a[i][j] < d[i][j]) {
					d[i][j] = d[nx][ny] + a[i][j];
					last[i][j] = nx;
				}
		}
	int ans1 = 0x3F3F3F3F, st;
	for (int i = 1; i <= m; i++)
		if (d[i][1] < ans1)
			ans1 = d[i][1], st = i;
	print2(st, 1);
	printf("\n%d\n", ans1);
} 

int main () {
	while (std:: cin >> m >> n) 
		kagari();
	return 0;
}
