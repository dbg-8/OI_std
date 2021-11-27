#include <stdio.h>
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) < (y) ? (y) : (x))

int n, m;
int a[1000003];
int ans1[1000003], ans2[1000003];
struct NODE {
	int l, r;
	int x;
	int minx;
	int maxx;
	#define l(p) tr[p].l
	#define r(p) tr[p].r
	#define x(p) tr[p].x
	#define mi(p) tr[p].minx
	#define ma(p) tr[p].maxx
} tr[4000003];
#define lc (p << 1)
#define rc ((p << 1) + 1)
#define mid (l + r >> 1)
#define ls lc, l, mid
#define rs rc, mid + 1, r

#define stdate(p, xc) x(p) = mi(p) = ma(p) = xc
#define upload(p) mi(p) = min(mi(lc), mi(rc)), ma(p) = max(ma(lc), ma(rc))
inline void build (int p, int l, int r) {
	l(p) = l, r(p) = r;
	if (l == r) {
		stdate(p, a[l]);
		return;
	}
	build(ls);
	build(rs); 
	upload(p);
	return;
}
inline void change (int p, int where, int xc) {
	int l = l(p), r = r(p);
	if (where < l || r < where)
		return;
	if (l == r) {
		stdate(p, xc);
		return;
	}
	change(lc, where, xc);
	change(rc, where, xc);
	upload(p);
	return;
}

int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, m);
	ans1[1] = mi(1), ans2[1] = ma(1);
	for (int i = 2; i <= n - m + 1; i++) {
		change(1, (i - 2) % m + 1, a[i + m - 1]);
		ans1[i] = mi(1), ans2[i] = ma(1);
	}
	for (int i = 1; i <= n - m + 1; i++)
		printf("%d%c", ans1[i], i == n - m + 1 ? '\n' : ' ');
	for (int i = 1; i <= n - m + 1; i++)
		printf("%d%c", ans2[i], i == n - m + 1 ? '\n' : ' ');
	return 0;
}
