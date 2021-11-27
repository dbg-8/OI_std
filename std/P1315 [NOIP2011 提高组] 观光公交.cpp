#include <stdio.h> 
#define ri register int
#define max(x, y) ((x) > (y) ? (x) : (y))
#define clear(x) 
#define getgettime()	\
	for (ri kk = 2; kk <= n; kk++) \
		gettime[kk] = max(canrun[kk - 1], gettime[kk - 1]) + d[kk - 1];

int n, m, q;
int d[1003];
int st[10003], sx[10003], sy[10003];
int getoff[1003], need[1003];
int canrun[1003], gettime[1003];

int main () {
	scanf("%d %d %d", &n, &m, &q);
	for (ri i = 1; i < n; i++)
		scanf("%d", &d[i]);
	for (ri i = 1; i <= m; i++) 
		scanf("%d %d %d", &st[i], &sx[i], &sy[i]),
		canrun[sx[i]] = max(canrun[sx[i]], st[i]),
		getoff[sy[i]] += 1;
	getgettime();
	while (q--) {
		for (ri j = n - 1; j >= 1; j--)				// 注意一次可以让后面所有人缩小等待时间!! 
			if (d[j] == 0)	// 无法继续减小 d[j]
				need[j] = 0;
			else if (gettime[j + 1] > canrun[j + 1])		// 需要优化 
				need[j] = need[j + 1] + getoff[j + 1];
			else	// 无需继续优化, 与后面人无关 
				need[j] = getoff[j + 1];
		ri maxp = 0, maxx = 0;
		for (ri j = 1; j < n; j++)
			if (maxx < need[j])
				maxx = need[j], maxp = j;
		if (maxp == 0)
			break; 
		d[maxp] -= 1;
		getgettime();
	}
	int ans = 0;
	for (ri i = 1; i <= m; i++)
		ans += gettime[sy[i]] - st[i];
	printf("%d\n", ans);
	return 0;
}
