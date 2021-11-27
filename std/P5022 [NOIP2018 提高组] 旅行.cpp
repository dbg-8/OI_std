#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

int n, m;
int lx[5003], ly[5003];
int ans[5003];
int ret[5003], cnt = 0;
bool vis[5003];
std:: vector < int > v[5003];
int nt = 0;

inline bool nechange () {
	for (int i = 1; i <= n; i++)
		if (ret[i] == 0)
			return false;
	if (ans[1] == 0)
		return true;
	for (int i = 1; i <= n; i++)
		if (ans[i] < ret[i])
			return false;
		else if (ans[i] > ret[i])
			return true;
	return false;
}
inline void check () {
	cnt = 0;
	if (!nechange())
		return;
	for (int i = 1; i <= n; i++)
		ans[i] = ret[i];
	return;
}

void dfs1 (int cur) {
	vis[cur] = true;
	ret[++cnt] = cur;
	for (int i = 0; i < v[cur].size(); i++)
		if (!(lx[nt] == cur && ly[nt] == v[cur][i] || ly[nt] == cur && lx[nt] == v[cur][i]) && !vis[v[cur][i]])
			dfs1(v[cur][i]);
	return;
}

inline void tatara () {
	memset(vis, false, sizeof(vis));
	dfs1(1);
	check();
	return;
}

inline void ogasa () {
	for (int i = 1; i <= m; i++) 
		nt = i, tatara();
}

int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) 
		scanf("%d %d", &lx[i], &ly[i]),
		v[lx[i]].push_back(ly[i]),
		v[ly[i]].push_back(lx[i]);
	for (int i = 1; i <= n; i++)
		std:: sort(v[i].begin(), v[i].end());
	if (n != m)
		tatara();
	else
		ogasa();
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
