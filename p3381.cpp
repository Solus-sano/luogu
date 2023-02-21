#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> P;
int n,m;
long long dis[5005],pre_v[5005],pre_e[5005];
struct edge{
    long long u,v,cap,cost;
    unsigned long long rev;
};

vector<edge> link_lst[5003];

void add_edge(int u,int v,int cap,int cost)
{
    link_lst[u].push_back(edge{u,v,cap,cost,link_lst[v].size()});
    link_lst[v].push_back(edge{v,u,0,-1*cost,link_lst[u].size()-1});
}

P min_cost_f(int s,int t)
{
    int cost_sum=0,f_sum=0;
    while(1)
    {
        //求s到t最短路
        fill(dis,dis+5002,INT_MAX);
        dis[s]=0;
        int update=1;
        
        while(update)
        {
            update=0;
            
            for(int i=1;i<=n;++i)
            {
                if(dis[i]==INT_MAX) continue;
                for(int j=0;j<link_lst[i].size();++j)
                {
                    edge &e=link_lst[i][j];
                    if(dis[e.v]>dis[e.u]+e.cost && e.cap>0)
                    {
                        dis[e.v]=dis[e.u]+e.cost;
                        pre_v[e.v]=e.u; pre_e[e.v]=j;
                        update=1; 
                    }
                }
            }
        }
        
        if(dis[t]==INT_MAX) return P{f_sum,cost_sum};

        long long d=INT_MAX;
        for(int v=t;v!=s;v=pre_v[v]) d=min(d,link_lst[pre_v[v]][pre_e[v]].cap);
        f_sum+=d;
        cost_sum+=d*dis[t];
        // printf("%d %d\n",f_sum,cost_sum);
        for(int v=t;v!=s;v=pre_v[v])
        {
            edge &e=link_lst[pre_v[v]][pre_e[v]];
            e.cap-=d;
            link_lst[v][e.rev].cap+=d;
        }
    }
    // return cost_sum;
}

int main()
{
    long long s,t,u,v,w,c;
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;++i)
    {
        scanf("%lld%lld%lld%lld",&u,&v,&w,&c);
        add_edge(u,v,w,c);
    }
    P ans=min_cost_f(s,t);
    printf("%lld %lld",ans.first,ans.second);
    return 0;
}