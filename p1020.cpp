#include<bits/stdc++.h>
using namespace std;
vector<int> ip;
int x,dp[100010],len;
int opt1()
{
    fill(dp,dp+len,50000);
    dp[0]=ip[0];
    for(int i=1;i<len;++i)
    {
        *lower_bound(dp,dp+len,ip[i])=ip[i];
    }
    return (lower_bound(dp,dp+len,50000)-dp);
}
int opt2()
{
    memset(dp,0,sizeof(dp));
    dp[0]=ip[0];
    for(int i=1;i<len;++i)
    {
        *upper_bound(dp,dp+len,ip[i],greater<int>())=ip[i];
    }
    return (lower_bound(dp,dp+len,0,greater<int>())-dp);
}
int main()
{
    int k=0;
    while(cin>>x)
    {
        ip.push_back(x);
    }
    len=ip.size();
    int ans1=opt2(),ans2=opt1();
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    return 0;
}