#include <stdio.h>
#include <algorithm>
#define ri register int
#define max(x, y) (x > y ? x : y)

struct NODE {
	int val;
	int id;
	inline const bool operator < (const NODE &rhs) const {
		return rhs.val == val ? rhs.id > id : rhs.val > val;
	}
	inline const bool operator == (const NODE &rhs) const {
		return rhs.val == val;
	}
} dd[40003];
#define x(i) dd[i].val
#define id(i) dd[i].id
#define pr(i) pri[i]
int n, m;
int ans[40003][4];
int pri[40003];
#define ada(a, b, c, d) ans[a][0]++, ans[b][1]++, ans[c][2]++, ans[d][3]++

inline int f2 (int x, int l, int r) {	// 寻找 x(l) ~ x(r) 中第一个 > x 的节点的编号 
	#define mid (l + r >> 1)
	while (l < r) {
		if (x(mid) > x)
			r = mid;
		 else
		 	l = mid + 1;
	}
	return l;
}
inline int f3 (int x, int l, int r) {	// 寻找 x(l) ~ x(r) 中第一个 = x 的节点的编号 
	#define mid (l + r >> 1)
	while (l < r) {
		if (x(mid) >= x)
			r = mid;
		 else
		 	l = mid + 1;
	}
	return l;
}

int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &x(i)), id(i) = i;
	std:: sort(dd + 1, dd + m + 1);
	
	for (int i = 1; i <= m; i++)
		if (i != 1 && x(i) == x(i - 1))
			pr(id(i)) = pr(id(i - 1));
		else
			pr(id(i)) = id(i);
	int om = m;	
//	for (ri i = 1; i <= om; i++)
//		printf("\t %d %d %d %d\n", i, x(i), id(i), pr(i));
	m = std:: unique(dd + 1, dd + m + 1) - dd;
	for (ri a = 1; a <= m; a++)
		for (ri b = f2(x(a), a + 1, m); b <= m; b++)
			for (ri c = f2(4 * x(b) - 3 * x(a), f2(x(b), b + 1, m), m); c <= m; c++)
				if ((x(b) - x(a) + 2 * x(c)) % 2 == 0)
					for (ri d = f3((x(b) - x(a) + 2 * x(c)) / 2, f2(x(c), c + 1, m), m); d <= m && 2 * x(d) == (x(b) - x(a) + 2 * x(c)); d++)
						ada(id(a), id(b), id(c), id(d));
	for (int i = 1; i <= om; i++)
		for (int j = 0; j < 4; j++)
			printf("%d%c", ans[pr(i)][j], j == 3 ? '\n' : ' ');
	return 0;
} 
