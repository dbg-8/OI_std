#include <stdio.h>
#include <algorithm>
#include <deque>

struct NODE {
	int p, l, s;
} a[16003];

int m, n, d[103][16003];
std:: deque <int> q;

inline bool cmp (const NODE &x, const NODE &y) {
	return x.s < y.s;
}

int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &a[i].l, &a[i].p, &a[i].s);
	std:: sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		for (int j = std:: max(a[i].s - a[i].l, 0); j < a[i].s; j++) {
			while (!q.empty() && d[i - 1][q.back()] - a[i].p * q.back() <= d[i - 1][j] - a[i].p * j)
				q.pop_back();
			q.push_back(j);
		}
		for (int j = 1; j <= n; j++) {
			d[i][j] = std:: max(d[i - 1][j], d[i][j - 1]);
			if (j >= a[i].s) {
				while (!q.empty() && q.front() < j - a[i].l)
					q.pop_front();
				if (!q.empty())
					d[i][j] = std:: max(d[i][j], a[i].p * j + d[i - 1][q.front()] - a[i].p * q.front());
			}
		}
	}
	printf("%d\n", d[m][n]);
	return 0;
}
