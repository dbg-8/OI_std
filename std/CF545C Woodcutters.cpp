#include <stdio.h>
int n;
struct NODE { int x, h, t; } a[100003];
int ans = 2;

int main () {
	scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].x, &a[i].h),
		a[i].t = a[i].x;
	for (int i = 2; i < n; i++) {
		if (a[i].x - a[i].h > a[i - 1].t)
			a[i].t = a[i].x, ans++;
		else if (a[i].x + a[i].h < a[i + 1].x)
			a[i].t = a[i].x + a[i].h, ans++;
	}
	printf("%d\n", ans);
	return 0;
}
