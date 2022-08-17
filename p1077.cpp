#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],mod=1e+6+7,dp[110];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    dp[0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=m;j>=0;--j)
        {
            for(int k=1;k<=a[i]&&k<=j;++k)
                dp[j]=(dp[j]+dp[j-k])%mod;
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}