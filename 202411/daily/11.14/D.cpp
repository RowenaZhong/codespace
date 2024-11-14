#include<bits/stdc++.h>
using namespace std;
int n;
int f[305][305];
bool hw[305][305];
string s;
int main(){
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	cin>>n>>s;
	s=" "+s;
	int j;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			hw[i][j]=true;
			for(int k=0;k<=(j-i)/2;k++){
				if(s[i+k]!=s[j-k]){hw[i][j]=false;break;}
			}
		}
	}
	for(int i=1;i<=n;i++) f[i][i]=1;
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			j=i+len-1;
			if(hw[i][j]){f[i][j]=1;continue;}
			f[i][j]=len;
			for(int k=i;k<j;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
			for(int k=0;k<=(j-i)/2;k++){
				if(s[i+k]!=s[j-k]) break;
				for(int l=j-k-1;l>=i+k+1;l--){
					if(hw[l][j-k-1]) f[i][j]=min(f[i][j],f[i+k+1][l-1]+1);
				}
			}
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}
