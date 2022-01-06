/*
ID: shakil1
PROG: milk3
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
//vector<int>sol;
map<int,int>M;
int dp[30][30][30];
int mx_a,mx_b,mx_c;

void rec(int a,int b,int c)
{
//    print3(a,b,c);
    if(a==0) M[c]=1;//{sol.pb(c);print1(c);}
    int &ret=dp[a][b][c];
    if(ret!=-1) return ;
    int dhal;
    ret=1;
    if(a)
    {
        dhal=min(mx_b,b+a ) -b;
        if(dhal!=0) rec(a-dhal,min(mx_b,b+a ),c);
        dhal=min(mx_c,c+a ) -c;
        if(dhal!=0) rec(a-dhal,b,min(mx_c,c+a ));
    }
    if(b)
    {
        dhal=min(mx_a,a+b ) -a;
        if(dhal!=0) rec(min(mx_a,a+b ),b-dhal,c);
        dhal=min(mx_c,c+b ) -c;
        if(dhal!=0) rec(a,b-dhal,min(mx_c,c+b ));
    }

    if(c)
    {
        dhal=min(mx_a,a+c ) -a;
        if(dhal!=0) rec(min(mx_a,a+c ),b,c-dhal);
        dhal=min(mx_b,c+b ) -b;
        if(dhal!=0) rec(a,min(mx_b,c+b ),c-dhal);
    }

    return ;

}
int main(void)
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w+",stdout);
    int a,b,c;
//    sol.clear();
    mem(dp,-1);
    scanf("%d %d %d",&a,&b,&c);
    mx_a=a;mx_b=b;mx_c=c;
    rec(0,0,mx_c);
    bool flag=0;
    for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
    {
        if(flag) printf(" %d",it->first);
        else printf("%d",it->first);
        flag=1;
    }
    puts("");
    return 0;
}

