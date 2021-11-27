#include <stdio.h>
#include <math.h> 
#include <algorithm>

struct EDGE {
	int x, y;
	double z;
	inline bool operator < (const EDGE &rhs) const {
		return z < rhs.z;
	}
} e[250003];

int n, q, m = 0;
int px[503], py[503];
int fa[250003];
double len[250003]; int cnt = 0;

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
			len[++cnt] = e[i].z;
		}
	}
	return;
}

int main () {
	scanf("%d %d", &q, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &px[i], &py[i]);
	for (int i = 1; i <= n; i++) 
		for (int j = i + 1; j <= n; j++) 
			e[++m].x = i, e[m].y = j, e[m].z = sqrt((px[i] - px[j]) * (px[i] - px[j]) + (py[i] - py[j]) * (py[i] - py[j]));
	build();
	printf("%0.2lf\n", len[n - q]);
}
