#include<bits/stdc++.h>
using namespace std;

int q[100010],n;

void quick_sort(int a,int b)
{
    if(a>=b) return;
    int i=a-1,j=b+1,x=q[a];
    while(i<j)
    {
        do ++i;while(q[i]<x);
        do --j;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(a,i);
    quick_sort(i+1,b);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
    quick_sort(0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",q[i]);
    }
    return 0;
}
