#include<iostream>
#include<cstdio>
#define LL long long
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r
#define ls k<<1
#define rs k<<1|1
#define mid ((l+r)>>1)
using namespace std;
const int maxn=100005;
LL tr[maxn<<2];
int mod,t,q;
inline void update(int k){
	tr[k]=(tr[ls]*tr[rs])%mod;
}
void build(int k,int l,int r){
	tr[k]=1;
	if(l==r)
		return ;
	build(lson);build(rson);
}
void change(int k,int l,int r,int x,int val){
	if(l==r){
		tr[k]=(val==0)?1:val;
		return ;
	}
	if(x<=mid)change(lson,x,val);
	else change(rson,x,val);
	update(k);
	printf("~~%d %lld\n", k, tr[k]);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&q,&mod);
		build(1,1,q);
		int opt,x;
		for(int i=1;i<=q;++i){
			scanf("%d%d",&opt,&x);
			if(opt==1)change(1,1,q,i,x),printf("%lld\n",tr[1]%mod);
			else change(1,1,q,x,0),printf("%lld\n",tr[1]%mod);
		}
	}
	return 0;
}
