#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,par[5005],rnk[5005],edge_cnt;

void init_union(int n)
{
    for(int i=1;i<=n;++i)
    {
        par[i]=i;
        rnk[i]=1;
    }
}

int find(int s){return par[s]==s ? s:find(par[s]);}

void unite(int u,int v)
{
    int x=find(u),y=find(v);
    if(x==y) return;
    else
    {
        if(rnk[x]<y)
        {
            par[x]=y;
        }
        else
        {
            par[y]=x;
            if(rnk[x]==rnk[y]) rnk[x]++;
        }
    }
}

struct edge
{
    int u;
    int v;
    int cost;
};
int cmp(edge a,edge b){return a.cost<b.cost;}

vector<edge> edge_lst;

int kruskal()
{
    sort(edge_lst.begin(),edge_lst.end(),cmp);
    init_union(n);
    edge_cnt=0;
    int res=0;
    for(int i=0;i<edge_lst.size();++i)
    {
        edge tmp_e=edge_lst[i];
        if(find(tmp_e.u)==find(tmp_e.v)) continue;
        unite(tmp_e.u,tmp_e.v);
        res+=tmp_e.cost;
        edge_cnt++;
    }
    return res;
}



int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        edge_lst.push_back(edge{x,y,z});
    }
    int ans=kruskal();
    if(edge_cnt!=n-1) printf("orz");
    else printf("%d\n",ans);
    return 0;
}