#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
int n, m;
char ch[100003];
int ans = 0;
int main() {
	scanf("%d %d ", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%c", &ch[i]);
	int a = 0, b = 0, l = 0, r = 0;
	for (l = 1; l <= n; l++) {
		while (1) {
			if (r == n)
				break;
			if (ch[r + 1] == 'a') {
				if ((a + 1) > m && b > m)
					break;
				a++;
			}
			else {
				if (a > m && (b + 1) > m)
					break;
				b++;
			}
			r++;
		}
		ans = max(ans, r - l + 1);
		if (ch[l] == 'a')
			a--;
		else
			b--;
	}
	printf("%d\n", ans);
	return 0;
}
