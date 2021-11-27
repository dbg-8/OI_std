#include <stdio.h>
#include <ctype.h>
#define ll long long

const ll MODN = 1e9 + 7;

int n, m;
ll a[103];
int ans = 0, anss[1000003];
char ch;

inline ll scan () {
	ll x = 0ll, f = 1ll;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-')
			f = -1ll;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = ((x << 1) % MODN + (x << 3) % MODN + ch - '0') % MODN;
		ch = getchar();
	}
	return x * f;
}

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i <= n; i++)
		a[i] = scan();
	for (register ll i = 1ll; i <= m; i++) {
		ll sum = 0ll;
		for (register int j = n; j >= 1; j--) 
			sum = (sum + a[j]) * i % MODN;
		sum = (sum + a[0]) % MODN;
		if (sum == 0ll)
			anss[++ans] = i;
	} 
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++)
		printf("%d\n", anss[i]);
	return 0;
} 
