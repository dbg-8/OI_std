#include<bits/stdc++.h>
#define maxn 10010
#define inf 0x7ffffff
using namespace std;
int n,m,k,p,l,h,x[maxn],y[maxn],dow[maxn],up[maxn],f[maxn][1001];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;i++) dow[i]=0,up[i]=m+1;
	for(int i=1;i<=k;i++) scanf("%d%d%d",&p,&l,&h),dow[p]=l,up[p]=h;
	for(int i=1;i<=n;i++) for(int j=0;j<=m;j++) f[i][j]=inf;
	f[0][0]=inf;
	int arrive=k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j>=x[i-1]){
				f[i][j]=min(f[i][j],f[i-1][j-x[i-1]]+1);
				f[i][j]=min(f[i][j],f[i][j-x[i-1]]+1);
			}
			if(j==m)
				for(int k=j-x[i-1];k<=m;k++){
					f[i][j]=min(f[i][j],f[i-1][k]+1);
					f[i][j]=min(f[i][j],f[i][k]+1);
				}
		}
		for(int j=dow[i]+1;j<=up[i]-1;j++) if(j+y[i-1]<=m) f[i][j]=min(f[i][j],f[i-1][j+y[i-1]]);
		for(int j=1;j<=dow[i];j++) f[i][j]=inf;
		for(int j=up[i];j<=m;j++) f[i][j]=inf;
		for (int j=1;j<=n;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}
	int cnt=k,ans=inf;
	for(int i=n;i>=1;i--){
		for(int j=dow[i]+1;j<=up[i]-1;j++) if(f[i][j]<inf) ans=min(ans,f[i][j]);
		if(ans!=inf) break;
		if(up[i]<=m) cnt--;
	}
	if(cnt==k) printf("1\n%d\n",ans);
	else printf("0\n%d\n",cnt);
	return 0;
}

