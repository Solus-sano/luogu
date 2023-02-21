#include<bits/stdc++.h>
using namespace std;
int t0,m,t[200],prc[200];
int main()
{
    cin>>t0>>m;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&t[i],&prc[i]);
    }
    int dp[t0+10][m+10];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=t0;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(i>=t[j])
            {
                dp[i][j]=max(dp[i-t[j]][j-1]+prc[j],dp[i][j-1]);
            }
            else dp[i][j]=dp[i][j-1];
        }
    }
    cout<<dp[t0][m];
    return 0;
}