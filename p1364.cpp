#include<bits/stdc++.h>
using namespace std;
vector<int> g[110];
int n,w,u,v,ip[110];
int bfs(int a,int b,int flag)
{
    int tmp=ip[a]*flag;
    for(int i=0;i<g[a].size();++i)
    {
        if(g[a][i]!=b) tmp+=bfs(g[a][i],a,flag+1);
    }
    return tmp;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d",&w,&u,&v);
        ip[i]=w;
        if(u)
        {
            g[i].push_back(u);
            g[u].push_back(i);
        }
        if(v)
        {
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;++i) ans=min(ans,bfs(i,i,0));
    cout<<ans;
    return 0;
}