#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010],len;
string ip1,ip2="";
void lcs(string s1,string s2)
{
    for(int i=1;i<=len;++i)
    {
        for(int j=1;j<=len;++j)
        {
            if(ip1[i-1]==ip2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
int main()
{
    cin>>ip1;
    len=ip1.length();
    for(int i=0;i<len;++i) ip2=ip1.substr(i,1)+ip2;
    memset(dp,0,sizeof(dp));
    lcs(ip1,ip2);
    int ans=len-dp[len][len];
    // for(int i=0;i<=len;++i)
    // {
    //     for(int j=0;j<=len;++j) printf("%d ",dp[i][j]);
    //     cout<<endl;
    // }
    cout<<ans;
    return 0;
}