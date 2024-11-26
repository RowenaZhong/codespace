#include<bits/stdc++.h>
using namespace std;
int n,a[200005],nxt[200005];
int st[200005][22],lg2[200005];
void init(){
	for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++) st[i][0]=nxt[i];
	for(int i=1;i<=lg2[n];i++)
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
			cout<<i<<' '<<j<<endl;
		}
			
}
int query(int l,int r){
	int k=lg2[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int r;
	int ans=0;
	for(int i=1;i<=n;i++){
		nxt[i]=n;
		for(int j=i+1;j<=n;j++)
			if(__gcd(a[i],a[j])!=1){
				nxt[i]=j-1;
				break;
			}
	}
	init();
	for(int i=1;i<=n;i++){
		r=n;
		while(query(i,r)<r) r=query(i,r);
		ans+=(r-i+1);
	}
	cout<<ans<<endl;
	return 0;
}
