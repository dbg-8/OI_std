#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 46345;
typedef long long ll;
int p[MAXN],cnt,l,r,m;
bool v[1000001];
int b[1000001];

void prime() {
	memset(v, 1, sizeof(v));
	for (int i = 2; i <= MAXN; i++)
		if (v[i]){
			p[++cnt] = i;
			for (int j = 2; j <= 46340 / i; j++) v[i*j] = false;
		}
}

int main() {
	prime();
	while (cin >> l >> r) {
		memset(v, 1, sizeof(v));
		if (l == 1) v[0] = false;
		for (ll i = 1; i <= cnt; i++)
			for (ll j = l / p[i]; j <= r / p[i]; j++) {
				if (p[i] * j - l < 0)continue;//?里不加，poj?不了
				if (j > 1) v[p[i] * j - l] = false;
			}
		m = 0;
		for (ll i = l; i <= r; i++){//?里一定要?ll的i，要不然溢出了就会死循?
			if (v[i - l]) b[++m] = i;
		}
		ll t1 = 2147483647; ll t2 = 0;
		ll x1, x2, y1, y2;
		for (ll i = 1; i<m; i++){
			ll cha = b[i + 1] - b[i];
			if (cha<t1) { t1 = cha; x1 = b[i]; y1 = b[i + 1]; }
			if (cha>t2) { t2 = cha; x2 = b[i]; y2 = b[i + 1]; }
		}
		if (!t2) cout << "There are no adjacent primes.\n";
		else cout << x1 << ',' << y1 << " are closest, " << x2 << ',' << y2 << " are most distant.\n";
	}
	return 0;
}
