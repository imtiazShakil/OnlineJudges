#include <stdio.h>
#include <iostream>
#include <string.h>

#define oo (1<<25)
#define mem(a,b) memset(a,b,sizeof a)

using namespace std;

int n;
int arr[200];
int dp[110][110];

int rec(int start,int end)
{
    if(start>end) return 0;
    int &ret=dp[start][end];
    if(ret!=-1) return ret;

    ret=-oo;

    int sum=0;

    for(int i=start;i<=end;i++)
    {
        sum+=arr[i];
//        if(turn==0)
        {
            ret=max(ret,sum-rec(i+1,end));
        }
    }
    sum=0;
    for(int i=end;i>=start;i--)
    {
        sum+=arr[i];
        ret=max(ret,sum-rec(start,i-1));
    }
    return ret;


}
int main(void)
{
    int i,val,ans;
    while(scanf("%d",&n)==1 && n)
    {
        for(i=0;i<n;i++) {scanf("%d",&arr[i]);}
        mem(dp,-1);
        ans=rec(0,n-1);
        printf("%d\n",ans);
    }
}
