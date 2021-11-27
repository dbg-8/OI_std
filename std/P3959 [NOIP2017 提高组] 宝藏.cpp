#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

int n, m;
bool vis[14];

struct EDGE {
	int y, z;
	int val;
} e[14][1003];
int cnt[14];
inline void add_edge(int x, int y, int z) {
	for (int i = 1; i <= cnt[x]; i++)
		if (e[x][i].y == y) {
			e[x][i].z = std:: min(e[x][i].z, z);
			return;
		}
	EDGE nd; nd.y = y, nd.z = z;
	e[x][++cnt[x]] = nd;
}

struct NODE {
	int x;
	int k, val;
	const inline bool operator < (const NODE &rhs) const {
		return val == rhs.val ? k < rhs.k :  val > rhs.val;
	}
};

inline int bfs (int cur) {
	memset(vis, false, sizeof(vis));
	int ret = 0; NODE nd;
	nd.x = cur, nd.k = 0, nd.val = 0;
	std:: priority_queue < NODE > q;
	q.push(nd);
	while (!q.empty()) {
		nd = q.top();	q.pop();
		int x = nd.x, k = nd.k;
		if (vis[x])
			continue;
		ret += nd.val;
		vis[x] = true;
		for (int i = 1; i <= cnt[x]; i++) {
			int to = e[x][i].y;
			if (!vis[to]) {
				nd.x = to, nd.k = k + 1, nd.val = e[x][i].z * nd.k;
				q.push(nd);
			} 
		}
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (z > 50)
			continue;
		add_edge(x, y, z);
		add_edge(y, x, z);
	}
	
	int ans = 0x3F3F3F3F;
	for (int i = 1; i <= n; i++) 
		ans = std:: min(ans, bfs(i));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= cnt[i]; j++)
			printf("%d %d %d\n", i, e[i][j].y, e[i][j].z);
	printf("%d\n", ans);
	return 0;
}
