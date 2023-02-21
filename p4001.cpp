#include<bits/stdc++.h>
using namespace std;
const int MAX_CNT=1000005;
int n,m,flag[MAX_CNT];
struct edge{int u,v,cap;unsigned long long rev;};
vector<edge> link_lst[MAX_CNT];

void add_edge(int u,int v,int cap)
{
    link_lst[u].push_back(edge{u,v,cap,link_lst[v].size()});
    link_lst[v].push_back(edge{v,u,cap,link_lst[u].size()});
}

int dfs(int u,int t,int f)
{
    if(u==t) return f;
    flag[u]=1;
    for(int i=0;i<link_lst[u].size();++i)
    {
        edge e=link_lst[u][i];
        if(!flag[e.v]&&e.cap>0)
        {
            int d=dfs(e.v,t,min(e.cap,f));
            if(d>0)
            {
                link_lst[u][i].cap-=d;
                link_lst[e.v][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        memset(flag,0,sizeof(flag));
        int f=dfs(s,t,INT_MAX);
        if(f==0) return flow;
        flow+=f;
    }
}


int main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    // freopen("P4001_3.in","r",stdin);
    cin>>n>>m;
    int ip_cap;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<m;++j)
        {
            cin>>ip_cap;
            add_edge(m*(i-1)+j,m*(i-1)+j+1,ip_cap);
        }
    }
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>ip_cap;
            add_edge(m*(i-1)+j,m*i+j,ip_cap);
        }
    }
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<m;++j)
        {
            cin>>ip_cap;
            add_edge(m*(i-1)+j,m*i+j+1,ip_cap);
        }
    }
    int ans=max_flow(1,m*n);
    cout<<ans<<endl;
    return 0;
}