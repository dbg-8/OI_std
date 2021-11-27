#include <stdio.h>

int n, m;
int px[1003], py[1003];
int fa[1003];
int ans;
bool use[13];

#define dis (i, j) (px[i] - px[j]) * (px[i] - px[j]) + (py[i] - py[j]) * (py[i] - py[j])

struct NET {
	int size;
	int city[1003];
	int val;
} net[10];

struct EDGE {
	int x, y, z;
	const inline bool operator < (const EDGE &rhs) const {
		return z < rhs.z;
	}
} e[2000003], nd; int m = 0;
#define addedge (x, y, z) e[++m].x = x, e[m].y = y, e[m].z = z;
inline EDGE nedge(x, y, z) { nd.x = x, nd.y = y, nd.z = z; return nd; }

inline void findfa (int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = findfa(fa[x]);
}

inline void dsul () {
	int cnt = 1, i = 1, ret = 0;
	while (cnt < n) {
		int x = findfa(e[i].x), y = findfa(e[i].y);
		if (x != y) {
			fa[x] = y;
			ret += e[i].z;
			cnt++;
		}
	}
	return ret;
}

inline void kusl () {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	int ret = 0;
	for (int i = 1; i <= q; i++)
		if (use[i]) {
			ret += net[i].val;
			for (int j = 1; j <= net[i].size; i++)
				
		} 
	ans = std:: min(ans, ret);
}

void dfs (int cur) {
	if (cur == q + 1) {
		kusl();
		return;
	}
	use[cur] = false;
	dfs(cur + 1);
	use[cur] = true;
	dfs(cur + 1); 
}

inline void sovle () {
	cnt = 0;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d", &net[i].size);
		for (int j = 1; j <= net[i].size; j++) 
			scanf("%d", &net[i].city[j]);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &px[i], &py[i]);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			addedge(i, j, dis(i, j)), add_edge(i, j, dis(i, j));
	std:: sort(e + 1, e + m + 1);
	ans = dsal();
	dfs(1);
	printf("%d\n\n", ans);
	return;
}

int main () {
	int t;
	scanf("%d", &t);
	while (t--)
		sovle();
	return 0;
}
