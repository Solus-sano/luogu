#include<bits/stdc++.h>
using namespace std;
int t0,m,t[10010],prc[10010];
long long dp[10000010];
int main()
{
    cin>>t0>>m;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&t[i],&prc[i]);
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;++i)
    {
        for(int j=t[i];j<=t0;++j)
        {
            dp[j]=max(dp[j-t[i]]+prc[i],dp[j]);
        }
    }
    cout<<dp[t0];
    return 0;
}