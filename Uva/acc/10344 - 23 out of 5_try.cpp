#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#define mem(a,b) memset(a,b,sizeof a)

using namespace std;

int arr[5];
bool color[10];
char str[10];
int chk;
bool flag;

int rec(int sum,int indx)
{
//    cout<<sum<<" "<<indx<<endl;

    if(indx==5 && sum!=23 ) return 0;
    if(indx==5 && sum==23 ) return 1;

    int val;

    val=rec(sum+arr[str[indx] ],indx+1)  ;
    if(val)  return 1;

    val=rec(sum-arr[str[indx] ],indx+1)  ;
    if(val)  return 1;

    val=rec(sum*arr[str[indx] ],indx+1)  ;
    if(val)  return 1;

    return 0;

}

void bt(int depth)
{
    if(depth==5)
    {

        chk=arr[str[0]] + arr[str[1]];
        if( rec(chk,2) ) {flag=1;return ;}

        chk=arr[str[0]] - arr[str[1]];
        if( rec(chk,2) ) {flag=1;return ;}

        chk=arr[str[0]] * arr[str[1]];
        if( rec(chk,2) ) {flag=1;return ;}

        return ;
    }
    if(flag) return ;
    for(int i=0;i<5;i++)
    {
        if(flag) return ;
        if(color[i]==0)
        {
            str[depth]=i;
            color[i]=1;
            bt(depth+1);
            if(flag) return ;
            color[i]=0;
        }
    }
    return ;
}

int main(void)
{
    while(scanf("%d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4])==5 && (arr[0] || arr[1] ||arr[2] ||arr[3] || arr[4]  ) )
    {



        mem(color,0);mem(str,0);
        flag=0;
        bt(0);
        if(flag) puts("Possible");
        else puts("Impossible");
    }

}
