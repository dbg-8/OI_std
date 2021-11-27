#include <stdio.h>

int n, m;
int lg[300003]; 
int x[300003], y[300003], z[300003];
int head[300003], to[600003], last[600003], val[600003], ccnt = 0;
#define addedge(x, y, z) to[++ccnt] = y, val[ccnt] = z, last[ccnt] = head[x], head[x] = ccnt

int a[30003], d[300003];
inline void sovle1 () {
	for (int i = 1; i < n; i++)
		a[x[i]] += z[i]; 
	for (int i = 1; i <= m; i++)
		a[]
}

inline int lca (int x, int y) {
	if (depth[x] < depth[y])
		x ^= y, y ^= x, x ^= y;
	while (depth[x] > depth[y])
		x = fa[x][lg[depth[x] - depth[y]] - 1]
	if (x == y)
		return x;
	for (int i = lg[depth[x]]; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

inline void dfs (int cur, int dep, int father, int su) {
	fa[cur][0] = father;
	depth[cur] = dep;
	sum[cur] = su;
	for (int i = 1; i <= lg[depth]; i++)
		fa[cur][i] = fa[fa[cur][i - 1]][i];
	for (int i = head[cur]; i; i = last[i])
		if (to[i] != fa[cur])
			dfs(to[i], dep + 1, cur, su + to[i]);
}

inline int lenth (int x, int y) {
	int lc = lca(x, y);
	return sum[x] + sum[y] - sum[fa[lc][0]];
}

int main () {
	for (int i = 1; i < 300003; i++)
		lg[i] = lg[i - 1] + (i >> lg[i - 1]);
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, z);
		if (x[i] > y[i])
			x[i] ^= y[i], y[i] ^= x[i], x[i] ^= y[i];
		if (x[i] + 1 != y[i])
			fs1 = false;
		addedge(x[i], y[i], z[i]);
		addedge(y[i], x[i], z[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		int len = lenth(x, y);
	}
	return 0;
}
