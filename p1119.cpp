#include<bits/stdc++.h>
using namespace std;
int N,M,Q,t_lst[205],d[205];
int D[205][205];


int main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j) D[i][j]=1e9;
    }
    for(int i=0;i<N;++i) D[i][i]=0;

    for(int i=0;i<N;++i) cin>>t_lst[i];
    int ip_u,ip_v,ip_w;
    for(int i=1;i<=M;++i)
    {
        cin>>ip_u>>ip_v>>ip_w;
        D[ip_u][ip_v]=D[ip_v][ip_u]=ip_w;
    }
    cin>>Q;
    int ip_x,ip_y,ip_t,idx=0;
    while(Q--)
    {
        cin>>ip_x>>ip_y>>ip_t;
        while (t_lst[idx]<=ip_t&&idx<N)
        {
            for(int i=0;i<N;++i)
            {
                for(int j=0;j<N;++j) D[i][j]=min(D[i][j],D[i][idx]+D[idx][j]);
            }
            idx++;
        }
        if(t_lst[ip_x]>ip_t||t_lst[ip_y]>ip_t) printf("-1\n");
        else
        {
            if(D[ip_x][ip_y]==1e9) printf("-1\n");
            else printf("%d\n",D[ip_x][ip_y]);
        }
        
    }
    return 0;
}