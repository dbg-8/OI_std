#include <stdio.h>
#define ci const int &

int n;
int a[53]; 
int d[53][53];
int root[53][53];

inline void print2 (ci l, ci r) {
	if (l > r || r < 1 || l > n)
		return;
	if (l == r) {
		printf("%d ", l);
		return;
	}
	printf("%d ", root[l][r]);		// 根 
	print2(l, root[l][r] - 1);		// 左
	print2(root[l][r] + 1, r);		// 右 
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), d[i][i] = a[i], root[i][i] = i;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1; 
			
			// 情况 1, l 为根, 左子树为空 
			d[l][r] = d[l + 1][r] + d[l][l];
			root[l][r] = l;
			
			// 情况 2, i 为根, i∈(l,r) 
			for (int i = l + 1; i < r; i++)
				if (d[l][i - 1] * d[i + 1][r] + d[i][i] > d[l][r]) { 
					d[l][r] = d[l][i - 1] * d[i + 1][r] + d[i][i];
					root[l][r] = i; 
				} 
		}
	}
	printf("%d\n", d[1][n]);
	print2(1, n);
	printf("\n");
	return 0;
}
