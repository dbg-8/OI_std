#include <stdio.h>
#include <algorithm>
#include <queue>

int n;
int a[1003][1003];
int d[1003];
int f[1003];
struct NODE {
	int id;	// ห๙ส๔สýื้
	int val;
	const inline bool operator < (const NODE &rhs) const {
		return rhs.val < val;
	} 
} ;
inline NODE nn (const int &x, const int &y)	{ NODE nd; nd.id = x, nd.val = y; return nd; } 

inline void kagari () {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		std:: sort(a[i] + 1, a[i] + n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = n; j >= 2; j--)
			a[i][j] = a[i][j] - a[i][j - 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			printf("~%d%c", a[i][j], j == n ? '\n' : ' '); 

	std:: priority_queue < NODE > q;
	int sum = 0;
	for (int i = 1; i <= n; i++) 
		sum += a[i][1],
		f[i] = 2,
		q.push(nn(i, a[i][2]));
	for (int i = 1; i <= n; i++) {
		int j = q.top().id, x = q.top().val;	q.pop();
		printf("%d ", sum);
		sum = sum + x;
		q.push(nn(j, a[j][++f[j]]));
		printf("~~%d %d %d %d\n", sum, x, j, f[j]);
	}
	printf("\n");
	return;
}

int main () {
	while (~scanf("%d", &n))
		kagari();
	return 0;
}
