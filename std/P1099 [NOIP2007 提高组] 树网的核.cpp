#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ci register const int &
#define ri register int

int n, s;
int head[1003], to[1003], last[1003], val[1003], cnt = 0;
int far[1003][1003];
bool isz[1003], isc[1003], vis[1003];

inline void add_edge(ci x, ci y, ci z) {
	to[++cnt] = y;
	val[cnt] = z;
	last[cnt] = head[x];
	head[x] = cnt;
	return;
}

inline void dfs2 (ci cur, ci father, ci st) {
	for (ri i = head[cur]; i; i = last[i]) 
		if (to[i] != father) {
			far[st][to[i]] = far[st][cur] + val[i];
			dfs2(to[i], cur, st);
		}
	return;
}

inline bool dfs3 (ci cur, ci father, ci wt, bool (&fl)[1003]) {
	fl[cur] = (cur == wt ? true : false);
	for (ri i = head[cur]; i; i = last[i]) 
		if (to[i] != father)
			if (dfs3(to[i], cur, wt, fl))
				fl[cur] = true;
	return fl[cur];
} 

int dfs4 (ci cur, ci sum) {
	ri ret = sum;
	vis[cur] = true;
	for (ri i = head[cur]; i; i = last[i]) {
		ri y = to[i];
		if (isc[y] && !vis[y]) { 
			ret = std:: max(ret, dfs4(y, 0));
			continue;
		}
		if (vis[y])
			continue;
		ret = std:: max(ret, dfs4(y, sum + val[i]));
	}
	return ret;
}

int main () {
	scanf("%d %d", &n, &s);
	for (int i = 1; i < n; i++) {
		ri x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		add_edge(x, y, z);
		add_edge(y, x, z);
	}
	for (int i = 1; i <= n; i++)
		dfs2(i, i, i);
	ri ren = 0;
	for (ri i = 1; i <= n; i++)
		for (ri j = 1; j <= n; j++) 
			ren = std:: max(ren, far[i][j]);
	for (ri i = 1; i <= n; i++)
		for (ri j = 1; j <= n; j++) 
			if (far[i][j] == ren)
				dfs3(i, i, j, isz);
	ri ans = 0x3F3F3F3F;
	for (ri i = 1; i <= n; i++)
		for (ri j = i; j <= n; j++)
			if (isz[i] && isz[j] && far[i][j] <= s) {
				memset(isc, false, sizeof(isc));
				memset(vis, false, sizeof(vis));
				dfs3(i, i, j, isc);
				ans = std:: min(ans, dfs4(i, 0));
			}
	printf("%d\n", ans);
	return 0;
}
