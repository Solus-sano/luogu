#include<bits/stdc++.h>
using namespace std;
int n,ip[1010],dp[1010][40200],con=20100;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&ip[i]);
    }
    int ans=0,mod=998244353;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        ans++;
        ans%=mod;
        for(int j=i-1;j>=1;--j)
        {
            dp[i][ip[i]-ip[j]+con]+=(dp[j][ip[i]-ip[j]+con]+1);
            dp[i][ip[i]-ip[j]+con]%=mod;
            ans+=dp[j][ip[i]-ip[j]+con]+1;
            ans%=mod;
        }
    }
    cout<<ans;
    return 0;
}