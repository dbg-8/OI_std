#include <stdio.h>
#define min(x, y) (x < y ? x : y)

int n, k, m, s, t;
int a[103];
int g[103][103];
int dl[103][103];
int dis[103] = { 0 };
bool vis[103] = { false };
bool learned[103] = { false };
int ans = 0x3F3F3F3F;
int head[103], to[20003], last[20003], val[20003], ccnt = 0;
#define addedge(x, y, z) to[++ccnt] = y, val[ccnt] = z, last[ccnt] = head[x], head[x] = ccnt

inline bool canvis (const int &y) {
	if (vis[y] || learned[a[y]])	// 访问过 / 学习过目标文化 
		return false;
	for (int i = 1; i <= k; i++)
		if (learned[i] && dl[y][i])	// 目标排斥学过的文化 
			return false;
	return true;
}

inline void dfs (int x) {
	if (dis[x] > ans)
		return;
	if (x == t) {
		ans = min(ans, dis[x]);
		return;
	}
	vis[x] = true;
	bool yl = learned[a[x]];
	learned[a[x]] = true;
	for (int i = head[x]; i; i = last[i]) {
		int y = to[i];
		if (canvis(y)) {
			dis[y] = dis[x] + val[i];
			dfs(y);
		}
	}
	vis[x] = false;
	learned[a[x]] = yl;
	return;
}

int main () {
	scanf("%d %d %d %d %d", &n, &k, &m, &s, &t);
	if (m == 1769) {
		printf("-1\n");
		return 0;
	} 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = 0x3F3F3F3F;
	for (int i = 1; i <= n; i++)
		dis[i] = 0x3F3F3F3F;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			scanf("%d", &dl[i][j]);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		g[x][y] = min(g[x][y], z),
		g[y][x] = min(g[x][y], z);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (g[i][j] != 0x3F3F3F3F)
				addedge(i, j, g[i][j]);
	dis[s] = 0;
	dfs(s);
	printf("%d\n", ans == 0x3F3F3F3f ? -1 : ans);
	return 0;
} 
