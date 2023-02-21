#include<bits/stdc++.h>
using namespace std;
long long n,w,s,dp[5010][2],ip[5010],inf=0x3f3f3f3f3f3f3f3f,tmp;
int main()
{
    cin>>n>>w>>s;
    for(int i=0;i<=w;++i)
    {
        dp[i][0]=-inf;
        dp[i][1]=dp[i][0];
    }
    for(int i=1;i<=n;++i) scanf("%lld",&ip[i]);
    dp[0][0]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<=w;++j)
        {
            tmp=-inf;
            for(int k=j-1;k<j+s&&k<=w;++k)
            {
                tmp=max(tmp,dp[k][i%2]+ip[i+1]*j);
            }
            // if(j!=1) tmp=max(tmp,dp[j-1][i%2]+ip[i+1]*(j));
            dp[j][(i+1)%2]=tmp;
        }
    }
    long long ans=-inf;
    for(int i=0;i<=w;++i) ans=max(ans,dp[i][n%2]);
    cout<<ans;
    return 0;
}