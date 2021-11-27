#include <stdio.h>

int n, k;
int fa[150003] = { 0 };
int ans = 0;

inline int get (int x) {
	if (fa[x] == x)
		return x;
	fa[x] = get(fa[x]);
	return fa[x];
}

int main () {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		fa[i] = i, fa[i + n] = i + n, fa[i + 2 * n] = i + 2 * n;
	for (int i = 1; i <= k; i++) {
		int x, y, z;
		scanf("%d %d %d", &z, &x, &y);
		if ((x > n || y > n || x == y && z == 2) ||
		  (z == 1 && (get(x + n) == get(y) || get(x) == get(y + n))) || 
		  (z == 2 && (get(x) == get(y + n) || get(x) == get(y)))) 
			ans++;
		else if (z == 1) {
			fa[get(x)] = get(y);
			fa[get(x + n)] = get(y + n);
			fa[get(x + 2 * n)] = get(y + 2 * n);
		} else {
			fa[get(x + n)] = get(y);
			fa[get(x + 2 * n)] = get(y + n);
			fa[get(x)] = get(y + 2 * n);
		}
	}
	printf("%d\n", ans);
} 
