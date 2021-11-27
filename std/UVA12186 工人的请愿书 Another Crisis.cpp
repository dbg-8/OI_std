#include <stdio.h>
#include <vector>
#include <queue>

int n, t;
int fa[100003];
std:: vector < int > sons[100003];
#define ns(i) (sons[i].size() - (int)(sons[i].size() * (100 - t) / 100))

inline int dfs (int x) {
	if (sons[x].size() == 0) 
		return 1;
	std:: priority_queue < int, std:: vector <int>, std:: greater <int> > q;
	for (int i = 0; i < sons[x].size(); i++)
		q.push(dfs(sons[x][i]));
	int ret = 0;
	for (int i = 0; i < ns(x); i++)
		ret += q.top(),
		q.pop();
	return ret;
}

inline void kagari () {
	for (int i = 0; i <= n; i++)
		sons[i].clear();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &fa[i]);
		sons[fa[i]].push_back(i);
	}
	printf("%d\n", dfs(0));
}

int main () {
	while (~scanf("%d %d", &n, &t) && n && t)
		kagari();
	return 0;
}
