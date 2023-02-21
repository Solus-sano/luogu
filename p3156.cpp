#include<bits/stdc++.h>
using namespace std;
int n,m,idx;
unordered_map<int,int> link;

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&link[i]);
    }
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&idx);
        printf("%d\n",link[idx]);
    }
    return 0;
}