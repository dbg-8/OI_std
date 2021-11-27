#include <stdio.h>

int n, ans;
int d[1003];

inline bool dfs (int cur, int cnt) {
	if (cnt > ans || cur <= 0 || cur << (ans - cnt) < n)	// 超过答案 |  值<=1 | 无法达到目标 
		return false;
	if (cur == n || cur << (ans - cnt) == n)	// 到达目标 | ^(ans - cnt) 能够到达目标 
		return true;
	d[cnt] = cur;
	for (int i = 0; i <= cnt; i++) 
		if (dfs(cur + d[i], cnt + 1) || dfs(cur - d[i], cnt + 1))	// cur * 或 / d[i] 能够到达目标 
			return true;
	return false;
}

inline void kagari () {
	for (ans = 0; ; ans++)
		if (dfs(1, 0))
			break;
	printf("%d\n", ans);
	return; 
}

int main () {
	while (scanf("%d", &n) && n)
		kagari();
	return 0;
}
