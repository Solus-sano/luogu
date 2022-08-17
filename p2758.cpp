#include<bits/stdc++.h>
using namespace std;
string ip1,ip2;
int dp[2][2010];
int main()
{
    cin>>ip1>>ip2;
    int len1=ip1.length(),len2=ip2.length();
    for(int i=0;i<=len2;++i) dp[0][i]=i;
    for(int i=1;i<=len1;++i)
    {
        dp[i%2][0]=i;
        for(int j=1;j<=len2;++j)
        {
            if(ip1[i-1]==ip2[j-1]) dp[i%2][j]=dp[(i-1)%2][j-1];
            else dp[i%2][j]=min(dp[(i-1)%2][j]+1,min(dp[i%2][j-1]+1,dp[(i-1)%2][j-1]+1));
        }
    }
    int ans=dp[len1%2][len2];
    cout<<ans;
    return 0;
}