/*
ID: shakil1
PROG: stamps
LANG: C++
*/
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
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define MAX 2000005

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

int limit,mx;
vector<int>v;
int money[2000005];

int do_it(void)
{
    money[0]=0;
    for(int i=0;i<SZ(v);i++)
    {
        for(int j=0;j<=mx;j++)
        {
//            if( money[j]>=0 )
//            {
                if( j+v[i]<=mx )
                {
//                    if(money[j+v[i]]<0) money[j+v[i]]=0;
                    if( money[j]+1 <= limit) money[ j+v[i] ] = min( money[j+v[i]] , money[j]+1 );
//                    else break;
                }
//            }
        }
    }
    int tot=0;
    for(int i=0;i<=mx;i++)
    {
        if(money[i]<=limit) tot=i;
        else break;
    }
    return tot;
}
int main(void)
{
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w+",stdout);
    int n,itm;
    scanf("%d %d",&limit,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&itm);
        mx=max(mx,itm);
        v.pb(itm);
    }
//    sort(all(v));
//    mx=v[n-1];
    mx=mx*limit;

    for(int i=1;i<=mx;i++) money[i]=10000;

    int ans=do_it();
    print1(ans);

//    getchar();getchar();
    return 0;
}

