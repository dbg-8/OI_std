#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

int n, m;
int head[2003], last[8000003], to[8000003], val[8000003], ccnt = 0;
int dis[2003], cnt[2003];
bool vis[2003];
int ed[2003][2003];

inline void addedge(int x, int y, int z) {
	to[++ccnt] = y;
	val[ccnt] = z;
	last[ccnt] = head[x];
	head[x] = ccnt; 
}

struct NODE {
	int to, val;
	const inline bool operator < (const NODE &rhs) const {
		return val > rhs.val;
	}
} nd;

inline void djs (int cur) {
	memset(vis, false, sizeof(vis));
	memset(dis, 0x3F, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	dis[cur] = 0, cnt[cur] = 1;
	std:: priority_queue <NODE> q;
	nd.to = cur, nd.val = 0;	q.push(nd);
	while (!q.empty()) {
		int x = q.top().to;	q.pop();
		if (vis[x])
			continue;
		vis[x] = true;
		for (register int i = head[x]; i; i = last[i]) {
			register int y = to[i], z = val[i];
			if (dis[x] + z < dis[y]) {
				dis[y] = dis[x] + z;
				cnt[y] = cnt[x];
				nd.to = y, nd.val = dis[y];	q.push(nd);
			}
			else if (dis[x] + z == dis[y])
				cnt[y] += cnt[x];
		}
	} 
	return;
}
inline void sovle (int cur, int wt) {
	djs(cur);
	if (dis[wt] == 0x3F3F3F3F)
		printf("No answer\n");
	else
		printf("%d %d\n", dis[wt], cnt[wt]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (register int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (ed[x][y])
			ed[x][y] = std:: min(ed[x][y], z);
		else
			ed[x][y] = z;
	}
	for (register int i = 1; i <= n; i++)
		for (register int j = 1; j <= n; j++)
			if (ed[i][j])
				addedge(i, j, ed[i][j]);
	sovle(1, n);
	return 0;
}
