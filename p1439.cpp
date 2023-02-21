#include<bits/stdc++.h>
using namespace std;
int n,ip1[100010],ip2[100010],dp[100010],x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        ip1[x]=i;
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        ip2[i]=ip1[x];
    }
    fill(dp,dp+n,100010);
    for(int i=1;i<=n;++i)
    {
        *lower_bound(dp,dp+n,ip2[i])=ip2[i];
    }
    int ans=lower_bound(dp,dp+n,100010)-dp;
    cout<<ans<<endl;
    return 0;
}