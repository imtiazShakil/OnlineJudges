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
#define MAX 16
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

ll dp[MAX][1<<15][3];

int items[MAX][MAX],n;

ll rec(int indx,int sho,int mtch)
{
    if(indx==n)
    {
        if(mtch) return 1;
        else return 0;
    }
    ll &ret=dp[indx][sho][mtch];
    if(ret!=-1) return ret;

    ret=0;

    for(int i=0;i<n;i++)
    {
        if( (sho&(1<<i))==0)
        {
            if(mtch==2 || items[indx][i]==2)
            {
                ret+=rec(indx+1,sho|(1<<i) , 2);
            }
            else if(mtch==1)
            {
                ret+=rec(indx+1,sho|(1<<i),items[indx][i]);
            }
            else  ret+=rec(indx+1,sho|(1<<i),0);
        }
    }
    return ret;

}

int main(void)
{
    int loop,cas=0,val;
    ll ans;
    scanf("%d",&loop);
    while(loop--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) scanf("%d",&items[i][j]);

//        mem(dp,-1);
        val=(1<<n) + 1;
        for(int i=0;i<n;i++)
            for(int j=0;j<val;j++) {dp[i][j][0]=-1;dp[i][j][1]=-1;dp[i][j][2]=-1;}

        ans=rec(0,0,1);
        printf("Case %d: %lld\n",++cas,ans);
//        cout<<ans<<endl;
    }
    return 0;
}

