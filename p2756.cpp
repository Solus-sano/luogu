#include<bits/stdc++.h>
using namespace std;
int m,n,flag[105];
struct edge{
    int u,v,cap;
    unsigned long long rev;
};
vector<edge> link_lst[105];

void add_edge(int u,int v,int cap)
{
    link_lst[u].push_back(edge{u,v,cap,link_lst[v].size()});
    link_lst[v].push_back(edge{v,u,0,link_lst[u].size()-1});
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
    cin>>m>>n;
    for(int i=1;i<=m;++i) add_edge(0,i,1);
    for(int i=m+1;i<=n;++i) add_edge(i,n+1,1);
    int ip_u=1,ip_v=1;
    while(1)
    {
        cin>>ip_u>>ip_v;
        if(ip_u==-1&&ip_v==-1) break;
        add_edge(ip_u,ip_v,1);
    }

    int ans=max_flow(0,n+1);
    cout<<ans<<endl;
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<link_lst[i].size();++j)
        {
            if(link_lst[i][j].cap==0&&link_lst[i][j].v!=0) printf("%d %d\n",i,link_lst[i][j].v);
        }
    }

    return 0;
}