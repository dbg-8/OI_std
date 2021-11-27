#include <stdio.h>

int n;
int a[10003], b[10003], c[10003], d[10003];
int e, f;
int ans = -1;

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	scanf("%d %d", &e, &f);
	for (int i = 1; i <= n; i++)
		if ((a[i] <= e && e <= a[i] + c[i]) && (b[i] <= f && f <= b[i] + d[i]))
			ans = i;
	printf("%d\n", ans);
	return 0;
}
