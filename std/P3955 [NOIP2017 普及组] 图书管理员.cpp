#include <stdio.h>
#include <algorithm>

int n, m;
int a[1003];
int k10[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	std:: sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++) {
		int len, x, ret = -1;
		scanf("%d %d", &len, &x);
		for (int j = 1; j <= n; j++)
			if (a[j] % k10[len] == x) {
				ret = a[j];
				break;
			}
		printf("%d\n", ret);
	}
	return 0;
}
