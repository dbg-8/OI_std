#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

int n, m; 

struct EDGE {
	int x, y, z;
	const inline bool operator < (const EDGE &rhs) const {
		return z < rhs.z;
	}
} e[10003];
int cnt;
#define addedge(x, y, z) e[++cnt].x = x, e[cnt].y = y, e[cnt].z = z

int fa[103];
inline int getfa (int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = getfa(fa[x]);
}

inline int dursal () {
	int ans = 0x3F3F3F3F;
	for (int l = 1; l <= m; l++) {
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		int ret = 1;			// 已经有 ret 个节点联通了 
		for (int r = l; r <= m; r++) {
			int x = getfa(e[r].x), y = getfa(e[r].y);
			if (x != y) {	// 尚未联通 
				fa[x] = y;
				ret++;
				if (ret == n) {
					ans = std:: min(ans, e[r].z - e[l].z);
					break;
				}
			}
		}
	}
	return ans == 0x3F3F3F3F ? -1 : ans;
}

inline void sovle () {
	cnt = 0;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		addedge(x, y, z);
	}
	std:: sort(e + 1, e + m + 1);
	printf("%d\n", dursal());
	return;
}

int main () {
	while (~scanf("%d %d", &n, &m) && n) 
		sovle();
	return 0;
}
