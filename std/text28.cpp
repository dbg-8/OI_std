#include <stdio.h>
int n;
bool np[1000003];
int ans[1000003], cnt = 0;
inline void sovle () {
	for (int i = 2; i <= n; i++) {
		if (np[i] == true)
			continue;
		ans[++cnt] = i;
		for (int j = 2; j * i <= n; j++)
			np[i * j] = true;
	}
}

int main () {
	n = 1e6;
	sovle();
//	freopen("text28.out", "w", stdout);
//	for (int i = 1; i <= cnt; i++)
//		printf("%d, ", ans[i]);
printf("%d\n", cnt);	return 0;
}
