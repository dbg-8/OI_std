#include <stdio.h>
#include <algorithm>
#include <string.h>
 
int n;
int a[103];
int d[25003];

inline void kagari () {
	memset(d, 0, sizeof(d));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	std:: sort(a + 1, a + n + 1);
	int ans = 0;
	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (d[a[i]] == 0)
			ans++;
		d[a[i]] = 1;
		for (int j = a[i]; j <= a[n]; j++)
			if (d[j - a[i]])
				d[j] = 1;
	}
	printf("%d\n", ans);
}

int main () {
	int t;
	scanf("%d", &t);
	while (t--)
		kagari();
	return 0;
} 
