#include<bits/stdc++.h>
using namespace std;
int t,n,m,prc[105][105],dp[100010];
int solve(int mx,int day)
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        for(int j=prc[day][i];j<=mx;++j)
        {
            dp[j]=max(dp[j],dp[j-prc[day][i]]+prc[day+1][i]-prc[day][i]);
        }
    }
    int tmp=dp[mx]+mx;
    if(day>=t-1) return tmp;
    else
    {
        // cout<<tmp<<endl;
        tmp=solve(tmp,day+1);
    }
}
int main()
{
    cin>>t>>n>>m;
    for(int i=1;i<=t;++i)
    {
        for(int j=1;j<=n;++j) scanf("%d",&prc[i][j]);
    }
    int ans=solve(m,1);
    cout<<ans;
    return 0;
}