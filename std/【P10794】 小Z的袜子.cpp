#include <stdio.h>
#include <math.h>
#include <algorithm> 
#define ll long long

struct QUERY {
	int l, r, p;
} q[50003]; 
inline bool cmp1 (const QUERY &a, const QUERY &b) {
	return a.l == b.l ? a.r < b.r : a.l < b.l;
}
inline bool cmp2 (const QUERY &a, const QUERY &b) {
	return a.r < b.r;
}

inline void work (int x, int w) {
	sum -= a[]
}

inline ll gcd (ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}
inline void mathsovle (ci tid, ci l, ci r) {
	ans[tid][0] = sum;
	ans[tid][1] = (ll)(r - l) * (r - l + 1);
	g = gcd(ans[tid][0], ans[tid][1]);
	if (!g) ans[tid][1] = 1;
	else {
		ans[tid][0] /= g;
		ans[tid][1] /= g;
	}
	return;
}
int main() {
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &q[i].l, &q[i].r), q[i].p = i;
	std:: sort (q + 1, q + m + 1, cmp);
	sn = sqrt(m);
	for (int i = 1; i <= sn; i++) {
		curl[i] = (i - 1) * sn + 1;
		curr[i] = i * sn;
	}
	if (curr[sn] < m) {
		curl[sn + 1] = curr[sn] + 1;
		curr[++sn] = m;
	}
	for (int i = 1; i <= sn; i++) {
		std:: sort(q + curl[i], q + curr[i], cmp2);
		memset(num, 0, sizeof(num));
		sum = 0;
		int l = q[curl[i]].l, r = q[curr[i]].r;
		for (int j = l; j <= r; j++)
			work(a[j], 1);
		ans[q[curl[i]].p][0] = sum;
		ans[q[curl[i]].p][1] = (ll)(r - l) * (r - l + 1);
		
		g = gcd(ans[q[curl[i]].p][0], ans[q[curl[i]].p][1]);
		if (g == 0)
			ans[q[cirl[i]].id][1] = 1;
		else {
			ans[q[curl[i]].p][0] /= g;
			ans[q[curl[i]].p][0] /= g;
		}
		
		for (int j = curl[i] + 1; j <= curr[i]; j++) {
			while (r < q[j].r)
				work(a[++r], 1);
			while (q[j].r < r)
				work(a[r--], -1);
			while (l < q[j].l)
				work(a[l++], -1);
			while (q[j].l < l)
				work(a[--l], 1);
		}
	}
}
