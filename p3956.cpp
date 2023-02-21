#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
struct node{
    int x,y,col;
};
vector<node> node_lst;
struct edge
{
    int u,v,cost;
};
vector<edge> edge_lst[10005];


int n,m,box[105][105],d[5005];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int chk_next(node a,node b)
{
    for(int i=0;i<4;++i)
    {
        if(a.x+dx[i]==b.x&&a.y+dy[i]==b.y) return 1;
    }
    return 0;
}

void dij(int s)
{
    fill(d,d+node_lst.size()+5,INT_MAX);
    d[s]=0;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(P{0,s});
    while(!que.empty())
    {
        P tmp_p=que.top(); que.pop();
        int u=tmp_p.second;
        if(d[u]<tmp_p.first) continue;
        for(int i=0;i<edge_lst[u].size();++i)
        {
            edge e=edge_lst[u][i];
            if(d[e.v]>d[u]+e.cost)
            {
                d[e.v]=d[u]+e.cost;
                que.push(P{d[e.v],e.v});
            }
        }
        // for(int i=0;i<node_lst.size();++i) printf("%d ",d[i]);
        // cout<<endl;
    }
}

int main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>m>>n;
    int x_ip,y_ip,col;
    for(int i=1;i<=n;++i)
    {
        cin>>x_ip>>y_ip>>col;
        if(col==0) col=2;
        box[x_ip][y_ip]=col;
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(box[i][j]!=1&&box[i][j]!=2) continue;
            for(int k=0;k<=3;++k)
            {
                int nx=i+dx[k],ny=j+dy[k];
                if(1<=nx&&nx<=m&&1<=ny&&ny<=m&&box[nx][ny]==0) box[nx][ny]=3;
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(box[i][j])
            {
                if(box[i][j]==3)
                {
                    node_lst.push_back(node{i,j,1});
                    node_lst.push_back(node{i,j,2});
                }
                else
                {
                    node_lst.push_back(node{i,j,box[i][j]});
                }
            }
        }
    }
    for(int i=0;i<node_lst.size()-1;++i)
    {
        for(int j=i+1;j<node_lst.size();++j)
        {
            node n1=node_lst[i],n2=node_lst[j];
            if(chk_next(n1,n2)==0||(box[n1.x][n1.y]==3&&box[n2.x][n2.y]==3)) continue;
            int cost = (box[n1.x][n1.y]==3||box[n2.x][n2.y]==3) ? 1:0;
            if(n1.col==n2.col)
            {
                edge_lst[i].push_back(edge{i,j,cost});
                edge_lst[j].push_back(edge{j,i,cost});
            }
            else
            {
                edge_lst[i].push_back(edge{i,j,cost+1});
                edge_lst[j].push_back(edge{j,i,cost+1});
            }
        }
    }
    // for(int i=0;i<node_lst.size();++i)
    // {
    //     node tmp_n=node_lst[i];
    //     printf("%d %d %d\n",tmp_n.x,tmp_n.y,tmp_n.col);
    // }
    dij(0);
    // for(int i=0;i<node_lst.size();++i)
    // {
    //     for(int j=0;j<edge_lst[i].size();++j) printf("%d ",edge_lst[i][j].v);
    //     cout<<endl;
    // }
    if(d[node_lst.size()-1]==INT_MAX) cout<<-1<<endl;
    else if(box[m][m]==3)
    {
        cout<<min(d[node_lst.size()-1],d[node_lst.size()-2])+1<<endl;
    }
    else
    {
        cout<<d[node_lst.size()-1]<<endl;
    }
    return 0;
}