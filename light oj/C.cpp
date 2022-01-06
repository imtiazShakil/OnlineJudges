
#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define PRE         1e-8
#define SZ(a)       (int)a.size()
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)

#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define popc(i) (__builtin_popcount(i))

bool dp[1<<7][1<<7];
int par;

void rec(int now,int after)
{
    if(popc(after)==4)
    {
//        print2("after ",after);
        dp[par][after]=1;
        return ;
    }
    for(int i=0;i<7;i++)
    {
        if(now&(1<<i))
        {
            if((i-1)>=0)
            {
                if( ( after&(1<<(i-1)) )==0 )
                {
                    rec(now^(1<<i),after|(1<<(i-1) ) );
                }
            }
            if(i+1<7)
            {
                if( ( after&(1<<(i+1) ) )==0)
                {
                    rec(now^(1<<i),after|(1<<(i+1)) );
                }
            }
        }
    }
    return ;
}

void gen(int indx,int mask)
{
    if(indx>=8) return ;
    if(popc(mask)==4) {print2("parent ",mask);par=mask; rec(par,0); return ;}
    gen(indx+1,mask|(1<<indx) );
    gen(indx+1,mask);
    return ;
}
void gen(int mask)
{

    return ;
}

int main(void)
{
    gen(0,0);

//    par=120;
//    rec(120,0);

    return 0;
}
