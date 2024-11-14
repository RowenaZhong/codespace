#include<bits/stdc++.h>
using namespace std;
struct FastIO {
    static const int S = 1e7;
    int wpos;
    char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) exit(0);
        return buf[pos++];
    }
    inline int xint() {
        int s = 1, c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        if (c == '-') s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void wchar(int x) {
        if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos++] = x;
    }
    inline void wstring(const char *s) {
        while (*s) wchar(*s++);
    }
    ~FastIO() {
        if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;
int n,a[501][501],b[501][501],c[501][501];
int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int T;
    T=io.xint();
    while(T--){
        io.wstring("here!\n");
        n=io.xint();
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j) a[i][j]=io.xint();
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j) b[i][j]=io.xint();
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j) c[i][j]=io.xint();
        }
        bool flag=true;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                int ans=0;
                for(int k=1;k<=n;++k) ans+=a[i][k]*b[k][j];
                if(ans!=c[i][j]){
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
        }
        io.wstring(flag?"true\n":"false\n");
    }
    return 0;
}