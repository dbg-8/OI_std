#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 500003
#define MAXM 1000003
#define MAXM2 MAXM * 2
#define MAXZ 0x3F3F3F3F 

struct EDGE {
	int x, y, z; // x to y, val = z
} edge[200003];
inline bool cmp (const EDGE &x, const EDGE &y) {
	return x.z > y.z;
}

int n, m;
int fa[MAXN];
int head[MAXN], to[MAXM2], last[MAXM2], val[MAXM2], cnt = 0;
int depth[MAXN];
int ans[MAXN];
int father[MAXN][50];
int lg[MAXN];
 
inline void add_edge (int x, int y, int z) {
	to[++cnt] = y;
	val[cnt] = z;
	last[cnt] = head[x];
	head[x] = cnt;
}

inline int get (int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = get(fa[x]);
}
inline void kruskal () { 
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	std:: sort (edge + 1, edge + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int x = get(edge[i].x), y = get(edge[i].y);
		if (x != y) {
			fa[x] = y;
			add_edge(edge[i].x, edge[i].y, edge[i].z);
			add_edge(edge[i].y, edge[i].x, edge[i].z);
		}
	} 
	return;
}

void dfs (int cur, int dis, int fat) {
	depth[cur] = dis;
	father[cur][0] = fat; 
	for (int i = 1; i <= lg[depth[cur]]; i++)
		father[cur][i] = father[father[cur][i - 1]][i - 1];
	for (int i = head[cur]; i; i = last[i]) 
		if (to[i] != fat)
			dfs(to[i], dis + 1, cur), ans[to[i]] = val[i];
	return;
}
inline int lca (int x, int y) {
	if (depth[x] < depth[y])
		std:: swap(x, y);
	while (depth[x] > depth[y])
		x = father[x][lg[depth[x] - depth[y]] - 1];
	if (x == y)
		return x;
	for (int k = lg[depth[x]] - 1; k >= 0; k--)
		if (father[x][k] != father[y][k])
			x = father[x][k], y = father[y][k];
	return father[x][0];
}

inline int sovle (int x, int y) {
	if (get(x) != get(y))
		return -1;
	int lc = lca(x, y);
	int ret = 0x3F3F3F3F;
	while (x != lc) {
		ret = std:: min(ret, ans[x]);
		x = father[x][0];
	}
	while (y != lc) {
		ret = std:: min(ret, ans[y]);
		y = father[y][0];
	}
	return ret;
}

inline void kagari () {
	cnt = 0;
	memset(head, 0, sizeof(head));
	
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].z);
	kruskal();
	
	for (int i = 1; i <= n; i++)
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	dfs(1, 1, 1);
	
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", sovle(x, y));
	}
}

int main() {
	while (~scanf("%d %d", &n, &m))
		kagari();
	return 0;
}
