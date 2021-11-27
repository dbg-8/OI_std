#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

int n, m; 
bool vis[100003];
int ans[100003];
int head[100003], last[100003], to[100003], cnt = 0;

inline void add_edge (int x, int y) {
	to[++cnt] = y;
	last[cnt] = head[x];
	head[x] = cnt;
}

inline void bfs (int cur) {
	std:: priority_queue < int, std:: vector <int>, std:: greater <int> > q;
	q.push(cur);
	vis[cur] = true;
	ans[cur] = cur;
	while (!q.empty()) {
		int x = q.top(); q.pop();
		for (int i = head[x]; i; i = last[i]) {
			int y = to[i];
			if (!vis[y]) {
				vis[y] = true;
				ans[y] = cur;
				q.push(y);
			}
		}
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		add_edge(y, x);
	}
	for (int i = n; i >= 1; i--)
		if (!vis[i])
			bfs(i);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}
