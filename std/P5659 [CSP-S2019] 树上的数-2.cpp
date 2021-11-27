#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define ri register int

int n, m;
int a[2003];	// a[i] = �� i �����ϵ�����
int b[2003];	// b[i] = �� i ���������ڵ�
int dis[2003]; 
int head[2003], last[4003], to[4003], cnt;
#define adde(x, y) to[++cnt] = y, last[cnt] = head[x], head[x] = cnt

inline int findedge (int x, int y) {	// ���� x -> y �ıߵı�� 
	for (ri i = head[x]; i; i = last[i])
		if (to[i] == y) 
			return i;
}

inline int dfs1 (int x, int fa) {	// �õ���С�Ŀ���ȥ�Ľڵ��� 
	int ret = x;
	for (ri i = head[x]; i; i = last[i]) 
		if (to[i] != -1 && to[i] != fa) 
			ret = std:: min(ret, dfs1(to[i], x));
	return ret;
}

inline bool dfs2 (int x, int fa, int wt) {	// ǰ�� wt �ڵ㲢��¼���� 
	if (x == wt) {
		dis[x] = -1;
		return true;
	}
	bool ret = false;
	for (ri i = head[x]; i; i = last[i]) 
		if (to[i] != -1 && to[i] != fa) 
			if (dfs2(to[i], x, wt)) {
				dis[x] = to[i];
				ret = true;
			}
	return ret;
}

inline void dfs3 (int x) {	// ǰ�� wt �ڵ� 
	ri y = dis[x];
	if (y == -1)
		return;
	std:: swap(a[x], a[y]);
	std:: swap(b[a[x]], b[a[y]]);
	to[findedge(x, y)] = -1;
	to[findedge(y, x)] = -1;
	dfs3(y);
}

inline void kagari () {
	cnt = 0;
	memset(head, 0, sizeof(head));
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		a[b[i]] = i;
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adde(x, y);	adde(y, x);
	}
	// ����״̬�� 1 2 3 4 5... ����ö��ÿ���� i ʹ�価���ܵ���ڵ� i ����С�ڵ� 
	for (ri i = 1; i <= n; i++) {	// �� i ���� 
		printf("======= start %d %d ==========\n", i, b[i]);
		for (ri j = 1; j <= n; j++)
			dis[j] = -1;
		int wt = dfs1(b[i], b[i]);
		printf("want to %d!! I can!\n", wt);
		dfs2(b[i], b[i], wt);
		dfs3(b[i]);
	}
	for (ri i = 1; i <= n; i++)
		printf("%d%c", a[i], i == n ? '\n' : ' ');
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		kagari(); 
	return 0;
}
