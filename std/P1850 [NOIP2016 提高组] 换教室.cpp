#include <stdio.h>
#include <string.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

int n, m, v, e;
int a[2003], b[2003];
double k[2003];
double d[2003][2003][2];
double dis[303][303];

inline void floyd () {
	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main () {
	scanf("%d %d %d %d", &n, &m, &v, &e);
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			dis[i][j] = 9000003.0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &k[i]);
	for (int i = 1; i <= e; i++) {
		int x, y;	double z;
		scanf("%d %d %lf", &x, &y, &z);
		dis[x][y] = dis[y][x] = min(dis[x][y], z);
	}
	floyd();
	d[1][0][0] = d[1][0][1] = d[1][1][0] = d[1][1][1] = 0.0;
	for (int i = 2; i <= n; i++) {
		d[i][0][0] = d[i - 1][0][0] + dis[a[i - 1]][a[i]];
		for (int j = 1; j <= m; j++) 
			d[i][j][0] = min(
				d[i - 1][j][0] + dis[a[i - 1]][a[i]],
				d[i - 1][j][1] 
					+ (1 - k[i - 1]) * dis[a[i - 1]][a[i]] +
					+ k[i - 1] * dis[b[i - 1]][a[i]]
			),	
			d[i][j][1] = min(
				d[i - 1][j - 1][0]
					+ dis[a[i - 1]][a[i]] * (1 - k[i])
					+ dis[a[i - 1]][b[i]] * k[i],
				d[i - 1][j - 1][1] 
					+ dis[a[i - 1]][a[i]] * (1 - k[i - 1]) * (1 - k[i])
					+ dis[a[i - 1]][b[i]] * (1 - k[i - 1]) * k[i]
					+ dis[b[i - 1]][a[i]] * k[i - 1] * (1 - k[i])
					+ dis[b[i - 1]][b[i]] * k[i - 1] * k[i]
			);
		}
	double ans = d[n][0][0];
	for (int i = 1; i <= m; i++)
		ans = min(ans, min(d[n][i][0], d[n][i][1]));
	printf("%.2lf\n", ans);
	return 0;
} 
