#include<bits/stdc++.h>
using namespace std;
int n,m,par[1005],rnk[1005],x,y;
int get(int a)
{
    if(par[a]==a) return a;
    else return get(par[a]);
}
int chk(int a,int b){return get(a)==get(b);}
void merge(int a,int b)
{
    a=get(a);
    b=get(b);
    if(a==b) return;
    if(rnk[a]<rnk[b]) par[a]=b;
    else
    {
        par[b]=a;
        if(rnk[a]==rnk[b]) rnk[a]++;
    }
}
int main()
{
    while(cin>>n>>m)
    {
        memset(rnk,0,sizeof(rnk));
        for(int i=1;i<=n;++i) par[i]=i;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            merge(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            if(get(i)==i) ans++;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}