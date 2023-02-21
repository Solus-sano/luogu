#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum;
    int n;
    int a[100];
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = 0; j < i; j++)
        {
            if(a[i] > a[j])
            {
                sum += 1;
            }
        }
        if(i == 0)
        {
            printf("%d",sum);
        }
        else
        {
            printf(" %d",sum);
        }
    }
    return 0;
}
