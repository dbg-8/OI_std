#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define ll long long
#define lowbit(x) x & (-x)
using namespace std;
struct NODE {
	int val, id;
} a[20003], b[20003];
inline bool cmp (const NODE &x, const NODE &y) {
	return x.val == y.val ? x.id > y.id : x.val < y.val;
}
int n, ranks[20003], score[20003], c[20003], d[20003];
inline int query(int x, int *c) {
	int ans = 0;
	while (x)
		ans += c[x], x -= lowbit(x);
	return ans;
}
inline void add (int x, int y, int *c) {
	while (x <= n)
		c[x] += y, x += lowbit(x);
	return;
}
inline ll sovle() {
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
	memset(score, 0, sizeof(score)); 
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ranks[b[i].id] = i;		// ? i ????? 
	for (int i = 1; i <= n; i++) {		// ?? for ?????? ranks[i] 
		// ?? a < b ? s[a] < s[b] ??? 
		score[ranks[i]] = query(ranks[i] - 1, c);
		add(ranks[i], 1, c);
		// ?? b < c ? s[b] < s[c] ??? 
		ans += query(ranks[i] - 1, d);
		add(ranks[i], score[ranks[i]], d);
	}
	return ans;
}
int main() {
	int t = 1;
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i].val), a[i].id = i;
		sort(a + 1, a + n + 1, cmp);
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			b[i] = a[i];
		printf("%lld\n", sovle());
		for (int i = 1; i <= n; i++)
			b[i] = a[n - i + 1];
		ans += sovle();		// ????? 
		printf("%lld\n", ans);
	}
	return 0;
}
