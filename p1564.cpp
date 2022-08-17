#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int abel[3][2510],n,m,a,dp[2510];
int chk(int x,int y)
{
    int tmp=0,s1=abel[1][y]-abel[1][x-1],s2=abel[2][y]-abel[2][x-1];
    return (s1==0)||(s2==0)||(abs(s1-s2)<=m);
}
int main()
{
    cin>>n>>m;
    abel[1][0]=0;
    abel[2][0]=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a);
        if(a==1)
        {
            abel[1][i]=abel[1][i-1]+1;
            abel[2][i]=abel[2][i-1];
        }
        else
        {
            abel[2][i]=abel[2][i-1]+1;
            abel[1][i]=abel[1][i-1];
        }
    }
    fill(dp,dp+2510,inf);
    dp[0]=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            if(chk(j,i)) dp[i]=min(dp[i],dp[j-1]+1);
        }
    }
    // for(int i=1;i<=n;++i) printf("%d ",dp[i]);
    cout<<dp[n];
    return 0;
}