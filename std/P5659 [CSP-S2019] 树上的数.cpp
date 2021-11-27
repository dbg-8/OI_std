#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define ri register int

int n;
int a[2003];	// a[i] = 第 i 个点上的数字
int b[2003];	// b[i] = 第 i 个数字所在点
int ans[2003];
int his[2003];
bool vis[4003];
struct NODE {
	int x, y;
} e[4003];
#define adde(x, y, i) e[i].x = x, e[i].y = y;

inline void dfs (int cur, int depth) {
	int x = e[cur].x, y = e[cur].y;
	std:: swap(a[x], a[y]);
	std:: swap(b[a[x]], b[a[y]]);
	vis[cur] = true;	
	if (depth + 1 >= n) {
		bool flag = false;
		for (int i = 1; i <= n; i++)
			if (ans[i] > b[i]) {
				flag = true;
				break;
			}
			else if (ans[i] < b[i]) 
				break;
		if (flag)
			for (int i = 1; i <= n; i++)
				ans[i] = b[i];
	}
	else
		for (int i = 1; i < n; i++)
			if (!vis[i])
				dfs(i, depth + 1);
	vis[cur] = false;
	std:: swap(a[x], a[y]);
	std:: swap(b[a[x]], b[a[y]]);
}

inline void kagari () {
	memset(vis, false, sizeof(vis));
	memset(ans, 0x3F, sizeof(ans));
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		a[b[i]] = i;
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adde(x, y, i);
	}
	for (int i = 1; i < n; i++)
		dfs(i, 1);
	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		kagari(); 
	return 0;
}
