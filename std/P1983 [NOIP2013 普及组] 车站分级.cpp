#include <stdio.h>
#define max(x, y) (x > y ? x : y)
int n, m;
bool edge[1003][1003];
int inh[1003];
bool vis[1003];
int dis[1003];
#define vcl() for (int i = 0; i < 1003; i++) vis[i] = false;
int ans = 1;

inline void dfs (int x, int deep) {
	if (deep <= dis[x])
		return;
	dis[x] = deep;
	ans = max(ans, deep);
	for (int y = 1; y <= n; y++)
		if (edge[x][y] && !vis[y])
			dfs(y, deep + 1);
	return;
}

inline void tur () {
	vcl();
	for (int i = 1; i <= n; i++)
		dis[i] = 0; 
	for (int i = 1; i <= n; i++)
		if (inh[i] == 0)
			dfs(i, 1);
	return;
}

int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		vcl();
		int s, l, r;
		scanf("%d %d", &s, &l);
		for (int j = 2; j < s; j++) {
			int x;
			scanf("%d", &x);
			vis[x] = true;
		}
		scanf("%d", &r);
		vis[l] = vis[r] = true;
		for (int j = l; j <= r; j++)
			if (!vis[j])
				for (int k = l; k <= r; k++)
					if (vis[k])
						edge[j][k] = true,
						inh[k]++;
	}
	tur();
	printf("%d\n", ans);
	return 0;
}
