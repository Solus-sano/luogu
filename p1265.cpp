#include<bits/stdc++.h>
using namespace std;
int n,x,y,par[5005],rnk[5005];
struct edge
{
    int u,v;
    double cost;
};
struct node{
    double x,y;
};
vector<edge> edge_lst;
int cmp(edge a,edge b){return a.cost<b.cost;}
node node_lst[5005];

void init_union(int n)
{
    for(int i=1;i<=n;++i)
    {
        par[i]=i; rnk[i]=1;
    }
}
int find(int s){return par[s]==s ? s:find(par[s]);}
void unite(int x,int y)
{
    x=find(x); y=find(y);
    if(x==y) return;
    
    if(rnk[x]<rnk[y]) par[x]=y;
    else
    {
        par[y]=x;
        if(rnk[x]==rnk[y]) rnk[x]++;
    }
}

double kruskal()
{
    init_union(n);
    sort(edge_lst.begin(),edge_lst.end(),cmp);
    double res=0;
    for(int i=0;i<edge_lst.size();++i)
    {
        edge e=edge_lst[i];
        if(find(e.u)==find(e.v)) continue;
        res+=e.cost;
        unite(e.u,e.v);
    }
    return res;
}

int main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>node_lst[i].x>>node_lst[i].y;
    }
    for(int i=1;i<=n-1;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            node n1=node_lst[i],n2=node_lst[j];
            edge_lst.push_back(edge{i,j,sqrt(pow(n1.x-n2.x,2)+pow(n1.y-n2.y,2))});
        }
    }
    printf("%.2lf\n",kruskal());
    return 0;
}
