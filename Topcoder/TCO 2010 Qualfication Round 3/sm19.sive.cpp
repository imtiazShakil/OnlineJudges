#include<stdio.h>
#include<math.h>
#define num 200000000
#define pri 80000000

bool flag[num];
int prime[pri];

void sive(void)
{
    int i,j,l,r,c=1;
    for(i=3;i<=num;i+=2) flag[i]=1;
    prime[c]=2;
    flag[2]=1;
    for(i=3;i<num;i+=2)
    {
        if(flag[i])
        {
            prime[++c]=i;
            if(num/i>=i)
            {
                r=i*2;
                for(j=i*i;j<num;j+=r)
                    flag[j]=0;
            }
        }
    }
    printf("Last prime %d\n",prime[c]);
}

int main()
{
      sive();
    int i,j,x,n;
    while(scanf("%d", &n)==1)
    {
        j=0;
        if(n==1) j=1;
        x=1+sqrt(n);
        for(i=1;prime[i]<x;i++)
        {
            if(n%prime[i]==0)
            {
                j++;
                break;
            }
        }
        if(j) printf("Not prime\n");
        else printf("Prime\n");
    }
    return 0;
}
