#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define MAX 60
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

//bool flag;
int stcks[MAX],n,sum;
int avg;

int dp[1<<21];

//void rec(int indx,int up,int dwn,int lft)
//{
//    if(indx==n)
//    {
//        if(up == dwn && dwn== lft && dwn==(sum-up-dwn-lft) )  flag=1;
//        return ;
//    }
//    rec(indx+1,up+stcks[indx],dwn,lft);
//    if(flag) return ;
//
//    rec(indx+1,up,dwn+stcks[indx],lft);
//    if(flag) return ;
//
//    rec(indx+1,up,dwn,lft+stcks[indx] );
//    if(flag) return ;
//
//    rec(indx+1,up,dwn,lft);
//    if(flag) return ;
//
//}

int rec(int side,int mask,int len)
{
    if(side==4 && mask ) return 0;
    if(side==4 && mask==0 ) return 1;

    int &ret=dp[mask];
    if(ret!=-1) return ret;

    ret=0;
    for(int i=0;i<n;i++)
    {
        if((mask & (1<<i)) && len+stcks[i]<=avg)
        {
            if(len+stcks[i]==avg ) ret+=rec(side+1,mask^(1<<i),0);
            else ret+=rec(side,mask^(1<<i),len+stcks[i]);
            if(ret) return ret;
        }
    }
    return ret;

}
int main(void)
{
    int cas=0,ans;
    scanf("%d",&cas);
    while(cas--)
    {
//        flag=0;
        scanf("%d",&n);
        sum=0;
        for(int i=0;i<n;i++) {scanf("%d",&stcks[i]);sum+=stcks[i];}
        if(sum%4) {puts("no");continue;}
        else avg=sum/4;

        mem(dp,-1);
        ans=rec(0,(1<<n)-1,0);

        if(ans) puts("yes");
        else puts("no");
    }


    return 0;
}

