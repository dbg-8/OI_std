#include <stdio.h>
#include <algorithm>
#define ll long long

ll n, w, h;
ll m;
ll row[20003];

struct STAR {
	ll x, y;
	ll q;
	ll val;
	inline const bool operator < (const STAR &rhs) const {
		return x == rhs.x ? val < rhs.val : x < rhs.x;
	}
} st[20003];

struct NODE {
	ll l, r;
	ll sum, lazy;
} t[80003];
#define l(p) t[p].l	
#define r(p) t[p].r
#define sum(p) t[p].sum
#define lazy(p) t[p].lazy
#define mid ((t[p].l + t[p].r) >> 1)
#define lc (p << 1)	
#define rc (p << 1 | 1)
#define lt lc, l(p), mid
#define rt rc, mid + 1, r(p)

inline void build (int p, int l, int r) {
	l(p) = l, r(p) = r;
	sum(p) = lazy(p) = 0;
	if (l == r)
		return;
	build(lt);
	build(rt);
	return; 
}
inline void download (const int &p) {
	lazy(lc) += lazy(p);
	lazy(rc) += lazy(p);
	sum(lc) += lazy(p);
	sum(rc) += lazy(p);
	lazy(p) = 0;
	return;
} 
inline void change (int p, const int &l, const int &r, const int &x) {
	if (l <= l(p) && r(p) <= r) {
		sum(p) += x;
		lazy(p) += x;
		return;
	}
	if (lazy(p))
		download(p);
	if (l <= mid)
		change(lc, l, r, x);
	if (r > mid)
		change(rc, l, r, x);
	sum(p) = std:: max(sum(lc), sum(rc));
	return;
} 

void sovle() {
	scanf("%d %d %d", &n, &w, &h);
	for (int i = 1; i <= n; i++) {
		int j = i << 1;
		scanf("%lld %lld %lld", &st[j - 1].x, &st[j - 1].y, &st[j - 1].val);
		st[j].x = st[j - 1].x + w;
		row[j - 1] = st[j].y = st[j - 1].y;
		row[j] = st[j - 1].q = st[j].q = st[j].y + h - 1;
		st[j].val = -st[j - 1].val;
	}
	n = n << 1;
	std:: sort(st + 1, st + n + 1);
	std:: sort(row + 1, row + n + 1);
	m = std:: unique(row + 1, row + n + 1) - (row + 1);
	for (int i = 1; i <= n; i++) {
		st[i].y = std:: lower_bound(row + 1, row + m + 1, st[i].y) - row;
		st[i].q = std:: lower_bound(row + 1, row + m + 1, st[i].q) - row;
	}
	build(1, 1, m);
	ll ans = 0;
	
	for (int i = 1; i <= n; i++) {
		change(1, st[i].y, st[i].q, st[i].val);
		ans = std:: max(ans, sum(1));
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		sovle();
	return 0;
}
