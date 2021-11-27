#include <stdio.h>
#include <algorithm>

int n;
int a[100003], b[100003];
int d[100003];

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a[x] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[b[i]] > a[d[ans]])
			d[++ans] = b[i];
		else {
			int l = 1, r = ans;
			while (l < r) {
				int mid = (l + r) / 2;
				if (a[d[mid]] <= a[b[i]])
					l = mid + 1;
				else
					r = mid;
			}
			d[l] = b[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
