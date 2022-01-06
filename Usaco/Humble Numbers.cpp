/*
ID: shakil1
PROG: humble
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
vector<ll>prm;
int k;
vector<ll>hmble;
vector<ll>chk;
vector<ll>pos;

void gen(void)
{
    ll mn,indx=0,loc;
    for(int i=0;i<SZ(prm);i++) chk.pb(prm[i]);
    pos.pb(0);
    while(SZ( hmble )<k)
    {
        mn=-1;
        for(int i=indx;i<SZ(pos);i++)
        {
            if(pos[i]>=(i+1)*SZ(prm)) {indx++;continue ;}
            if( mn>chk[ pos[i] ] || mn==-1 )
            {
                mn=chk[pos[i]];
                loc=i;
            }
            else if( mn== chk[pos[i]] ) pos[i]++;
            else if(mn<chk[pos[i]] && pos[i]==i*SZ(prm) ) break;
        }
        pos[loc]++;
        hmble.pb(mn);
        pos.pb(SZ(chk));
        for(int i=0;i<SZ(prm);i++) chk.pb( mn*prm[i] );
    }
}

int main(void)
{
//    freopen("humble.in","r",stdin);
//    freopen("humble.out","w+",stdout);

    int n;
    ll val;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {scanf("%lld",&val);prm.pb(val);}
    sort(all(prm));
    gen();
    print1(hmble[k-1]);

    return 0;
}

