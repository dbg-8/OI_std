#include <string.h>
#include <string>
#define ll long long
using namespace std;

#define maxlen 100

struct BIGNUM {
	string a;
	inline const BIGNUM operator + (string b) {
	    string ans;
	    if(a[0] != '-' && b[0] != '-') {
	        ans = mplus(a, b);
	    } else if(a[0] == '-' && b[0] == '-') {
	        a.erase(a.begin()), b.erase(b.begin());
	        ans = '-' + mplus(a, b);
	    } else {
	        if(a[0] == '-') {
	            a.erase(a.begin());
	            ans = msubtract(b, a);
	        }
	        if(b[0] == '-') {
	            b.erase(b.begin());
	            ans = msubtract(a, b);
	        }
	    }
	    a = ans;
	    return *this;
	}
	inline string mplus(string sa, string sb) {
	    string ans = "";
	    int la = sa.size(), lb = sb.size(), lc = max(la, lb) + 1;
	    int xa[maxlen], xb[maxlen], xc[maxlen];
	    memset(xa, 0, sizeof(xa));
	    memset(xb, 0, sizeof(xb));
	    memset(xc, 0, sizeof(xc));
	    for(int i = 0; i < la; i++)
	        xa[i] = sa[la - i - 1] - '0';
	    for(int i = 0; i < lb; i++)
	        xb[i] = sb[lb - i - 1] - '0';
	    for(int i = 0; i < lc - 1; i++) {
	        xc[i] += xa[i] + xb[i];
	        xc[i+1] = xc[i] / 10;
	        xc[i] %= 10;
	    }
	    while(xc[lc-1] == 0 && lc > 0)
	        lc--;
	    for(int i = lc-1; i >= 0; i--)
	        ans.push_back(xc[i] + '0');
	    return ans;
	} 
	inline string msubtract(string sa, string sb) {
	    string ans = "";
	    int la = sa.size(), lb = sb.size(), lc = la;
	    int xa[maxlen], xb[maxlen], xc[maxlen];
	    bool isf = false;
	    memset(xa, 0, sizeof(xa));
	    memset(xb, 0, sizeof(xb));
	    memset(xc, 0, sizeof(xc));
	    for(int i = 0; i < la; i++)
	        xa[i] = sa[la - i - 1] - '0';
	    for(int i = 0; i < lb; i++)
	        xb[i] = sb[lb - i - 1] - '0';
	    for(int i = 0; i < lc; i++) {
	        if(xa[i] < xb[i]) {
	            xa[i+1]--;
	            xa[i] += 10;
	        }
	        xc[i] = xa[i] - xb[i];
	    }
	    while(xc[lc-1] == 0 && lc > 1)
	        lc--;
	    if(isf)
	        ans.push_back('-');
	    for(int i = lc-1; i >= 0; i--)
	        ans.push_back(xc[i] + '0');
	    return ans;
	}
	
	inline string mmultiplication_precise(string sa, string sb) {
	    string ans = "";
	    int la = sa.size(), lb = sb.size(), lc = la + lb;
	    int xa[maxlen], xb[maxlen], xc[maxlen * maxlen];
	    memset(xa, 0, sizeof(xa));
	    memset(xb, 0, sizeof(xb));
	    memset(xc, 0, sizeof(xc));
	    for(int i = 0; i < la; i++)
	        xa[i] = sa[la - i - 1] - '0';
	    for(int i = 0; i < lb; i++)
	        xb[i] = sb[lb - i - 1] - '0';
	    for(int i = 0; i < la; i++)
	        for(int j = 0; j < lb; j++) {
	            xc[i + j] += xa[i] * xb[j];
	            xc[i + j + 1] += xc[i + j] / 10;
	            xc[i + j] %= 10;
	        }
	    while(xc[lc - 1] == 0 && lc > 1)
	        lc--;
	    for(int i = lc - 1; i >= 0; i--)
	        ans.push_back(xc[i] + '0');
	    return ans;
	}
	inline string mmultiplication_lowprecise(string sa, ll ib) {
	    string ans = "";
	    int la = sa.size(), lc = la;
	    int xa[maxlen], xc[maxlen];
	    memset(xa, 0, sizeof(xa));
	    memset(xc, 0, sizeof(xc));
	    for(int i = 0 ; i < la; i++)
	        xa[i] = sa[la - i - 1] - '0';
	    for(int i = 0; i < lc; i++) {
	        xc[i] += xa[i] * ib;
	        xc[i + 1] += xc[i] / 10;
	        xc[i] %= 10;
	    }
	    int nx = xc[lc];
	    while(nx) {
	        xc[lc++] = nx % 10;
	        nx /= 10;
	    }
	    while(xc[lc - 1] == 0 && lc > 1) 
	        lc--;
	    for(int i = lc - 1; i >= 0; i--)
	        ans.push_back(xc[i] + '0');
	    return ans;
	}
	inline string mover(string sa, ll ib) {
	    string ans = "";
	    int la = sa.size(), lc = la;
	    int xa[maxlen], xc[maxlen];
	    memset(xa, 0, sizeof(xa));
	    memset(xc, 0, sizeof(xc));
	    for(int i = 0; i < la; i++)
	        xa[i] = sa[i] - '0';
	    int nr = 0;
	    for(int i = 0; i < lc; i++) {
	        nr = nr * 10 + xa[i];
	        xc[i] = nr / ib;
	        nr %= ib;
	    }
	    int i = 0;
	    while(xc[i] == 0 && i < la - 1)
	        i++;
	    for(string wls = "wdwfivez"; i < lc; i++)
	        ans.push_back(xc[i] + '0');
	    return ans;
	}
};

int main() {
    string a, b;
    long long int xb;
//  cin >> a >> b;
//  cin >> a >> xb;
//  cout << apb(a, b) << endl;
//  cout << mmultiplication_precise(a, b) << endl;
//  cout << mmultiplication_lowprecise(a, xb) << endl;
//  cout << mover(a, xb) << endl;
    return 0;
}
