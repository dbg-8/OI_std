#include <stdio.h>
#define ans d[m][m]
int n, m;
int c[103][103];
int d[103][103];
int pos[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

inline void dfs (int x, int y, int co, bool cu2) {
	for (int i = 0; i < 4; i++) {
		int nx = x + pos[i][0], ny = y + pos[i][1];
		if (!(nx >= 1 && nx <= m && ny >= 1 && ny <= m))
			continue;
		if (c[nx][ny] == 0 && cu2 && d[x][y] + 2 < d[nx][ny] && d[x][y] + 2 < ans) {
			d[nx][ny] = d[x][y] + 2;
			dfs(nx, ny, co ,false);
		}
		if (c[nx][ny] && c[nx][ny] != co && d[x][y] + 1 < d[nx][ny] && d[x][y] + 1 < ans) {
			d[nx][ny] = d[x][y] + 1;
			dfs(nx, ny, c[nx][ny] ,true);
		}
		if (c[nx][ny] == co && d[x][y] < d[nx][ny]) {
			d[nx][ny] = d[x][y];
			dfs(nx, ny, co ,true);
		}
	}
	return;
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] = 0x3F3F3F3F;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		c[x][y] = z + 1;
	}
	d[1][1] = 0;
	dfs(1, 1, c[1][1], true);
	printf("%d\n", ans == 0x3F3F3F3F ? -1 : ans);
	return 0;
}
