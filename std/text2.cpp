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
    memset(dp,128,sizeof(dp));//�����и�����������Ϊ����� 
    ans = -1000000001;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            cin>>a[i][j];
    dp[0][0] = 0;//�߽� 
    for(int i = 1;i<=n;i++)
        for(int j = i;j<=m-(n-i);j++)//λ����j������j�ķ�ΧҪ���� 
            for(int k = i-1;k<=j-1;k++)//��һ�ֻ���λ��,����Ӧ�ô�С������ΪҪ�����ֵ��� 
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
