// O(2^n*m)
#include <stdio.h>
#define abs(x) ((x) > 0 ? (x) : -(x))

int n, m, r, c;
int a[23][23];
int b[23][23];
int c[23][23];
int pos[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
bool vis[23];

inline void sovle () {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (vis[i]) {
			cnt++;
			for (int j = 1; j <= m; j++)
				c[cnt][j] = a[i][j];
		}
	#define nx x + pos[i][0]
	#define ny y + pos[i][1]
	for (int x = 1; x <= r; y++)
		for (int y = 1; y <= c; y++) {
			b[x][y] = 0;
			for (int k = 0; k < 4; k++)
				b[x][y] += abs(c[nx][ny] - c[x][y]);
		}
	for (int i = 1; i <= n; i++)
		
	return;
}

inline void dfs (int x, int used) {
	if (x == n + 1)
		return;
	if (x == c) {
		sovle();
		return;
	}
	vis[x] = true;
	dfs(x + 1, used + 1);
	vis[x] = false;
	dfs(x + 1, used);
	return;
}

int main () {
	scanf("%d %d %d %d", &n, &m, &r, &c);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	dfs(1, 0);
	return 0;
}
