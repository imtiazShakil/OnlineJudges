/*
ID: shakil1
PROG: inflate
LANG: C++
*/

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

#define mem(a,b) memset(a,b,sizeof a)
#define SZ(x) ( (int)x.size() )
#define MAX 500
#define paii pair<int,int>
#define pb push_back
#define print1(a) cout<<a<<endl
#define fs first
#define sc second
#define mp make_pair
using namespace std;

int tm,n;
vector<paii>v;
int dp[10005];

int gen(void)
{
    dp[0]=0;
    int score=0;
    for(int i=0;i<SZ( v);i++)
    {
        for(int j=tm;j>=0;j--)
        {
            if(dp[j]>=0)
            {
                if( j+ v[i].sc<=tm )
                {
                    if( dp[j+v[i].sc]<0 ) dp[j+v[i].sc]=0;
                     dp[j+v[i].sc]=max(dp[j+v[i].sc],dp[j]+v[i].fs);
                }
            }
        }
    }
    for(int i=0;i<=tm;i++)
    {
        score=max(score,dp[i]);
    }
    return score;
}
int main(void)
{
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w+",stdout);

    int a,b;
    scanf("%d %d",&tm,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        v.pb(mp(a,b));
        for(int j=b+b;j<=tm;j+=b) v.pb(mp(a,b));
    }
    int ans=gen();
    print1(ans);

    return 0;
}
