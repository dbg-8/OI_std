#include <stdio.h>
#include <algorithm>

struct EDGE {
	int x, y, z;
	inline bool operator < (const EDGE &rhs) const {
		return z < rhs.z;
	}
} e[10003];

int n, m = 0;
int ans = 0;
int fa[10003];

inline int get (int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = get(fa[x]);
}
 
inline void build () {
	std:: sort(e + 1, e + m + 1);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int x = get(e[i].x), y = get(e[i].y);
		if (x != y) {
			fa[x] = y;
			ans += e[i].z; 
		}
	}
	return;
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			if (i > j) 
				e[++m].x = i, e[m].y = j, e[m].z = x;
		}
	build();
	printf("%d\n", ans);
}
