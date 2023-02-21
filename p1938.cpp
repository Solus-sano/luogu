#include<bits/stdc++.h>
using namespace std;
int D,P,C,F,S,d[225];
struct edge
{
    int form;
    int to;
    int cost;
};
vector<edge> edge_lst;

void shortest_path(int s)
{
    fill(d,d+225,INT_MAX);
    d[s]=-D;
    while(1)
    {
        int update=0;
        for(int i=0;i<edge_lst.size();++i)
        {
            edge e=edge_lst[i];
            if(d[e.form]!=INT_MAX&&d[e.to]>d[e.form]+e.cost)
            {
                update=1;
                d[e.to]=d[e.form]+e.cost;
            }
        }
        if(update==0) break;
    }
}


int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>D>>P>>C>>F>>S;
    int tmp_from,tmp_to,tmp_cost;
    for(int i=1;i<=P;++i)
    {
        cin>>tmp_from>>tmp_to;
        edge_lst.push_back(edge{tmp_from,tmp_to,D*(-1)});
    }
    for(int i=1;i<=F;++i)
    {
        cin>>tmp_from>>tmp_to>>tmp_cost;
        edge_lst.push_back(edge{tmp_from,tmp_to,D*(-1)+tmp_cost});
    }
    int ans=0;
    shortest_path(S);
    for(int i=1;i<=C;++i) ans=min(ans,d[i]);
    cout<<ans*(-1);
    return 0;
}