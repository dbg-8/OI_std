#include <stdio.h>
#include <algorithm>

struct EDGE {
	int x, y, z; // x to y, val = z
} edge[200003];
inline bool cmp (const EDGE &x, const EDGE &y) {
	return x.z < y.z;
}

int n, m;
int fa[5003];
int head[10003], to[400003], last[400003], val[400003], cnt = 0;
int ans = 0;
int ccnt;	// ��ʾ��ǰ�� ccnt ����
 
inline void add_edge (int x, int y, int z) {
	to[++cnt] = y;
	val[cnt] = z;
	last[cnt] = head[x];
	head[x] = cnt;
}

inline int get (int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = get(fa[x]);
}

inline void kruskal () {
	// 1. �������鼯 
	ccnt = n;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	
	// 2. �ߵ����� 
	std:: sort (edge + 1, edge + m + 1, cmp);
	
	// 3. ����ö��ÿ���� ���ӱ�
	for (int i = 1; i <= m; i++) {
		int x = get(edge[i].x), y = get(edge[i].y);
		if (x != y) {	// �����ڵ�û����ͨ(����һ��������), �ӱ� 
			fa[x] = y;
//			add_edge(edge[i].x, edge[i].y, edge[i].z);
//			add_edge(edge[i].y, edge[i].x, edge[i].z);
			ans += edge[i].z;
			ccnt--; 
		}
	} 
	return;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].z);
	kruskal();
	if (ccnt == 1)
		printf("%d\n", ans);
	else
		printf("orz\n");
	return 0;
}
