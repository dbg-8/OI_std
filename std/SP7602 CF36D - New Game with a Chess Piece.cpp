#include <bits/stdc++.h>
using namespace std;
int t,k,a,b;
int main(){
    scanf("%d",&t);//读入数据组数t
	while(t--){
		scanf("%d %d %d",&k,&a,&b);//读入k、m、n
		if(a>b) swap(a,b);
		if(!(a%(k+1))||(b-a+a/(k+1)*(k!=1))%2) cout<<"+";
		else cout<<"-"; 
		puts("");
	}
}
