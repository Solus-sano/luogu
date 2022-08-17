#include<bits/stdc++.h>
using namespace std;
vector<int> work[10010];
int n,k,p,t,dp[10010];
int main()
{
    // freopen("p1280_8.in","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=k;++i)
    {
        scanf("%d%d",&p,&t);
        work[p].push_back(t);
    }
    if(work[n].size()) dp[n]=0;
    else dp[n]=1;
    for(int i=n-1;i>=1;--i)
    {
        if(work[i].size()==0) dp[i]=dp[i+1]+1;
        else
        {
            for(int j=0;j<work[i].size();++j) dp[i]=max(dp[i],dp[i+work[i][j]]);
        }
    }
    cout<<dp[1];
    return 0;
}