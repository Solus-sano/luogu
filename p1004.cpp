#include<bits/stdc++.h>
using namespace std;


int main()
{
    int dp[15][15][15][15],value[15][15],N,a,b,c;
    cin>>N;
    while(1)
    {
        cin>>a>>b>>c;
        if(a==0 || b==0 || c==0) break;
        else
        {
            value[a][b]=c;
        }

    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=N;k++)
            {
                for(int l=1;l<=N;l++)
                {
                    if(i==k && j==l)
                    {
                        dp[i][j][k][l] = max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1])) + value[i][j];
                    }
                    else
                    {
                        dp[i][j][k][l] = max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1])) + value[i][j] + value[k][l];
                    }
                }
            }
        }
    }
    cout<<dp[N][N][N][N]<<endl;
    return 0;
}
