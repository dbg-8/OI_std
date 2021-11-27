#include <stdio.h>
#include <vector>
#include <algorithm>
#define ci const int &

int n;
int a[200003];
std:: vector <int> g[200003];
int ans1 = 0, ans2 = 0; 

inline void add_edge (ci x, ci y) {
	g[x].push_back(y);
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		// 2a1a2+2a1a3+...+2an-1*2n = (a1+a2+...+an)^2 - (a1^2+a2^2+...+an*2)
		int max1 = 0, max2 = 0, sum = 0, msum = 0;
		for (int j = 0; j < g[i].size(); j++) {
			int x = a[g[i][j]];
			if (x > max1)
				max2 = max1, max1 = x;
			else if (x > max2)
				max2 = x;
			sum = (sum + x) % 10007;
			msum = (msum + x * x) % 10007;
		}
		ans1 = std:: max(ans1, max1 * max2);
		if (g[i].size() >= 2)
			ans2 = (ans2 + sum * sum - msum) % 10007;
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}
