#include <stdio.h>
#include <algorithm>

int n, m;
int t[5003], c[5003];
int d[5003];

int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &t[i], &c[i]), 
		t[i] = t[i - 1] + t[i],
		c[i] = c[i - 1] + c[i],
		d[i] = 0x3F3F3F3F;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			d[i] = std:: min(d[i], d[j] + (c[i] - c[j])  * t[i] + (c[n] - c[j]) * m);
	printf("%d\n", d[n]);
	return 0;
} 
