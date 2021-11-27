#include <stdio.h>
#include <vector>
#include <queue>
#define ci const int &

struct NODE {
	int p, val;
	inline const bool operator < (const NODE &rhs) const {
		return val > rhs.val;
	}
} nd;

int n, m;
int s, t;
std:: vector <int> g[2][10003];
int d[10003];
bool vis[10003];
bool cvis[10003];		// 出边所指向的点都直接或间接与终点连通的点 
bool ccvis[10003];		// 与终点相连的点 

inline void add_edge (ci x, ci y, ci p) {
	if (x == y)	// 自环 
		return;
	for (int i = 0; i < g[p][x].size(); i++)
		if (g[p][x][i] == y)	// 重边 
			return;
	g[p][x].push_back(y);
	return;
}

void dfs1 (int cur) {		// 从终点出发, 看哪些点能够到达终点 
	ccvis[cur] = true;
	for (int i = 0; i < g[1][cur].size(); i++) 
		if (!ccvis[g[1][cur][i]])
			dfs1(g[1][cur][i]);
	return;
}

inline void djs (int cur) {	// 最短路 
	for (int i = 1; i <= n; i++)
		d[i] = 0x3F3F3F3F;
	std:: priority_queue <NODE> pq;
	nd.p = cur, nd.val = 0;
	pq.push(nd);
	d[cur] = 0;
	while (!pq.empty()) {
		nd = pq.top(); pq.pop();
		int x = nd.p, val = nd.val;
		vis[x] = true;
		for (int i = 0; i < g[0][x].size(); i++) {
			int fw = g[0][x][i];
			if (!vis[fw] && cvis[fw] && d[fw] > val + 1) {
				d[fw] = val + 1;
				nd.p = fw, nd.val = d[fw]; pq.push(nd);
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
		add_edge(x, y, 0);
		add_edge(y, x, 1);
	}
	scanf("%d %d", &s, &t);
	dfs1(t);
	for (int i = 1; i <= n; i++) {
		cvis[i] = true;
		if (ccvis[i] == false)
			cvis[i] = false; 
		for (int j = 0; j < g[0][i].size(); j++)
			if (ccvis[g[0][i][j]] == false)
				cvis[i] = false;
	}
	djs(s);
	printf("%d\n", d[t] == 0x3F3F3F3F ? -1 : d[t]);
	return 0;
}
