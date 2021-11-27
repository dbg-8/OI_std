#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int n;
int a[100003];
int d[2][100003];
int ans = 0;

inline int sovle () {
	for (int i = 1; i <= n; i++)
		if (a[i] > a[i - 1])
			d[0][i] = d[1][i - 1] + 1;
		else
			d[1][i] = d[0][i - 1] + 1;
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret = max(ret, d[0][i] + d[1][i]);
	return ret;
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ans = sovle();
	for (int i = 1; i <= n; i++)
		a[i] = -a[i];
	ans = max(ans, sovle());
	printf("%d\n", ans);
	return 0;
}
