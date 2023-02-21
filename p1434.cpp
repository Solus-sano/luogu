#include<bits/stdc++.h>
using namespace std;
int a,b,ip[110][110],lst[110][110],dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
void opt(int x,int y)
{
    if(lst[x][y])
        return;
    lst[x][y] = 1;
    for (int i = 0; i < 4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(ip[x][y]>ip[nx][ny]&&1<=nx&&nx<=a&&1<=ny&&ny<=b)
        {
            opt(nx, ny);
            lst[x][y] = max(lst[x][y], lst[nx][ny]+1);
        }
    }
    return;
}
int main()
{
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= a;i++)
    {
        for (int j = 1; j <= b;++j)
        {
            scanf("%d", &ip[i][j]);
        }
    }
    memset(lst, 0, sizeof(lst));
    int ans = 1;
    
    for (int i = 1; i <= a;++i)
    {
        for (int j = 1; j <= b;++j)
            opt(i, j);
    }
    for (int i = 1; i <= a;++i)
    {
        for (int j = 1; j <= b;++j)
            ans = max(ans, lst[i][j]);
    }
    printf("%d\n", ans);
    return 0;
}