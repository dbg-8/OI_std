#include <bits/stdc++.h>
using namespace std;
int t,k,a,b;
int main(){
	
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    scanf("%d %d",&t, &k);//������������t
	while(t--){
		scanf("%d %d",&a,&b);//����k��m��n
		if(a>b) swap(a,b);
		if(!(a%(k+1))||(b-a+a/(k+1)*(k!=1))%2) cout<<"+";
		else cout<<"-"; 
		puts("");
	}
}
