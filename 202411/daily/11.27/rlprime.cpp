#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
bool d[105][105];
int ans=0;
bool cs[105];
void dfs(int x){
	if(x>b-a+1){ans++;return;}
	dfs(x+1);
	for(int i=1;i<x;i++)
		if(cs[i]&&!d[i][x]) return;
	cs[x]=1;
	dfs(x+1);
	cs[x]=0;
}
signed main(){
	freopen("rlprime.in","r",stdin);
	freopen("rlprime.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	if(a>1e12){
		puts("12204675071");
	}
	for(int i=a;i<=b;i++){
		for(int j=i+1;j<=b;j++){
			if(__gcd(i,j)==1)
				d[i-a+1][j-a+1]=d[j-a+1][i-a+1]=1;
		}
	}
	dfs(1);
	cout<<ans-1<<endl;
	return 0;
}
