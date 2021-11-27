#include <stdio.h>

int m, n; 
int x[1003], y[1003];

inline bool check (int mid) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			;
	}
	return true;
}


int main () {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d %d", &x[i], &y[i]);
	int l = 0, r = 10003;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
