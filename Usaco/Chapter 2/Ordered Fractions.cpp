/*
ID: shakil1
PROG: frac1
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
#define MAX 60
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
struct frac
{
    int a,b;
    double val;
} ;
vector<frac>v;
bool com(frac a,frac b)
{
    return a.val<b.val;
}

int main(void)
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w+",stdout);

    int n,chk;map<paii,bool>M;
    frac tmp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i==1)
            {
                tmp.a=0;tmp.b=i;tmp.val=double((double)tmp.a/(double) tmp.b );v.pb(tmp);
            }
            if(j)
            {
                chk=__gcd(j,i);
                if( M.find(mp( j/chk,i/chk ))==M.end() )
                {
                    tmp.a=j;tmp.b=i;tmp.val=double((double)tmp.a/(double)tmp.b);v.pb(tmp);
                    M[mp( j/chk,i/chk) ]=1;
                }
            }
        }
    }
    tmp.a=1;tmp.b=1;tmp.val=1.0;v.pb(tmp);
    sort(all(v),com);
    for(int i=0;i<SZ(v);i++) printf("%d/%d\n",v[i].a,v[i].b);
    return 0;
}

