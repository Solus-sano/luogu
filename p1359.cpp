#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;//first是最短距离，second是顶点编号
// int pre[205];

struct edge
{
    int to;
    int cost;
};
// vector<int> get_path(int t)
// {
//     vector<int> path;
//     while(t!=0)
//     {
//         path.push_back(t);
//         t=pre[t];
//     }
//     reverse(path.begin(),path.end());
//     return path;
// }

int n,ip,d[205];
vector<edge> link_lst[205];

int main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n-1;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            cin>>ip;
            link_lst[i].push_back(edge{j,ip});
            // link_lst[j].push_back(edge{i,ip});
        }
    }

    priority_queue<P,vector<P>,greater<P>> que;
    fill(d,d+205,INT_MAX);
    d[1]=0;
    que.push(P{0,1});
    while(!que.empty())
    {
        P tmp_p=que.top();que.pop();
        int v=tmp_p.second;
        if(d[v]<tmp_p.first) continue;

        for(int i=0;i<link_lst[v].size();++i)
        {
            if(d[link_lst[v][i].to]>d[v]+link_lst[v][i].cost)
            {
                d[link_lst[v][i].to]=d[v]+link_lst[v][i].cost;
                // pre[link_lst[v][i].to]=v;
                que.push(P{d[link_lst[v][i].to],link_lst[v][i].to});
            }
        }
    }
    // vector<int> path=get_path(n);
    // for(int i=0;i<path.size();++i) cout<<path[i]<<" ";
    // cout<<endl;
    cout<<d[n]<<endl;
    return 0;
}