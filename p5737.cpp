#include<bits/stdc++.h>
using namespace std;

int run_nian(long a)
{
    if(a % 400 == 0 || a % 100 !=0 && a % 4 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    long x,y,sum = 0;
    cin>>x>>y;
    for(long i = x;i <= y;i++)
    {
        int k = run_nian(i);
        if(k == 1)
        {
            sum += 1;
        }
    }
    cout<<sum<<endl;
    for(long i = x;i <= y;i++)
    {
        int k = run_nian(i);
        if(k == 1)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
