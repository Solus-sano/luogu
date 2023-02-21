#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
struct edge
{
    int to;
    double cost;
};


int n,m,pre[205];
double d[205];
P location_lst[205];
vector<edge> link_lst[205];

void dij(int s,int u0,int v0)
{
    priority_queue<P,vector<P>,greater<P>> que;
    fill(d,d+205,INT_MAX);
    d[s]=0; pre[s]=0;
    que.push(P{0,s});
    while(!que.empty())
    {
        P tmp_p=que.top();que.pop();
        if(tmp_p.first>d[tmp_p.second]) continue;
        for(int i=0;i<link_lst[tmp_p.second].size();++i)
        {
            edge e=link_lst[tmp_p.second][i];
            if((tmp_p.second==u0&&e.to==v0)||(tmp_p.second==v0&&e.to==u0)) continue;
            if(d[e.to]>d[tmp_p.second]+e.cost)
            {
                d[e.to]=d[tmp_p.second]+e.cost;
                que.push(P{d[e.to],e.to});
                pre[e.to]=tmp_p.second;
            }
        }
    }
}
vector<P> remove_edge_lst()
{
    vector<P> lst;
    int t=n;
    while(pre[t]!=0)
    {
        lst.push_back(P{t,pre[t]});
        t=pre[t];
    }
    return lst;
}


int main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>location_lst[i].first>>location_lst[i].second;
    int ip_u,ip_v;
    for(int i=1;i<=m;++i)
    {
        cin>>ip_u>>ip_v;
        double dis=sqrt(pow(location_lst[ip_u].first-location_lst[ip_v].first,2)+pow(location_lst[ip_u].second-location_lst[ip_v].second,2));
        link_lst[ip_u].push_back(edge{ip_v,dis});
        link_lst[ip_v].push_back(edge{ip_u,dis});
    }
    vector<P> rem_lst;
    dij(1,0,0);
    double ans=INT_MAX;
    rem_lst=remove_edge_lst();
    for(auto it:rem_lst)
    {
        dij(1,it.first,it.second);
        ans=min(ans,d[n]);
    }
    if(ans==INT_MAX) cout<<-1<<endl;
    printf("%.2lf\n",ans);
    return 0;
}