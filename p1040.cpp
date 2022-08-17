#include<bits/stdc++.h>
using namespace std;
long long dp[40][40],n,ip[40],lst[40][40];
long long dfs(int a,int b)
{
    if(dp[a][b]) return dp[a][b];
    else
    {
        if(a>b) return dp[a][b]=1;
        else if(a==b)
        {
            lst[a][b]=a;
            return dp[a][b]=ip[a];
        }
        else
        {
            long long tmp=0;
            for(int i=a;i<=b;++i)
            {
                tmp=dfs(a,i-1)*dfs(i+1,b)+ip[i];
                if(tmp>dp[a][b])
                {
                    dp[a][b]=tmp;
                    lst[a][b]=i;
                }
            }
        }
    }
    return dp[a][b];
}
void prt(int l,int r)
{
    if(l>r) return;
    printf("%d ",lst[l][r]);
    prt(l,lst[l][r]-1);
    prt(lst[l][r]+1,r);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) scanf("%lld",&ip[i]);
    memset(dp,0,sizeof(dp));
    long long ans=dfs(1,n);
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=1;j<=n;++j) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<ans<<endl;
    prt(1,n);
    return 0;
}