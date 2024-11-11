#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],vis[1005][1005],tot,n,m;
vector<pair<int,int> > p;
char c;
void dfs(int x,int y){
	if(x<0||x>n||y<0||y>m||vis[x][y]||!a[x][y]) return;
	vis[x][y]=tot;
	dfs(x+1,y);dfs(x,y+1);dfs(x-1,y);dfs(x,y-1);
}
int fa[1000005];
int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
int main(){
	freopen("room.in","r",stdin);
	freopen("room.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			if(c=='.') a[i][j]=1;
			else p.push_back(make_pair(i,j));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!vis[i][j]&&a[i][j]){
				tot++;
				dfs(i,j);
			}
		}
	}
	vector<int> s;
	int x,y,z,w;
	int st=vis[1][1],ed=vis[n][m];
	int ans=0;
	for(int i=0;i<p.size();i++){
		for(int j=i+1;j<p.size();j++){
			for(int k=1;k<=tot;k++) fa[k]=k;
			s.clear();
			x=p[i].first,y=p[i].second;
			if(vis[x+1][y]) s.push_back(vis[x+1][y]);
			if(vis[x][y+1]) s.push_back(vis[x][y+1]);
			if(vis[x][y-1]) s.push_back(vis[x][y-1]);
			if(vis[x-1][y]) s.push_back(vis[x-1][y]);
			if(s.size()) vis[x][y]=s[0];
			z=x,w=y;
			for(int i=1;i<s.size();i++){
				if(get(s[i])!=get(s[0]))
					fa[get(s[i])]=get(s[0]);
			}
			x=p[j].first,y=p[j].second;
			s.clear();
			if(vis[x+1][y]) s.push_back(vis[x+1][y]);
			if(vis[x][y+1]) s.push_back(vis[x][y+1]);
			if(vis[x][y-1]) s.push_back(vis[x][y-1]);
			if(vis[x-1][y]) s.push_back(vis[x-1][y]);
			for(int i=1;i<s.size();i++){
				if(get(s[i])!=get(s[0]))
					fa[get(s[i])]=get(s[0]);
			}
			if(get(st)==get(ed)){
				ans++;
			}
			vis[z][w]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
