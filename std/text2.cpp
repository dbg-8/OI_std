#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[101][101],dp[101][101],ans,location[101][101],x;
void locat(ll n,ll x)
{
    if(n==1)
        cout<<x<<" ";
    else
    {
        locat(n-1,location[n][x]);
        cout<<x<<" ";
    }
}
int main()
{
    memset(dp,128,sizeof(dp));//可能有负数，所以设为无穷大 
    ans = -1000000001;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            cin>>a[i][j];
    dp[0][0] = 0;//边界 
    for(int i = 1;i<=n;i++)
        for(int j = i;j<=m-(n-i);j++)//位置在j，这里j的范围要搞清 
            for(int k = i-1;k<=j-1;k++)//上一种花的位置,这里应该从小到大，因为要按照字典序 
                if(dp[i-1][k]+a[i][j]>dp[i][j])
                {
                    dp[i][j] = dp[i-1][k]+a[i][j];
                    location[i][j] = k;
                    printf("%d\n", k);
                }             
    for(int i = n;i<=m;i++)
    {
        if(dp[n][i]>ans)
        {
            ans = dp[n][i];
            x = i;
        }
    }    
    cout<<ans<<endl;
    locat(n,x);
    return 0;
} 
