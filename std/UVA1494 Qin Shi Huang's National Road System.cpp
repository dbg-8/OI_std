#include <stdio.h>

int n;
int px[1003], py[1003];
struct EDGE {
	int x, y;
	double z;
} e[2000003];	int m;
#define addedge(x, y, z) e[++m].x = x, e[m].y = y, e[m].z = z
#define dis(i, j) sqrt((double)((px[i] - px[j]) * (px[i] - px[j]) + (py[i] - py[j]) * (py[i] - py[j]))

int fa[1003];
inline int getfa (int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = getfa(fa[x]);
}

inline void kur (int cur) {
	std:: sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	int cnt = 1;
	double ans2 = 0.0, ans3 = 0.0;
	for (int i = 1; i <= n; i++) {
		int x = getfa(e[i].x), y = getfa(e[i].y);
		if (x != y) {
			fa[x] = y;
			ans2 += e[i].z;
			cnt++;
			if (cnt == n) {
				ans3 = e[i].z;
				break;
			}
		} 
	}
	return ans2 - ans3;
}

inline void kagari () {
	cnt = 0;
	memset(head, 0, sizeof(head));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &px[i], &py[i], &tval[i]);
	double ans1 = 0.0, ans2 = 0.0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			addedge(i, j, dis(i, j)), addedge(j, i, dis(i, j)), de[i][j] = de[j][i] = dis(i, j);
	kur();
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			double 
		}
}

int main () {
	int t;
	scanf("%d", &t);
	while (t--)
		kagari();
	return 0;
}
