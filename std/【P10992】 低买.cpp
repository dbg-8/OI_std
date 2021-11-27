#include <stdio.h>
#include <algorithm>

int n;
int a[5003];
int d[5003];
int h[5003];
int ans1 = 0, ans2 = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), d[i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++)
			if (a[j] > a[i])
				d[i] = std:: max(d[i], d[j] + 1);
		for (int j = 1; j < i; j++)
			if (a[j] == a[i] && d[j] == d[i])
				h[j] = 0; 
			else if (a[j] > a[i] && d[j] + 1 == d[i])
				h[i] += h[j];
		ans1 = std:: max(ans1, d[i]);
		if (d[i] == 1)
			h[i] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (ans1 == d[i])
			ans2 += h[i];
	printf("%d %d", ans1, ans2);
	return 0;
}
