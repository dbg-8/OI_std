#include <stdio.h>
#include <math.h>
#define ll long long
#define ld long double

int n;
ll h, r, x[1003], y[1003], z[1003];
int edge[1003][1003];
bool vis[1003];

#define dis(i, j) sqrt((long double)((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j])))
#define addedge(i, j) edge[i][++edge[i][0]] = j

void dfs (int cur) {
	vis[cur] = true;
	for (int i = 1; i <= edge[cur][0]; i++)
		if (!vis[edge[cur][i]])
			dfs(edge[cur][i]);
}

inline void sovle () {
	scanf("%d %lld %lld\n", &n, &h, &r);
	for (int i = 1; i <= n; i++)
		scanf("%lld %lld %lld", &x[i], &y[i], &z[i]), vis[i] = false, edge[i][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (dis(i, j) <= (ld)r * (ld)2.0)
				addedge(i, j), addedge(j, i);
	for (int i = 1; i <= n; i++) 
		if (!vis[i] && z[i] <= r)
			dfs(i);
	bool ans = false;
	for (int i = 1; i <= n; i++)
		if (vis[i] && z[i] + r >= h)
			ans = true;
	printf("%s\n", ans ? "Yes" : "No");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		sovle();
	return 0;
} 
