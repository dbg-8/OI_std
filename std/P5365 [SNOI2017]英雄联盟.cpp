#include <stdio.h>
#include <algorithm>
#include <string.h>
#define ll long long
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

int n;	ll m;
int a[1003];
int b[1003];
ll d[10000003];
int sum;

int main () {
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]),
		sum += a[i] * b[i];
	d[0] = 1;
	for (int i = 1; i <= n; i++) 
		for (int j = sum; j >= 1; j--)
			for (int k = 0; k <= a[i] && j - b[i] * k >= 0; k++)
				d[j] = max(d[j], d[j - b[i] * k] * k);
	for (int i = 1; i <= sum; i++)
		if (d[i] >= m) {
			printf("%d\n", i);
			return 0;
		}
	return 0;
} 
