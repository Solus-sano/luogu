#include<bits/stdc++.h>
using namespace std;
int ts1,ts2,te1,te2,t,n,dp[1005];
struct node
{
    int w;
    int v;
    int m;
};
node ip[10010];
vector<int> tmp;
int main()
{
    scanf("%d:%d",&ts1,&ts2);
    scanf("%d:%d",&te1,&te2);
    cin>>n;
    t=te2-ts2+(te1-ts1)*60;
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d",&ip[i].w,&ip[i].v,&ip[i].m);
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        if(ip[i].m==0)
        {
            for(int j=ip[i].w;j<=t;++j)
            {
                dp[j]=max(dp[j],dp[j-ip[i].w]+ip[i].v);
            }
        }
        else
        {
            for(int x=1;x<=ip[i].m;++x)
            {
                for(int j=t;j>=x*ip[i].w;--j)
                {
                    dp[j]=max(dp[j],dp[j-ip[i].w]+ip[i].v);
                }
            }
        }
    }
    cout<<dp[t];
    return 0;
}