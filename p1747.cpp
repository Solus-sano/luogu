#include<bits/stdc++.h>
using namespace std;
int idx[25][25],box[25][25];
int x_lst[12]={1,1,2,2,2,2,-1,-1,-2,-2,-2,-2};
int y_lst[12]={-2,2,-2,-1,1,2,-2,2,-1,1,-2,2};
void bfs(int x_0, int y_0)
{
    memset(idx,0,sizeof(idx));
    idx[x_0][y_0]=1;
    box[x_0][y_0]=0;
    queue<pair<int,int>> que;
    que.push(pair<int,int>(x_0,y_0));

    while(!que.empty())
    {
        pair<int,int> p_tmp=que.front();
        if(p_tmp.first==1&&p_tmp.second==1)
        {
            break;
        }
        que.pop();
        for(int i=0;i<12;++i)
        {
            int dx=x_lst[i],dy=y_lst[i];
            int nx=p_tmp.first+dx;
            int ny=p_tmp.second+dy;

            if(1<=nx&&nx<=20&&1<=ny&&ny<=20&&idx[nx][ny]==0)
            {
                box[nx][ny]=box[p_tmp.first][p_tmp.second]+1;
                idx[nx][ny]=1;
                que.push(pair<int,int> {nx,ny});
            }
        }
    }
    cout<< box[1][1]<<endl;
}


int main()
{
    int x1,x2,y1,y2;
    scanf("%d%d",&x1,&y1);
    scanf("%d%d",&x2,&y2);
    bfs(x1,y1);
    bfs(x2,y2);
    // printf("%d\n%d",ans1,ans2);
    return 0;
}