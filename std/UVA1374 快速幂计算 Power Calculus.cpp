#include <stdio.h>

int n, ans;
int d[1003];

inline bool dfs (int cur, int cnt) {
	if (cnt > ans || cur <= 0 || cur << (ans - cnt) < n)	// ������ |  ֵ<=1 | �޷��ﵽĿ�� 
		return false;
	if (cur == n || cur << (ans - cnt) == n)	// ����Ŀ�� | ^(ans - cnt) �ܹ�����Ŀ�� 
		return true;
	d[cnt] = cur;
	for (int i = 0; i <= cnt; i++) 
		if (dfs(cur + d[i], cnt + 1) || dfs(cur - d[i], cnt + 1))	// cur * �� / d[i] �ܹ�����Ŀ�� 
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
