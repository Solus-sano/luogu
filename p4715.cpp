#include<bits/stdc++.h>
using namespace std;
const int MAX_CNT=1<<7;
typedef pair<int,int> node;
int n,p;
node dat[MAX_CNT*2+5];

node get_max(node a,node b){return a.second>b.second ? a:b;}
node get_min(node a,node b){return a.second<b.second ? a:b;}

void init(int n_)
{
    int cnt=1;
    while(cnt<n_) cnt*=2;
    for(int i=1;i<=2*cnt-1;++i) dat[i]=node{0,0};
}

int main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>n;
    n=pow(2,n);
    init(n);
    for(int i=1;i<=n;++i)
    {
        cin>>p;
        int idx=i+n-1;
        dat[idx]=node{i,p};
        while(idx>=1)
        {
            idx/=2;
            dat[idx]=get_max(dat[idx*2],dat[idx*2+1]);
        }
    }
    // for(int i=1;i<=2*n-1;++i) printf("%d ",dat[i].second);
    // cout<<endl;
    node ans=get_min(dat[2],dat[3]);
    cout<<ans.first;
    return 0;
}