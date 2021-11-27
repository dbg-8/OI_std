#include<bits/stdc++.h>
#include <string>
using namespace std;
int f[105][105], p[105][105], n;
char a[105];

int qqq(int x){
	if (x < 10)
	return 1;
	if (x < 100)
	return 2;
	if (x <  1000)
	return 3;
}

bool equals(int r, int ed, int len) { // r,ed往前len个字符是否相同
    for (int i = 0; i < len; i++)
        if (a[r - i] != a[ed - i]) return false;
    return true;
}

void print(int l, int r) {
    if (!p[l][r]) {
        for (int i = l; i <= r; i++) putchar(a[i]);
        return;
    }
    if (p[l][r] > 0) {
        print(l, p[l][r]);
        print(p[l][r] + 1, r);
    } else {
        int len = -p[l][r];
        printf("%d(", (r - l + 1) / len);
        print(l, l + len - 1);
        putchar(')');
    }
}

int main() {
    scanf("%s", a + 1);
    n = strlen(a + 1);
    memset(f, 0x3f, sizeof(f));
    for (int len = 1; len <= n; len++)
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            // [l,r]拆分成两段
            if (len == 1) f[l][r] = 1;
            else for (int k = l; k < r; k++)
                if (f[l][k] + f[k + 1][r] < f[l][r]) {
                    f[l][r] = f[l][k] + f[k + 1][r];
                    p[l][r] = k;
                    printf("$$$\n");
                }
            // [l,r]]重复cnt次生成更长的字符串[l,ed]
            for (int ed = r + len, cnt = 2; ed <= n && equals(r, ed, len); ed += len, cnt++)
                if (f[l][r] + 2 + qqq(cnt) < f[l][ed]) {
                    f[l][ed] = f[l][r] + 2 + qqq(cnt);
                    p[l][ed] = -len; // 负数表示由若干个长度为len的子串循环构成
                	printf("###\n");
				}
        }
    print(1, n);
}
