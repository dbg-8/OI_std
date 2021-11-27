// Problem: P3719 [AHOI2017³õÖÐ×é]rexp
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3719
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*houpingze \CCF/ \CCF/ \CCF/ \CCF/ \CCF/ */
/*
Note:

*/
#include<bits/stdc++.h>
#define reg register int
#define INF (1<<30)
#define pb push_back
#define vc vector
#define fst first
#define scd second
//#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int read(){
	int res=0,fs=1; char c=getchar();
	while(!(c>='0' && c<='9')){ if(c=='-')fs=-1; c=getchar(); }
	while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();
	return res*fs;
}
void print(int x){
    if(x<0) { putchar('-'); x=-x;}
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,cnt,m,a[500010],tmp,k;
typedef pair<int,int> P;
//struct PROBLEM_SOLVER{
//	   int n,m;
//}solver;

//signed main(){
struct khc{
	int opt;
	//opt=0 char(  + (  )  )
	//opt=1 num
	int num;
	char c;
	
};
	khc f[300005];
	khc ans[1000005];
int main() {
	// ios::sync_with_stdio(false);
	string s;
	cin>>s;
	// for(int )
	int idx=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('||s[i]==')') {
			f[idx].opt=0,f[idx].c=s[i],idx++;
			if(s[i]==')'&&i!=s.size()-1&&s[i+1]=='a') {
				f[idx].opt=0,f[idx].c='+',idx++;
			}
		
		}else if(s[i]=='a'){
			f[idx].opt=1;
			while(i<(int)s.size()&&s[i]=='a'){
				i++;
				f[idx].num++;
				// cout<<i<<' ';
			}
			idx++;
			i--;
		}else if(s[i]=='|'){
			f[idx].opt=0;
			f[idx].c='|';
			idx++;
		}
	}
	// stack<khc>ans;
	int anscnt=0;
	stack<khc>sta;//sta! sta! sta!!!!!!!!!111111
	for(int i=0;i<idx;i++){
		if(f[i].c=='('){
			anscnt++;
			ans[anscnt]=f[i];
			// sta.push(f[i])
		}else if(f[i].c==')'){
			while(!sta.empty()&&sta.top().c!='(') {
				// ans.push(f[i])
				anscnt++;
				ans[anscnt]=sta.top();
				sta.pop();
			}
			cout<<ans[1].num<<endl;
			return 0;
			sta.pop();
		}else if(f[i].opt==0){
			sta.push(f[i]);
		}else {
			
			sta.push(f[i]);
		}
	}
	while(!sta.empty()) {
		
				anscnt++;
				ans[anscnt]=sta.top();
				sta.pop();
	}
	for(int i=1;i<=anscnt;i++){
		if(ans[i].opt==0) cout<<ans[i].c<<' ';
		else cout<<ans[i].num<<' ';
	}
	// for(int i=0;i<idx;i++){
		// if(f[i].opt==0) cout<<f[i].c<<' ';
		// else cout<<f[i].num<<' ';
	// }
    return 0;
}

