#include <stdio.h>
#include <algorithm>
#include <string.h>

int n, k;
int dis[100003];
bool vis[100003];
int head[200003], to[200003], last[200003], val[200003], cnt = 0;
int l2 = -0x3F3F3F3F;
int ans1, ans2, ren;

inline void add_edge(int x, int y, int z) {
	to[++cnt] = y;
	val[cnt] = z;
	last[cnt] = head[x];
	head[x] = cnt;
	return;
}

inline void dp (int x) {
	vis[x] = true;
	for (int i = head[x]; i; i = last[i]) {
		int y = to[i], z = val[i];
		if (vis[y]) 
			continue;
		dp(y);
		l2 = std:: max(l2, dis[x] + dis[y] + z);
		dis[x] = std:: max(dis[x], dis[y] + z);
	}
}

bool dfs (int cur, int father, int wt) {
	bool flag = (cur == wt ? true : false);
	for (int i = head[cur]; i; i = last[i]) 
		if (to[i] != father) {
			dis[to[i]] = dis[cur] + val[i];
			if (dfs(to[i], cur, wt)) // 这条路可以通往 wt 节点
				flag = true, val[i] *= -1, val[(i % 2 == 1 ? i + 1 : i - 1)] *= -1;
		}
	return flag;
}

inline int maxdp () {
	int maxn = -0x3F3F3F3F, maxp;
	for (int i = 1; i <= n; i++)
		if (dis[i] >= maxn)
			maxn = dis[i], maxp = i;
	return maxp;
}
inline int longroad () {	// 计算树的直径 返回长度 
	dis[1] = 0;	dfs(1, 1, -1);	ans1 = maxdp();
	dis[ans1] = 0;	dfs(ans1, ans1, -1);	ans2 = maxdp();
	ren = dis[ans2];
	dis[ans1] = 0;	dfs(ans1, ans1, ans2);
	return ren;
}

inline void sovle1 () {
	printf("%d\n", 2 * n - 2 - longroad() + 1);
}
inline void sovle2 () {
	int l1 = longroad();
	memset(dis, 0, sizeof(dis));
	dp(ans1);
	printf("%d\n", 2 * n - l1 - l2);
}

int main () {
	scanf("%d %d", &n, &k);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		add_edge(x, y, 1);
		add_edge(y, x, 1);
	}
	if (k == 1)
		sovle1();
	else
		sovle2();
	return 0;
}
