#include<bits/stdc++.h>
using namespace std;
int n,ip[30],mp[25][25],lst[30],road[30],x0;
void prt(int x)
{
    if(road[x])
        prt(road[x]);
    printf("%d ", x);
}
int main() 
{
	cin >> n;
	memset(mp, 0, sizeof(mp));
	memset(lst, 0, sizeof(lst));
	for (int i = 1; i <= n;++i)
	{
		scanf("%d", &ip[i]);
	}
	for (int i = 1; i <= n-1;++i)
	{
		for (int j = i + 1; j <= n;++j)
		{
			scanf("%d", &mp[i][j]);
		}
	}
    for (int i = 1; i <= n;++i)
    {
        lst[i] = ip[i];
        for (int j = 1; j <= i - 1;++j)
        {
            if(mp[j][i]&&(lst[j]+ip[i])>lst[i])
            {
                lst[i] = lst[j]+ip[i];
                road[i] = j;
            }
        }
    }
    int ans = 0;
	for (int i = 1; i <= n;++i)
    {
        if(ans<lst[i])
        {
            ans = lst[i];
            x0 = i;
        }
    }
    prt(x0);
    printf("\n%d", ans);
    return 0;
}