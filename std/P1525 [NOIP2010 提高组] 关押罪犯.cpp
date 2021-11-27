#include <stdio.h>
#include <string.h>
#include <algorithm>

int n, m; 
int co[20003];
int head[20003], last[200003], to[200003], val[200003], cnt = 0;

inline void add_edge (int x, int y, int z) {
	to[++cnt] = y;
	val[cnt] = z;
	last[cnt] = head[x];
	head[x] = cnt;
}

inline bool dfs (int x, int color, int mid) {
	co[x] = color;
	for (int i = head[x]; i; i = last[i]) 
		if (val[i] > mid) {
			int y = to[i];
			if (co[y] == 0) {
				if (dfs(y, 3 - co[x], mid) == false)
					return false;
			}
			else if (co[y] == color)
				return false;
		}
	return true;
}

inline int sovle (int mid) {
	memset(co, 0, sizeof(co));
	for (int i = 1; i <= n; i++)
		if (co[i] == 0)
			if (dfs(i, 1, mid) == false)
				return false;
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		add_edge(x, y, z);
		add_edge(y, x, z);
	}
	int l = 0, r = 1000000003;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (sovle(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n", r);
	return 0;
}
