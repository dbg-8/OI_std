#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

int n, m;
int s[1003];
int d[1003];

struct NODE {
	int v, k, c, l;
	const inline bool operator < (const NODE &rhs) const {
		return v < rhs.v;
	}
} a[1003];

inline void kagari () {
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d %d", &a[i].v, &a[i].k, &a[i].c, &a[i].l),
		s[i] = s[i - 1] + a[i].l;
	std:: sort(a + 1, a + n + 1);
	d[0] = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= i; j++)
			d[i] = std:: min(d[i], d[j] + (s[i] - s[j]) * a[i].c + a[i].k);
	printf("%d\n", d[n]);
	return;
}

int main () {
	while (std:: cin >> n && n) 
		kagari();
	return 0;
}
