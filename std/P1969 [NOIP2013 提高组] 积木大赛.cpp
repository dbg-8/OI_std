#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int n;
int a[100003], b[100003];
int ans1 = 0, ans2 = 0;

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		b[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; i++)
		if (b[i] > 0)
			ans1 += b[i];
		else
			ans2 += b[i];
	printf("%d\n", max(ans1, -ans2));
	return 0;
}
