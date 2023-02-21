#include<bits/stdc++.h>
using namespace std;
int n,q,mode,i,j,k;
map<pair<int,int>,int> box;

int main()
{
    scanf("%d%d",&n,&q);
    while(q--)
    {
        scanf("%d",&mode);
        if(mode==1)
        {
            scanf("%d%d%d",&i,&j,&k);
            box[{i,j}]=k;
        }
        else
        {
            scanf("%d%d",&i,&j);
            printf("%d\n",box[{i,j}]);
        }
    }
    return 0;
}