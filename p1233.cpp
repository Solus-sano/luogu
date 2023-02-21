#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    int x;
    int y;
};
int dp[5010];
int cmp(node a,node b)
{
    if(a.x==b.x) return a.y>b.y;
    return a.x>b.x;
}
node ip[5010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) scanf("%d%d",&ip[i].x,&ip[i].y);
    sort(ip+1,ip+1+n,cmp);
    vector<int> lst;
    fill(dp,dp+n,10010);
    for(int i=1;i<=n;++i) lst.push_back(ip[i].y);
    for(int i=0;i<n;++i) *lower_bound(dp,dp+n,lst[i])=lst[i];
    cout<<lower_bound(dp,dp+n,10010)-dp;
    return 0;
}