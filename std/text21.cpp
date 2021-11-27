#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;

const int N = 1010;
const int M = 10010;
int d[N], getto[N], getoff[N], latest[N], f[N];
//d[i]：i - i+1这条边的长
//latest[i]：最晚到达i点的人的到达时间
//getto[i]：公交车到达i点的时间
//getoff[i]：在i点下车的人数
//f[i]：i - i+1这条边最多能减少多少时间

struct Passenger{
    int t, s, e;
}a[M];

inline int read()
{
    char ch = getchar(); int x = 0;
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)){
        x = x * 10 + ch - '0'; ch = getchar();
    }
    return x;
}

int main()
{
//	freopen("P1315_10.in", "r", stdin);
    int n, m, k;
    n = read(); m = read(); k = read();
    for (int i = 1; i < n; i ++) d[i] = read();
    for (int i = 1; i <= m; i ++){
        a[i].t = read(), a[i].s = read(), a[i].e = read();
        latest[a[i].s] = max(latest[a[i].s], a[i].t);
        getoff[a[i].e] ++;
    } 
    for (int i = 1; i <= n; i ++)
        getto[i] = max(getto[i - 1], latest[i - 1]) + d[i - 1];
    while (k --){
        for (int i = n - 1; i >= 1; i --)
            if (!d[i]) 
				f[i] = 0;
            else if (getto[i + 1] > latest[i + 1])
				f[i] = getoff[i + 1] + f[i + 1];
            else 
				f[i] = getoff[i + 1];
        int maxtime = 0, pos = 0; 
        for (int i = 1; i < n; i ++)
            if (f[i] > maxtime){
                maxtime = f[i]; pos = i;
            }
        if (pos == 0) break;
        d[pos] --;
        printf("%d  %d\n", pos, maxtime); 
        for (int i = pos + 1; i <= n; i ++) getto[i] = max(getto[i - 1], latest[i - 1]) + d[i - 1];
    }
    for (int i = 1; i <= n; i++)
    ;//	printf("%d\n", getoff[i]);
    int tot = 0;
    for (int i = 1; i <= m; i ++)
        tot += getto[a[i].e] - a[i].t;
    printf("%d\n", tot);
    return 0;
}
