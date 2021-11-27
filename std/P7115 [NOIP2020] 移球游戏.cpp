#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define sz(i) a[i][0]
#define top(i) a[i][sz(i)]
#define pop(i) (--sz(i))
#define push(x, i) a[i][++sz(i)] = x

int n, m;
int a[53][403];
int his[820003][2], ans = 0;
#define ada(x, y) his[++ans][0] = x, his[ans][1] = y
int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]), sz(i)++;
	srand(time(NULL));
	while (1) {
		for (int i = 1; i <= n; i++) {
			int wt = 1;
			wt = rand() % (n + 1) + 1;
			for (int j = 1; j <= n + 1; j++) {	// Ã¶¾ÙÎ»ÖÃ 
				if (j == wt)
					continue;
				while (sz(j) != 0) {
					if (sz(wt) == m)
						break;
					if (top(j) == i)
						ada(j, wt),
						push(top(j), wt), pop(j);
					else
						break;
				}
			}
		} 
		bool flag = true;
		for (int i = 1; i <= n + 1; i++) {
			if (sz(i) == 0)
				continue;
			if (sz(i) != m)
				flag = false;
			for (int j = 2; j <= m; j++)
				if (a[i][j - 1] != a[i][j])
					flag = false;
		}
		if (flag)
			break;
	//	printf("~~%d\n", ans);
	}
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++)
		printf("%d %d\n", his[i][0], his[i][1]);
	return 0;
}
