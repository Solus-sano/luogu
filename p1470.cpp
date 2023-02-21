#include<bits/stdc++.h>
using namespace std;
string ip,str="";
int tmp;
vector<string> lst;
int main()
{
    while(1)
    {
        cin>>ip;
        if(ip==".") break;
        lst.push_back(ip);
    }
    while(cin>>ip) str+=ip;
    int len=str.length(),dp[len+10];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=len;++i)
    {
        for(int j=0;j<lst.size();++j)
        {
            tmp=lst[j].length();
            if((i-tmp)<0||lst[j]!=str.substr(i-tmp,tmp)) continue;
            dp[i]|=dp[i-tmp];
        }
    }
    for(int i=len;i>=0;--i)
    {
        if(dp[i])
        {
            printf("%d",i);
            return 0;
        }
    }
    // for(int i=1;i<=len;++i) printf("%d ",dp[i]);
}