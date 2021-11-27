#include <stdio.h>
#define min(x, y) ((x) < (y) ? (x) : (y))

int k;
int c[2003][2003];
int ans[2003][2003];

inline void init () {
	for (int i = 0; i <= 2000; i++) {
		c[i][0] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
		c[i][i] = 1;
	}
}

int main () {
	int t;
	scanf("%d %d", &t, &k);
	init();
	for (int i = 1; i <= 2000; i++)
		for (int j = 1; j <= 2000; j++)
			ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + (c[i][j] == 0 && j <= i ? 1 : 0);
	while (t--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", ans[x][y]);
	}
	return 0;
} 
