#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int> White[100001]; 
bool vis[100001];
void dfs(int p,int edge,int color){
    if(edge>3||(edge<3&&vis[p])) return;
    if(edge==3&&vis[p]) ++ans;
    vis[p]=1;
    int k=0;
    for(int i=1;i<=n;++i){
        if(i==p) continue;
        if(i==White[p][k]){
            if(color==1){
                dfs(i,0,-1);
            }
            else{
                dfs(i,edge+1,0);
            }
            ++k;
        }
        else{
            if(color==0){
                dfs(i,0,-1);
            }
            else{
                dfs(i,edge+1,1);
            }
        }
    }
    vis[p]=0;
    return;
}
int main(){
    freopen("tri.in","r",stdin);
    freopen("tri.out","w",stdout);
//    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cerr<<"test1\n";
    for(int i=1;i<=m;++i){
        int u,v;
        cerr<<"here!\n";
        cin>>u>>v;//RE here
        cerr<<"here!\n";
        White[u].push_back(v);
        White[v].push_back(u);
    }
    cerr<<"test2\n";
    for(int i=1;i<=n;++i) sort(White[i].begin(),White[i].end());
    cerr<<"test3\n";
    dfs(1,0,-1);
    cerr<<"test4\n";
    cout<<ans;
    return 0;
}