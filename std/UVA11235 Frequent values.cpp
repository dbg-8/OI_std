#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int m, n = 0, l[100003], r[100003], id[100003];
int d[100003][103];
inline void init() {
	for (int i = 1; i <= n; i++)
		d[i][0] = r[i] - l[i] + 1;
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= m; i++)
			d[i][j] = max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
	return;
}
inline int query(int L, int R) {
	int k = 0;
	while (1 << (k + 1) <= R - L + 1)
		k++;
	return max(d[L][k], d[R - (1 << k) + 1][k]);
}
int main() {
	int q;
	while (~scanf("%d", &m) && m) {
		n = 0;
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(id, 0, sizeof(id));
		memset(d, 0, sizeof(d));
		scanf("%d", &q);
		int last = -100003;
		for (int i = 1; i <= m; i++) {
			int x;
			scanf("%d", &x);
			if (x != last)
				r[n] = i-1, l[++n] = i, last = x;
			id[i] = n;
		}
		init();
		while (q--) {
			int L, R;
			scanf("%d %d", &L, &R);
			if (id[L] == id[R])		// 只能分成一部分 
				printf("%d\n", R - L + 1);
			else if (id[L] + 2 <= id[R]) 		// 可以分成三部分
				printf("%d\n", max(query(id[L] + 1, id[R] - 1), max(r[id[L]] - L + 1, R - l[id[R]] + 1)));
			else		// 只能分成两部分 
				printf("%d\n", max(r[id[L]] - L + 1, R - l[id[R]] + 1));
		}
	}
	return 0;
}
