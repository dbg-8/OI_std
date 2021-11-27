#include <stdio.h>
#include <algorithm>
#include <stack>
#include <set>

struct NODE {
	int id;
	int val;
	std:: stack < int > eatt;
	const inline bool operator < (const NODE &rhs) const {
		return rhs.val == val ? rhs.id < id : rhs.val < val;
	}
} nd;
inline NODE nn (int id, int val) {
	nd.id = id, nd.val = val;
	while (!nd.eatt.empty())
		nd.eatt.pop();
	return nd;
}

int t;
int n;
int a[1000003];

inline void sovle () {
	std:: multiset <NODE> q;
	for (int i = 1; i <= n; i++)
		q.insert(nn(i, a[i]));
	int ans = 1;
	int cnt = n - 1;
	while (q.size() > 1) {
		printf("*** first id = %d, val = %d\n", (*q.begin()).id, (*q.begin()).val);
		std:: set <NODE> :: iterator ien = q.end(); ien--;
		if (!(*ien).eatt.empty()) {
			ans = std:: min(ans, (*ien).eatt.top());
			if ((*ien).eatt.empty())
				break;
			nd = (*ien);	q.erase(ien);
			nd.eatt.pop();
			q.insert(nd);
			ien = q.end(); ien--;
		}
		nd = *q.begin();
		nd.eatt.push(cnt + 1), nd.val -= (*ien).val;
		q.erase(ien);
		q.erase(q.begin());
		q.insert(nd);
		cnt--;
	}
	printf("%d\n", ans);
}

inline void kagari () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	sovle();
}

inline void tatara_kogasa () {
	int k;
	scanf("%d", &k);
	while (k--) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x] = y;
	}
	sovle();
}

int main() {
	scanf("%d", &t);
	kagari();
	while (--t)
		tatara_kogasa();
	return 0;
} 
