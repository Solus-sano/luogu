#include<bits/stdc++.h>
using namespace std;

int jie_cheng(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * jie_cheng(n - 1);
    }
}

int main()
{
    int a;
    long long x;
    scanf("%d",&a);
    x = jie_cheng(a);
    cout << x <<endl;
    return 0;
}

