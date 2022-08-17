#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long m,n;
    cin>>m>>n;
    int a[10] = {0};
    for(int i = m;i <= n; i++)
    {
        int j = i;
        while(j > 0)
        {
            int x = j % 10;
            a[x] += 1;
            j = j / 10;
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);

    return 0;
}
