#include <stdio.h>
#define max(x, y) (x > y ? x : y)
 
int n;
int a[20003];
int head[20003], last[40003], to[40003], ccnt = 0;
#define addedge(x, y) to[++ccnt] = y, last[ccnt] = head[x], head[x] = ccnt
int ans = -2147483647;

inline int dfs (int x, int fa) {
	int ret = a[x];
	for (int i = head[x]; i; i = last[i]) {
		if (to[i] == fa)
			continue;
		int z = dfs(to[i], x);
		if (z > 0)
			ret += z;
	}
	ans = max(ret, ans);
	return ret;
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]),
		ans = max(ans, a[i]);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;	
} 
