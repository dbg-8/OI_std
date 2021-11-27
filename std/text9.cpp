#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=110;
const int M=1100;
int n,m,i,j,k;
struct bign
{
    int a[M],len;
} f[N],power[N];
inline bign operator / (const bign &x,const int y)
{
    bign now;
    memset(now.a,0,sizeof now.a);
    now.len=0;
    int ns=0;
    for(int i=x.len; i>=1; i--)
    {
        ns=ns*10+x.a[i];
        now.a[i]=ns/y;
        ns%=y;
        if(!now.len && now.a[i]) now.len=i;
    }
    return now;
}
inline bign operator + (const bign &x,const bign &y)
{
    bign now;
    memset(now.a,0,sizeof now.a);
    for(int i=1; i<=max(x.len,y.len); i++)
    {
        now.a[i]+=x.a[i]+y.a[i];
        now.a[i+1]=now.a[i]/10;
        now.a[i]%=10;
    }
    now.len=max(x.len,y.len);
    if(now.a[now.len+1]) 
        now.len++;
    return now;
}
inline bign operator * (const bign &x,const bign &y)
{
    bign now;
    memset(now.a,0,sizeof now.a);
    for(int i=1; i<=x.len; i++)
        for(int j=1; j<=y.len; j++)
        {
            now.a[i+j-1]+=x.a[i]*y.a[j];
            now.a[i+j]+=now.a[i+j-1]/10;
            now.a[i+j-1]%=10;
        }
    now.len=x.len+y.len-1;
    if(now.a[now.len+1]) 
        now.len++;
    return now;
}
inline bign C(int x,int y)
{
    bign tot,temp;
    tot.len=1;
    tot.a[1]=1;
    for(int i=y,j=1; j<=x; i--,j++)
    {
        int t=i;
        temp.len=0;
        while(t)
        {
            temp.a[++temp.len]=t%10;
            t/=10;
        }
        tot=tot*temp/j;
    }
    return tot;
}
inline void print(const bign &x)
{
    for(int i=x.len; i>=1; i--)
        printf("%d",x.a[i]);
    printf("\n");
}
inline void init()
{
    for(int i=1; i<=50; i++)
    {
        ll temp=((ll)(1)<<i)-1;
        while(temp)
        {
            power[i].a[++power[i].len]=temp%10;
            temp/=10;
        }
    }
    f[1].len=1;f[1].a[1]=1;f[2].len=1;f[2].a[1]=1;
    for(int i=3; i<=50; i++)
        for(int j=1; j<=i-1; j++)
            f[i]=f[i]+C(j-1,i-2)*f[j]*f[i-j]*power[j];//Ô¤´¦Àí
}
int main()
{
    init();
    n = 1;
    while(n <= 20) 
        print(f[n++]);
    return 0;
}
