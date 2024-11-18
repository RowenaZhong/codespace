#include <bits/stdc++.h>
using namespace std;
int T,n,m,a[25],sg;
bool selected[21];
// int cnt[21];

int main() {
    cin>>T;
    while(T--)
    {
        cin>>n;
        sg=0;
        while(n--)
        {
            cin>>m;
            for(int i=0;i<=20;i++)selected[i]=0;
            int idx=21-m;
            while(m--)
            {
                int x;
                cin>>x;
                selected[x]=true;
            }
            int cont=0;
            for(int i=1;i<=20;i++)
            {
                if(selected[i])cont++;
                else
                {
                    if((--idx)&1)sg^=cont;
                    // cnt[++idx]=cont;
                    cont=0;
                }
            }
        }
        puts(sg?"YES":"NO");
    }
    return 0;
}