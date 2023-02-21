#include<bits/stdc++.h>
using namespace std;
const int MAX_CNT=1005;
int n,m,d[2*MAX_CNT+10];
typedef pair<int,int> P;
struct edge
{
    int to;
    int cost;
};
vector<edge> link_lst[2*MAX_CNT+10];

void dij(int s)
{
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(P{0,s});
    d[s]=0;
    while(!que.empty())
    {
        P tmp_p=que.top();que.pop();
        int v=tmp_p.second;
        if(d[v]<tmp_p.first) continue;
        for(int i=0;i<link_lst[v].size();++i)
        {
            edge tmp_e=link_lst[v][i];
            if(d[tmp_e.to]>d[v]+tmp_e.cost)
            {
                d[tmp_e.to]=d[v]+tmp_e.cost;
                que.push(P{d[tmp_e.to],tmp_e.to});
            }
        }
    }
}

int main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;++i)
    {
        cin>>u>>v>>w;
        link_lst[u].push_back(edge{v,w});
        link_lst[v+MAX_CNT].push_back(edge{u+MAX_CNT,w});
    }

    fill(d,d+2*MAX_CNT+10,INT_MAX);
    
    dij(1);
    dij(1+MAX_CNT);
    int ans=0;
    for(int i=2;i<=n;++i)
    {
        ans+=d[i];
        ans+=d[i+MAX_CNT];
    }

    cout<<ans;
    return 0;
}
