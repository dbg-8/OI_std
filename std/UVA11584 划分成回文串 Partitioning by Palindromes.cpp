#include <stdio.h>
#include <string.h> 
#include <algorithm>

char str[1003];
int d[1003];
bool ish[1003][1003];

inline void kagari () {
	memset(ish, false, sizeof(ish));
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for (int i = 1; i <= n; i++)
		ish[i][i] = true;
	for (int i = 1; i < n; i++)
		ish[i][i + 1] = (str[i] == str[i + 1] ? true : false);
	#define r  l + len - 1
	for (int len = 3; len <= n; len++)
		for (int l = 1; r <= n; l++) {
			if (str[l] != str[r])
				continue;
			ish[l][r] = ish[l + 1][r - 1];
		}
	memset(d, 0x3F, sizeof(d));
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 0; j < i; j++)
			if (ish[j + 1][i])
				d[i] = std:: min(d[i], d[j] + 1);
	}
	printf("%d\n", d[n]);
}

int main () {
	int t;
	scanf("%d", &t);
	while (t--)
		kagari();
	return 0;
}
