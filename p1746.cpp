#include<bits/stdc++.h>
using namespace std;
int n,box[1005][1005],dx[]={1,0,-1,0},dy[]={0,1,0,-1};
char idx[1005][1005];

void bfs(int x_init,int y_init,int x_2,int y_2)
{
    queue<pair<int,int>> que;
    que.push(pair<int,int>{x_init,y_init});
    // idx[x_init][y_init]=1;
    box[x_init][y_init]=1;
    while(que.size())
    {   
        pair<int,int> p_tmp=que.front();
        // cout<<p_tmp.first<<' '<<p_tmp.second<<endl;
        que.pop();
        if(p_tmp.first==x_2&&p_tmp.second==y_2)
        {
            cout<<box[x_2][y_2]-1<<endl;
            break;
        }
        
        for(int i=0;i<4;++i)
        {
            int nx=p_tmp.first+dx[i],ny=p_tmp.second+dy[i];
            if(1<=n&&nx<=n&&1<=ny&&ny<=n&&idx[nx][ny]=='0'&&box[nx][ny]==0)
            {
                box[nx][ny]=box[p_tmp.first][p_tmp.second]+1;
                que.push(pair<int,int>{nx,ny});
            }
        }
    }
}


int main()
{   
    int x_1,y_1,x_2,y_2;
    cin>>n;
    string str;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>idx[i][j];
        }
    }
    scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);
    bfs(x_1,y_1,x_2,y_2);
    return 0;
}