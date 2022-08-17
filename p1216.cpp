#include<iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    int dp[2][n+10],ip[n+10];
    cin>>dp[1][1];
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=i;++j) cin>>ip[j];
        for(int j=1;j<=i;++j)
        {
            if(j==1) dp[i%2][j]=dp[(i-1)%2][j]+ip[j];
            else if(j==i) dp[i%2][j]=dp[(i-1)%2][j-1]+ip[j];
            else dp[i%2][j]=max(dp[(i-1)%2][j],dp[(i-1)%2][j-1])+ip[j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(ans<dp[n%2][i]) ans=dp[n%2][i];
    }
    cout<<ans;
    return 0;
}