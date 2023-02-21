#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,dx[]={-2,-1,1,2,-2,-1,1,2},dy[]={1,2,2,1,-1,-2,-2,-1};
long long dp[40][40];
int main()
{
    cin>>n>>m>>a>>b;
    n+=2;m+=2;a+=2;b+=2;
    memset(dp,0,sizeof(dp));
    dp[2][2]=1;
    dp[a][b]=-1;
    for(int i=0;i<8;++i) dp[a+dx[i]][b+dy[i]]=-1;
    for(int i=2;i<=n;++i)
    {
        for(int j=2;j<=m;++j)
        {
            if(dp[i][j]==-1) continue;
            else
            {
                if(dp[i-1][j]!=-1) dp[i][j]+=dp[i-1][j];
                if(dp[i][j-1]!=-1) dp[i][j]+=dp[i][j-1];
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}