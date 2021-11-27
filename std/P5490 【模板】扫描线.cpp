#include <stdio.h>
#include <algorithm>
#include <map>
#define ll long long
int n, m;
int row[200003], raw[200003];
std:: map <int, int> san;
struct NODE {
	int l, r;
	int sum, len;
} t[1600003];
#define l(x) t[x].l
#define r(x) t[x].r
#define sum(x) t[x].sum
#define len(x) t[x].len
#define mid ((l(p) + r(p)) >> 1)
#define lc (p << 1)
#define rc (p << 1 | 1)
#define lt lc, l, mid
#define rt rc, mid + 1, r
inline void update (int p) {
	int l = l(p), r = r(p);
	if (sum(p))
		len(p) = row[r + 1] - row[l];
	else
		len(p) = len(lc) + len(rc);
	return;
}
inline void build (int p, int l, int r) {
	l(p) = l, r(p) = r;
	sum(p) = len(p) = 0;
	if (l == r) 
		return;
	build(lt);
	build(rt);
	return;
}
inline void change (int p, int l, int r, int x) {
	if (l <= l(p) && r(p) <= r) {
		sum(p) += x;
		update(p);
		return; 
	}
	if (l <= mid)
		change(lc, l, r, x);
	if (r > mid)
		change(rc, l, r, x);
	update(p);
	return;
}

struct LINE {
	int l, r, x;
	int val;
	const inline bool operator < (const LINE &rhs) const {
		return x < rhs.x;
	}
} line[200003];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x1, y1, x2, y2, j = i << 1;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		row[j - 1] = line[j - 1].l = line[j].l = y1;
		row[j] = line[j - 1].r = line[j].r = y2;
		line[j - 1].x = x1, line[j].x = x2;
		line[j - 1].val = 1, line[j].val = -1;
	}
	n = n << 1;
	std:: sort(row + 1, row + n + 1);
	std:: sort(line + 1, line + n + 1);
	m = std:: unique(row + 1, row + n + 1) - (row + 1);
	for (int i = 1; i <= m; i++)
		san[row[i]] = i;
	build(1, 1, m - 1);
	ll ans = 0ll;
	for (int i = 1; i < n; i++) {
		change(1, san[line[i].l], san[line[i].r] - 1, line[i].val);
		ans += (ll)len(1) * (ll)(line[i + 1].x - line[i].x);
	}
	printf("%lld\n", ans);
	return 0;
}
