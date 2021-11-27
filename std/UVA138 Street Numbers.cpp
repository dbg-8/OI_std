#include <stdio.h>
#define ll long long
#define sp(x, y) (((y) - (x) + 1) *((x) + (y)) >> 1ll)

ll n = 1, m = 2;

inline void sovle () {
	A:
	n++;
	while (1) {
		if (sp(n + 1ll, m) >= sp(1ll, n - 1ll))
			break;
		m++;
	}
	if (sp(1ll, n - 1ll) != sp(n + 1ll, m))
		goto A;
	printf("%10lld%10lld\n", n, m);
	return;
}

int main () {
	int t = 10;
	while (t--)
		sovle(),
		n++;
	return 0;
}
