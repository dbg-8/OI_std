#include <stdio.h>

int L, n, m;
int a[50005], b[50005];

inline bool check (int mid) {
	int ret = 0;
	for (int i = 1; i <= n; i++)
		a[i] = b[i];
	for (int i = 1; i < n; i++)
		if (a[i] - a[i - 1] < mid)
			ret++, a[i] = a[i - 1];	// ÒÆ³ı stone i
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] != b[i])
			continue;
		if (a[n] - a[i] >= mid)
			break;
		ret++, a[i] = a[i - 1];
	}
	return ret <= m;
}

int main () {
	scanf("%d %d %d", &L, &n, &m);
	b[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	b[++n] = L;
	int l = 1, r = L;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (l + 1 == r)
			break;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	if (check(r))
		printf("%d\n", r);
	else
		printf("%d\n", l);
	return 0;
} 
