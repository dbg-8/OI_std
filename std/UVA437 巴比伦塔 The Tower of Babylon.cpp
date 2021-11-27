#include <stdio.h>
#include <string.h>
#include <algorithm>

struct NODE {
	int x, y;
	int h;
} a[103];
inline NODE getn (int x, int y, int z) {
	NODE nd; nd.x = x, nd.y = y, nd.h = z; return nd;
}
int n;
int d[103];

inline int dfs (int i) {
	if (d[i] != -1)
		return d[i];
	int ret = a[i].h;
	for (int j = 1; j <= 3 * n; j++)
		if (a[i].x > a[j].x && a[i].y > a[j].y)
			ret = std:: max(ret, a[i].h + dfs(j));
	d[i] = ret;
	return d[i]; 
}

inline void kagari (int t) {
	for (int i = 0; i < sizeof(d); i++)
		d[i] = -1;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[3 * i - 2] = getn(std:: max(x, y), std:: min(x, y), z);
		a[3 * i - 1] = getn(std:: max(y, z), std:: min(y, z), x);
		a[3 * i - 0] = getn(std:: max(z, x), std:: min(z, x), y);
	}
	int ans = 0;
	for (int i = 1; i <= 3 * n; i++)
		ans = std:: max(ans, dfs(i));
	printf("Case %d: maximum height = %d\n", t, ans);
	return; 
}

int main () {
	int t = 1;
	while (~scanf("%d", &n) && n)
		kagari(t++);
	return 0;
}
