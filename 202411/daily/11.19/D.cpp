#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,l,L,p;
int ans=0;
void dfs(int cnt,int x,int occ,int len){
	if(cnt>n) return;
	if(x>l) return;
	if(occ>(1ll<<40)) return;
	if(len==l&&cnt==n){
		(ans+=1)%=p;
		return;
	}
	for(int i=0;len+i*x<=l&&i*((1ll<<(40-x)))<=((1ll<<40)-occ);i++)
		dfs(cnt+i,x+1,occ+i*((1ll<<(40-x))),len+i*x);
}
signed main(){
	freopen("ducky.in","r",stdin);
	freopen("ducky.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&d,&L,&p);
	if(d==2){
		for(l=1;l<=L;l++){
			ans=0;
			dfs(0,1,0,0);
			printf("%lld\n",ans);
		}
		return 0;
	}
	return 0;
}
