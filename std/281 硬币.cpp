#include <stdio.h>
#include <string.h>

int n, m;
int a[103], c[103];
int bag[100003];
bool isan[100003];

inline void sovle () {
	memset(isan, 0, sizeof(isan));
	isan[0] = 1;
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &[i]);
	
	for (int i = 1; i <= n; i++) {
		memset(bag, 0, sizeof(bag));
		for (int j = a[i]; j <= m; j++)
			if (isan[j] == 0 && isan[j - a[i]] != 0 && bag[j - a[i]] < c[i]) {
				isan[j] = 1;
				bag[j] = bag[j - a[i]] + 1;
			} 
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		if (isan[i])
			ans++;
	printf("%d\n", ans);
	return;
}
int main() {
	while (~scanf("%d %d", &n, &m) && n)
		sovle();
	return 0;
}
