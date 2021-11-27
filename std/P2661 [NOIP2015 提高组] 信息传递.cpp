#include <stdio.h>
#include <queue>
#define min(x, y) ((x) < (y) ? (x) : (y))

int n;
int a[200003];
int d[200003];
int rd[200003];
bool vis[200003];
int ans = 2e5 + 3;

inline void dfs (int cur, int sum) {
	if (vis[cur])
		return;
	ans = min(ans, sum);
	
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]),
		rd[a[i]]++;
	int ans = bfs();
	printf("%d\n", ans);
	return 0;
}
