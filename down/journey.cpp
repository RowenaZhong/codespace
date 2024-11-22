#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
int a,b,n;
ull ans1,ans2;
const int p=1e9+7;
int power(int a,int b,int p){
	int ans=1;
	for(;b;b>>=1){
		if(b&1) ans=ans*a%p;
		a=a*a%p;
	}
	return ans;
}
void solve(){
	scanf("%lld%lld%lld",&a,&b,&n);
	int cnt=0;
	while(a%2==0&&b%2==0) cnt++,a/=2,b/=2;
	if((a%2)+(b%2)==1){
		printf("%lld\n",power(2,cnt*n,p));
		return;
	}
	int ans=cnt*n;
	ans1=ans2=1;
	int d=n;
	for(;d;d>>=1){
		if(d&1) ans1*=a;
		a*=a;
	}
	d=n;
	for(;d;d>>=1){
		if(d&1) ans2*=b;
		b*=b;
	}
	for(int i=0;i<=63;i++){
		if((ans1>>i&1)^(ans2>>i&1)){ans+=i;break;}
	}
	printf("%lld\n",power(2,ans,p));
}
signed main(){
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--) solve();
	return 0;
}
