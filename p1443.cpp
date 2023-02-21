#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ip[410][410];
int dx[]={2,2,-2,-2,1,1,-1,-1},dy[]={1,-1,1,-1,2,-2,2,-2};
struct node{
    int x0;
    int y0;
};
queue<node> Q;
void mov(int a,int b)
{
    node tmp,tmp1;
    tmp.x0=a;
    tmp.y0=b;
    Q.push(tmp);
    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();
        for(int i=0;i<8;++i)
        {
            int nx=tmp.x0+dx[i],ny=tmp.y0+dy[i];
            if(1<=nx&nx<=n&&1<=ny&&ny<=m)
            {
                if((ip[tmp.x0][tmp.y0]+1)<ip[nx][ny]||ip[nx][ny]==-1)
                {
                    ip[nx][ny]=ip[tmp.x0][tmp.y0]+1;
                    tmp1.x0=nx;
                    tmp1.y0=ny;
                    Q.push(tmp1);
                }
            }
        }
    }
}
int main()
{
    cin>> n>>m>>x>>y;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            ip[i][j]=-1;
        }
    }
    ip[x][y]=0;
    mov(x,y);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            printf("%-5d",ip[i][j]);
        }
        printf("\n");
    }
    return 0;
}
