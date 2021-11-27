#include <stdio.h>
#include <algorithm>
#define min(x, y) ((x) < (y) ? (x) : (y))

int n;
int a[100003];
int ans = 100003;

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	std:: sort (a + 1, a + n + 1);
	int l = 1;
	while (l <= n) {
		int m = std:: unique(a + l, a + n + 1);
		int pp = 1;
		for (int i = l + 1; i <= m; i++) {
			if (a[i + 1] + 1 != a[i])
				ans = min(ans, pp),
				pp = 0;
			pp++;
		}
		l = m + 1;
	}
	printf("%d\n", ans);
	return 0;
}
