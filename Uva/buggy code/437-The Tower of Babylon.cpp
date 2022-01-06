#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
#define mem(a,b) memset(a,b,sizeof a)
#define mp make_pair
using    namespace std;
int n;
//int base[50],width[50],height[50];
int dimension[50][3];
int arr[]={0,1,2};
//int dp[20000][20000];
map< pair<pair<int,int>,int> ,int >M;

int rec(int bas,int wid,int id)
{
    if(M.find( mp(mp(bas,wid ),id) ) != M.end() ) return M[ mp(mp(bas,wid),id) ];

    //int ret=M[ mp(bas,wid) ] ;//dp[bas][wid];
//    if(ret!=-1) return ret;
//    int ret;
    int ret=0;

    for(int i=0;i<n;i++)
    {
        while(next_permutation(arr,arr+3))
        {
            if(dimension[i][arr[0]] >bas && dimension[i][arr[1]] >wid )
            {
                ret=max(ret,dimension[i][arr[2]] + rec(dimension[i][arr[0]],dimension[i][arr[1]] ,dimension[i][arr[2]] ));
            }
        }
    }
    return M[ mp(mp(bas,wid),id) ]=ret;

    return ret;
}
int main(void)
{
    int i,j,ans,cas=0;
    while(scanf("%d",&n)==1 && n)
    {
        for(i=0;i<n;i++) scanf("%d %d %d",&dimension[i][0],&dimension[i][1],&dimension[i][2]);
//        mem(dp,-1);
        M.clear();
        ans=rec(0,0,0);
        printf("Case %d: maximum height = %d\n",++cas,ans);
    }

    return 0;
}
