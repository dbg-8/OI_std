#include <stdio.h>
#include <math.h>
#include <algorithm> 
#define ci const int &

int n, m;
int sn;				// =sqrt(n), 分块用 
int curl, curr;		// 当前区间 
int sum = 0;		// 当前区间的答案 
int a[100003];
int cnt[100003];	// 对于每个数 x 在当前区间[curl, curr]中出现的次数 
bool ans[100003];

struct QUERY {
	int l, r;	// 询问所对应区间 
	int p;		// 询问的编号 
} q[100003]; 

// 分成 sqrt(n) 个块后按左端点排序, 若左端点所在块相同则按右端点排序 
inline bool cmp (const QUERY &x, const QUERY &y) {
	return x.l / sn == y.l / sn ? x.r < y.r : x.l < y.l;  
}

inline void add (ci pos) {		// 区间增加节点 pos 
	cnt[a[pos]]++; 
	if (cnt[a[pos]] == 1)
		sum++;
	return;
}
inline void del (ci pos) {		// 区间删去节点 pos 
	cnt[a[pos]]--;
	if (cnt[a[pos]] == 0)
		sum--;
	return;
}

int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &q[i].l, &q[i].r), q[i].p = i;

	sn = sqrt(n);
	std:: sort(q + 1, q + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int l = q[i].l, r = q[i].r;
		while (curl < l)
			del(curl++);
		while (curl > l)
			add(--curl);
		while (curr < r)
			add(++curr);
		while (curr > r)
			del(curr--);
		if (sum == (r - l + 1))
			ans[q[i].p] = true; 
	}

	for (int i = 1; i <= m; i++)
		printf("%s\n", ans[i] == true ? "Yes" : "No");
	return 0;
}
