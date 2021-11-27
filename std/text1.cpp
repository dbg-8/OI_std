//from:Onion
//239 奇偶游戏 带权并查集
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

const int maxn=1e5+100;
int far[maxn];
int d[maxn];
int mp[maxn<<1];
int n,m;
struct node{
    int l,r,result;
}qs[maxn];

void init()
{
    for(int i=0;i<maxn;i++)
    {
        far[i]=i;
        d[i]=0;
    }
}

int find(int x)
{
    if(far[x]==x)
    {
        return far[x];
    }
    int root=find(far[x]);
    d[x]=d[x]^d[far[x]];
    return far[x]=root;
}


int main()
{
    int n,m;
    init();
    scanf("%d%d",&n,&m);
    char op[10];
    int x,y;
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%s",&x,&y,op);
        x--;
        if(op[0]=='e')
        {
            qs[i].l=x;
            qs[i].r=y;
            qs[i].result=0;
        }
        else
        {
            qs[i].l=x;
            qs[i].r=y;
            qs[i].result=1;
        }
        mp[cnt++]=x;
        mp[cnt++]=y;
    }
    int flag=0;
    sort(mp,mp+cnt);
    n=unique(mp,mp+cnt)-mp;
    for(int i=1;i<=m;i++)
    {
        x=lower_bound(mp,mp+n,qs[i].l)-mp;
        y=lower_bound(mp,mp+n,qs[i].r)-mp;
        int res=qs[i].result;
        int a=find(x);
        int b=find(y);
        if(a==b)
        {
            if(d[x]^d[y]==res)
                continue;
            else
            {
                printf("%d\n",i-1);
                flag=1;
                break;
            }
        }
        else
        {
            far[a]=b;
            d[a]=d[x]^d[y]^res;
        }
    }
    if(!flag)
        printf("%d\n",m);
}
