#include <stdio.h>
#include <string.h>
#include <queue>

int n, m;
int dis[100003][2];
bool vis[100003][2];
int head[100003], last[200003], to[200003], cnt = 0;

#define addedge(x, y) to[++cnt] = y, last[cnt] = head[x], head[x] = cnt

struct NODE {
	int y;
	int z;
	const inline bool operator < (const NODE &rhs) const {
		return z > rhs.z;
	}
} nd;

inline void djs (int cur) {
	memset(dis, 0x3F, sizeof(dis));
	vis[cur][0] = true;
	dis[cur][0] = 0;
	std:: priority_queue <NODE> q;
	nd.y = cur, nd.z = 0;
	q.push(nd);
	while (!q.empty()) {
		int x = q.top().y, z = q.top().z; q.pop();
		int w = (z + 1) % 2;
		for (int i = head[x]; i; i = last[i]) {
			int y = to[i];
			if (!vis[y][w]) {
				vis[y][w] = true;
				dis[y][w] = z + 1;
				nd.y = y, nd.z = z + 1; q.push(nd);
			} 
		}
	}
	return;
}

int main() {
	int q;
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
	djs(1);
	while (q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%s\n", dis[x][y % 2] <= y ? "Yes" : "No");
	}
	return 0;
}
