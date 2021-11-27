#include <stdio.h>
#include <algorithm> 
#define ci const int &

int n, m, nm = 0;
int a[1003][1003];
int d[1003][1003];	// (x, y) 前往目标最优路径上的最大值 
int pos[4][2] = { { 0, 1 }, { 1, 0 } };
struct EDGE {
	int x, y, z;
	const inline bool operator < (const EDGE &rhs) const {
		return rhs.z < z;
	}
} e[8000003], nd;	int ccnt = 0;
inline EDGE nn (ci x, ci y, ci z) {	EDGE ne; ne.x = x, ne.y = y, ne.z = z;	return ne;	}
#define addedge(x, y, z) e[++ccnt] = nn(x, y, z)

int fa[1000003];
inline int getfa (int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = getfa(fa[x]);
}
inline int kur (int cur) {
	std:: sort(e + 1, e + ccnt + 1); 
	for (int i = 1; i <= nm; i++)
		fa[i] = i;
	int cnt = 1, ret;
	for (int i = 1; i <= nm; i++) {
		int x = getfa(e[i].x), y = getfa(e[i].y);
		if (x != y) {
			fa[x] = y;
			ret = std:: max(ret, e[i].z);
			cnt++;
			if (getfa(1) == getfa(nm)) 
				break;
		} 
	}
	return ret;
}

int main () {
	scanf("%d %d", &n, &m);	nm = n * m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			for (int k = 0; k < 2; k++) {
				int nx = i + pos[k][0], ny = j + pos[k][1];
				if (!(nx >= 1 && nx <= n && ny >= 1 && ny <= m))
					continue;
				addedge((i - 1) * n + j, (nx - 1) * n + ny, std:: max(a[i][j], a[nx][ny]));
			}
	printf("%d\n", kur(1));
	return 0;
} 
