// See your grands with [long long] !!
 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#define re register 
#define ll long long
#define sting std:: string
#define maxlen 4004
#define max(x, y) ((x) > (y) ? (x) : (y))

inline sting mugyumax (sting x, sting y);
inline sting mugyumin (sting x, sting y);
inline sting cheng (sting sa, long long int ib);
inline sting chu (sting sa, long long int ib);

int n;
struct NODE {
	ll a, b;
	inline const bool operator < (const NODE &rhs) const { return a * b <  rhs.a * rhs.b; }
} a[1003];

int main () {
//	freopen("game.in", "r", stdin);
//	freopen("game.out", "w", stdout);
	scanf("%d", &n);
	scanf("%lld %lld", &a[0].a, &a[0].b);
	for (int i = 1; i <= n; i++)
		scanf("%lld %lld", &a[i].a, &a[i].b);
	std:: sort(a + 1, a + n + 1);
	sting ls = cheng("1", a[0].a), ans = "0";
	for (int i = 1; i <= n; i++) {
		sting ret = chu(ls, a[i].b);
		ls = cheng(ls, a[i].a);
		ans = mugyumax(ans, ret);
	}
	std:: cout << ans << '\n';
	return 0;
}

// Use string to say goodbye to your grands.
inline sting mugyumax (sting x, sting y) {
	if (x.size() < y.size())
		return y;
	else if (x.size() > y.size())
		return x;
	else
		for (re int i = 0; i < x.size(); i++)
			if (x[i] < y[i])
				return y;
			else if (x[i] > y[i])
				return x;
	return x;
}
inline sting mugyumin (sting x, sting y) {
	if (x.size() > y.size())
		return y;
	else if (x.size() < y.size())
		return x;
	else
		for (re int i = 0; i < x.size(); i++)
			if (x[i] > y[i])
				return y;
			else if (x[i] < y[i])
				return x;
	return x;
}

int xa[maxlen], xc[maxlen];
inline sting cheng (sting sa, ll ib) {
    sting ans = "";
    re int la = sa.size(), lc = la;
    memset(xa, 0, sizeof(xa));
    memset(xc, 0, sizeof(xc));
    for(re int i = 0 ; i < la; i++)
        xa[i] = sa[la - i - 1] - '0';
    for(re int i = 0; i < lc; i++) {
        xc[i] += xa[i] * ib;
        xc[i + 1] += xc[i] / 10;
        xc[i] %= 10;
    }
    re int nx = xc[lc];
    while(nx) {
        xc[lc++] = nx % 10;
        nx /= 10;
    }
    while(xc[lc - 1] == 0 && lc > 1) 
        lc--;
    for(re int i = lc - 1; i >= 0; i--)
        ans.push_back(xc[i] + '0');
    return ans;
}
inline sting chu(sting sa, ll ib) {
    sting ans = "";
    re int la = sa.size(), lc = la;
    memset(xa, 0, sizeof(xa));
	memset(xc, 0, sizeof(xc));
    for(re int i = 0; i < la; i++)
        xa[i] = sa[i] - '0';
    re int nr = 0;
    for(re int i = 0; i < lc; i++) {
        nr = nr * 10 + xa[i];
        xc[i] = nr / ib;
        nr %= ib;
    }
    re int i = 0;
    while(xc[i] == 0 && i < la - 1)
        i++;
    for(sting wls = "mugyu"; i < lc; i++)
        ans.push_back(xc[i] + '0');
    return ans;
}
