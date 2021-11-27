#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ci const int &

struct QUERY {
	int l, r;
	int p;
} q[200003];

int n, m;
int sn;
int curl, curr;
int sum;
int a[200003];
int cnt[1000003];
int ans[200003];

inline bool cmp (const QUERY &a, const QUERY &b) {
	return a.l / sn == b.l / sn ? a.r < b.r : a.l < b.l;
}

inline void add (ci pos) {
	cnt[a[pos]]++;
	if (cnt[a[pos]] == 1) 
		sum++;
	return;
}
inline void del (ci pos) {
	cnt[a[pos]]--;
	if (cnt[a[pos]] == 0) 
		sum--;
	return;
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &q[i].l, &q[i].r), q[i].p = i;
	sn = sqrt(n);
	std:: sort(q + 1, q + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int l = q[i].l, r = q[i].r;
		while (curl < l)
			del(curl++);
		while (l < curl)
			add(--curl);
		while (curr < r)
			add(++curr);
		while (r < curr)
			del(curr--);
		ans[q[i].p] = sum;
	}
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
} 
