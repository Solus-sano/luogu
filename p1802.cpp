#include<bits/stdc++.h>
using namespace std;
int n,w,lose[1010],win[1010],use[1010],dp[1010];
int main()
{
    cin>>n>>w;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i) scanf("%d%d%d",&lose[i],&win[i],&use[i]);
    for(int i=1;i<=n;++i)
    {
        for(int j=w;j>=0;--j)
        {
            if(j>=use[i]) dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
            else dp[j]=dp[j]+lose[i];
        }
    }
    long long ans=dp[w];
    cout<<ans*5<<endl;
    return 0;
}