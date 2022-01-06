#include <stdio.h>
#include <iostream>

#define MAX 20000
using namespace std;

int arr[MAX],t;

void gen(int n,int m)
{
    int i,j,k;
    for(i=0;i<=t;i++) arr[i]=0;

    int sm=min(n,m);
    for(i=sm,j=1;i<=t;i+=sm,j++)    arr[i]=j;

//    printf("--> %d\n ",arr[t] );

    int bg=max(n,m);
    if(bg<=t) arr[bg]=max(arr[bg],1);

    for(i=0;i<=t;i++)
    {
        if(i+bg<=t && arr[i] )
        {
            arr[i+bg]=max(arr[i+bg],arr[i]+1);
        }
    }
    return ;
}
int main(void)
{
    int n,m,i,j,beer,flag;
    while(scanf("%d %d %d",&n,&m,&t)==3)
    {
        gen(n,m);
        if( arr[t] ) printf("%d\n",arr[t]);
        else
        {
            for(beer=1,flag=0;beer<=t;beer++)
            {
                if( arr[t-beer] )
                {
                    flag=1;
                    printf("%d %d\n",arr[t-beer],beer);
                    break;
                }
            }
            if(flag==0) printf("0 %d\n",t);
        }
    }
    return 0;
}
