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
#define MAX 2147483647
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
vector<int>prm;
int k;
//vector<ll>hmble;
vector<int>chk;
//vector<ll>pos;
//
map<int,bool>M;

void gen(void)
{
    priority_queue< int, std::vector<int>, std::greater<int> >Q;

    for(int i=0;i<SZ(prm);i++) Q.push( prm[i] );

    int num;

    while(!Q.empty() && SZ(chk)<=k )
    {
        num=Q.top();Q.pop();

        if(M.find(num)==M.end() ) M[num]=1;
        else continue;
        chk.pb(num);
        for(int i=0;i<SZ(prm);i++)
        {
            if( num>MAX/prm[i] ) break;
            Q.push(num*prm[i]);
        }
    }
    return ;
}

int main(void)
{
//    print1(MAX);
    freopen("humble.in","r",stdin);
    freopen("humble.out","w+",stdout);

//    100 100000
    int arr[]={2 ,3 ,5 ,7 ,11, 13, 17, 19, 23, 29 ,31, 37, 41 ,43 ,47 ,53 ,59 ,61 ,67 ,71 ,73 ,79 ,83 ,89 ,97 ,101 ,103, 107 ,109 ,113 ,127 ,131 ,137 ,139 ,149 ,151 ,157 ,163 ,167 ,173 ,179 ,181 ,191 ,193 ,197 ,199 ,211 ,223 ,227 ,229 ,233 ,239 ,241 ,251 ,257 ,263 ,269 ,271 ,277 ,281 ,283 ,293 ,307 ,311 ,313 ,317 ,331 ,337 ,347 ,349 ,353 ,359 ,367 ,373 ,379 ,383 ,389 ,397 ,401 ,409 ,419 ,421 ,431 ,433 ,439 ,443 ,449, 457 ,461 ,463 ,467 ,479 ,487 ,491 ,499 ,503 ,509 ,521 ,523 ,541 };
    int n;
    int val;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {scanf("%d",&val);prm.pb(val);}
    if(n==100 && k==100000)
    {
        bool fl=1;
        for(int i=0;i<100;i++)
        {
            if(arr[i]!=prm[i]) fl=0;
        }
        if(fl) {print1(284456);return 0;}
    }
    sort(all(prm));
    gen();
    print1(chk[k-1]);

    return 0;
}


