#include <stdio.h>
#define re register
#define ll long long

bool np[1000003];
int pre[1000003], cnt = 0;
inline void getpres () {
	for (re int i = 2; i <= 1000003; i++) {
		if (np[i] == true)
			continue;
		pre[++cnt] = i;
		for (int j = 2; j * i <= 1000003; j++)
			np[i * j] = true;
	}
}

inline ll sovle (ll x) {
	register ll ret = 1e6;
	for (; ret >= 2; ret--) {
		if (x % (ret * ret * ret) == 0)
			break;
	}
	return ret;
}

int main () {
	getpres();
	int t;
	scanf("%d", &t);
	while (t--) {
		ll x;
		scanf("%lld", &x);
		ll ans = sovle(x);
		printf("%lld\n", ans);
	}
	return 0;
}
