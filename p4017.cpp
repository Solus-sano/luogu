#include<bits/stdc++.h>
using namespace std;
int n, m,lst[5010],a,b;
int mp[5010][5010],ru[5010],chu[5010];
queue<int> q;
int main()
{
    cin >> n >> m;
    while(m--)
    {
        scanf("%d%d", &a, &b);
        mp[a][b]=1;
        chu[a]++;
        ru[b]++;
    }
    for (int i = 1; i <= n;++i)
    {
        if(ru[i]==0)
        {
            q.push(i);
            lst[i] = 1;
        }
    }
    int ans = 0;
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for (int i = 1; i <= n;++i)
        {
            if(mp[tmp][i])
            {
                lst[i] += lst[tmp];
                lst[i] %= 80112002;
                ru[i]--;
                if(ru[i]==0)
                {
                    q.push(i);
                }
            }
        }
    }
    for (int i = 1; i <= n;++i)
    {
        if(chu[i]==0)
        {
            ans += lst[i];
            ans %= 80112002;
        }
    }
    cout << ans;
    return 0;
}