#include<bits/stdc++.h>
using namespace std;
int n,k,h,dp[110][110];
struct node{
    int h;
    int l;
};
node ip[110];
int cmp(node a,node b){return a.h<b.h;}
int main()
{
    cin>>n>>k;
    k=n-k;
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&ip[i].h,&ip[i].l);
    }
    sort(ip+1,ip+1+n,cmp);
    memset(dp,0,sizeof(dp));
    for(int j=2;j<=k;++j)
    {
        for(int i=j;i<=n;++i)
        {
            dp[i][j]=0x3f3f3f3f;
            for(int x=j-1;x<i;++x)
            {
                dp[i][j]=min(dp[i][j],dp[x][j-1]+abs(ip[i].l-ip[x].l));
            }
        }
    }
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=1;j<=k;++j) printf("%d ",dp[i][j]);
    //     cout<<endl;
    // }
    int ans=0x3f3f3f3f;
    for(int i=k;i<=n;++i) ans=min(ans,dp[i][k]);
    cout<<ans;
    return 0;
}