/*
ID: shakil1
PROG: runround
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

ll arr[]={10,100,1000,10000,100000,1000000 ,10000000,100000000};
char str[12];
bool col[12];
short vvv[10];

bool chk(ll num)
{
    int c=0,indx=0,val;
    mem(str,0);
    int len=log10(num) + 1,org;
    org=len;
    if(len>9) return true;
    mem(vvv,0);
    while(len>1)
    {
        str[c++]=(num/arr[len-2] + '0');
        vvv[str[c-1]-'0']++;

        num%=arr[len-2] ;
        len=log10(num) + 1;
    }
    str[c++]=num+'0';
    vvv[num]++;

    if(c!=org) return false;
    for(int i=1;i<=9;i++) if(vvv[i]>1) return false;

    mem(col,0);

    while(col[indx]==0)
    {
        col[indx]=1;
        val=(str[indx]-'0' + indx)%c;
        indx=val;
    }

    for(int i=0;i<c;i++) if(col[i]==0) return false;

    if(indx) return false;
    else return true;

}
int main(void)
{

    freopen("runround.in","r",stdin);
    freopen("runround.out","w+",stdout);
    ll n;
    while(cin>>n)
    {
        for(ll i=n+1; ; i++)
        {
            if(chk(i)) {print1(i);break;}
        }
    }
    return 0;
}

