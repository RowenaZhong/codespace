#include<bits/stdc++.h>
using namespace std;
int t;
vector<int> fr[100005];
int m,n,x;
int sz[100005],k[100005],tot[100005],ans[100005];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) fr[i].clear();
	memset(tot,0,sizeof(tot));
	for(int i=1;i<=m;i++){
		scanf("%d",&k[i]);
		fr[i].push_back(-1);
		for(int j=1;j<=k[i];j++){
			scanf("%d",&x);
			fr[i].push_back(x);
			if(k[i]==1) tot[x]++;
		}
		sort(fr[i].begin(),fr[i].end());
	}
	int maxn=0;
	for(int i=1;i<=n;i++) maxn=max(maxn,tot[i]);
	if(maxn>(m+1)/2){
		puts("SOMEONE WILL BE ANGRY!");
		return;
	}
	for(int i=1;i<=m;i++){
		if(k[i]==1){
			printf("%d ",fr[i][1]);
			continue;
		}
		for(int j=1;j<=k[i];j++){
			if(tot[fr[i][j]]<(m+1)/2){
				tot[fr[i][j]]++;
				printf("%d ",fr[i][j]);
				break;
			}
		}
	}
	puts("");
}
int main(){
	freopen("kagi.in","r",stdin);
	freopen("kagi.out","w",stdout);
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
