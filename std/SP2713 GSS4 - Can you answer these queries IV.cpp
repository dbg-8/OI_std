#include <stdio.h>
#include <math.h>
#define ll long long

int n, m;
ll a[100003];
struct NODE {
	int l, r;
	ll sum;
	#define l(p) tr[p].l
	#define r(p) tr[p].r
	#define sum(p) tr[p].sum
} tr[400003];
#define lc (p << 1)
#define rc ((p << 1) | 1)
#define mid ((l + r) >> 1)
#define lt lc, l, mid
#define rt rc, mid + 1, r

inline void upload (int p) {
	sum(p) = sum(lc) + sum(rc);
	return;
}

inline void build (int p, int l, int r) {
	l(p) = l, r(p) = r;
	if (l == r) {
		sum(p) = a[l];
		return;
	}
	build(lt);
	build(rt);
	upload(p);
	return;
}

inline void change (int p, int wl, int wr) {
	int l = l(p), r = r(p);
	if (r < wl || wr < l)
		return;
	if (sum(p) <= (r - l + 1))
		return;
	if (l == r) {
		sum(p) = sqrt(sum(p));
		return;
	}
	change(lc, wl, wr);
	change(rc, wl, wr);
	upload(p);
	return;
}

inline ll query (int p, int wl, int wr) {
	int l = l(p), r = r(p);
	if (r < wl || wr < l)
		return 0;
	if (wl <= l && r <= wr)
		return sum(p);
	ll ret = 0;
	ret += query(lc, wl, wr);
	ret += query(rc, wl, wr);
	return ret;
}

inline void sovle (int t) {
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	build(1, 1, n);
	printf("Case #%d:\n", t);
	scanf("%d", &m);
	while (m--) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (y > z)
			y ^= z, z ^= y, y ^= z;
		if (x == 0) 
			change(1, y, z);
		else
			printf("%lld\n", query(1, y, z));
	}
	printf("\n");
}
int main () {
	int t = 0;
	while (~scanf("%d", &n))
		sovle(++t);
	return 0;
}
