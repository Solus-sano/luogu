#include<bits/stdc++.h>
using namespace std;
int n,ip[2010],dp[2010][2010];
int dfs(int a,int l,int r)
{
    if(dp[l][r]) return dp[l][r];
    if(l==r) return a*ip[l];
    return dp[l][r]=max(a*ip[l]+dfs(a+1,l+1,r),a*ip[r]+dfs(a+1,l,r-1));
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) scanf("%d",&ip[i]);
    memset(dp,0,sizeof(dp));
    int ans=dfs(1,1,n);
    cout<<ans;
    return 0;
}