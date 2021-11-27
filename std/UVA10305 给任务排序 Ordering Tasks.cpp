#include <stdio.h>
#include <string.h>

int n, m;
int head[1003], last[10003], to[10003], ccnt = 0;
int ans[1003], cnt = 0;
bool vis[1003];

inline void add_edge (int x, int y) {
	to[++ccnt] = y;
	last[ccnt] = head[x];
	head[x] = ccnt;
}

inline bool dfs (int x) {
	vis[x] = true;
	for (int i = head[x]; i; i = last[i]) {
		int y = to[i];
		if (vis[y] == false)
			dfs(y);
	}
	ans[cnt--] = x;
}

inline void sovle () {
	ccnt = 0;
	cnt = n;
	memset(head, 0, sizeof(head));
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		add_edge(x, y);
	}
	for (int i = 1; i <= n; i++)
		if (vis[i] == 0)
			dfs(i);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
}

int main () {
	while (~scanf("%d %d", &n, &m) && n) 
		sovle();
	return 0;
}
