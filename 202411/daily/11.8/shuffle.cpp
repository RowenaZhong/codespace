#include <stdio.h>
#include <ctype.h>
inline void readi(int& x){
	static int ch; x = 0,ch = getchar();
	while (!feof(stdin)&&!isdigit(ch)) ch = getchar();
	while (!feof(stdin)&&isdigit(ch)) x = x * 10 + ch - '0',ch = getchar();
}
int main()
{
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    int n,x=0,s;
    readi(n);
    n=n*2+1;
    while(n--)
    {
        readi(s);
        x^=s;
    }
    printf("%d\n",x);
    fclose(stdin);
    fclose(stdout);
    return 0;
}