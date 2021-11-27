#include <stdio.h>
#include <algorithm>

int n, m;
int ci[500003];
struct NODE {
	int l, r;
	int lm, rm, mm, sm;
} a[2000003];

inline void upload (NODE &q, NODE x, NODE y) {
	q.lm = std:: max(x.lm, x.sm + y.lm);
	q.rm = std:: max(y.rm, y.sm + x.rm);
	q.mm = std:: max(x.rm + y.lm, std:: max(x.mm, y.mm));
	q.sm = x.sm + y.sm;
	return;
}

inline void build (int p, int l, int r) {
	a[p].l = l, a[p].r = r;
	if (l == r) {
		a[p].lm = a[p].rm = a[p].mm = a[p].sm = ci[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	upload(a[p], a[p << 1], a[p << 1 | 1]);
	return;
}

inline void change (int p, int to, int x) {
	int l = a[p].l, r = a[p].r;
	if (l == r) {
		a[p].lm = a[p].rm = a[p].mm = a[p].sm = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (to <= mid)
		change(p << 1, to, x);
	else
		change(p << 1 | 1, to, x);
	upload(a[p], a[p << 1], a[p << 1 | 1]);
	return;
}

inline NODE query (int p, int l, int r) {
	if (l <= a[p].l && a[p].r <= r) 
		return a[p];
	int mid = (a[p].l + a[p].r) >> 1;
	if (l <= mid && mid < r) {
		NODE ans;
		upload(ans, query(p << 1, l, r), query(p << 1 | 1, l, r));
		return ans;
	}
	else if (l <= mid)
		return query(p << 1, l, r);
	else
		return query(p << 1 | 1, l, r);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &ci[i]);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			NODE ans = query(1, std:: min(b, c), std:: max(b, c));
			printf("%d\n", ans.mm);
		}
		else
			change(1, b, c);
	}
	return 0;
}
