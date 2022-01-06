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
#define MAX 1000002
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

int dp[MAX];
int s_tree[4*MAX];

int rec(ll n)
{
    if(n==1) return 1;
    if(n>MAX)
    {
        int steps=0;
//         val=n;
        while(n!=1)
        {
            if(n%2) n=3*n+1;
            else n/=2;
            steps++;
            if(n<MAX) return rec(n) + steps;
        }
        return steps;
    }

    int &ret=dp[n];
    if(ret!=-1) return ret;
    ret=0;
    if(n%2) ret=rec(3*n+1) + 1;
    else ret=rec(n/2) + 1;
    return ret;
}

int segment_tree(int node,int i,int j)
{
    if(i==j)
    {
        s_tree[node]=dp[i];
        return dp[i];
    }
    s_tree[node]=max( segment_tree(node*2,i,(i+j)/2) , segment_tree(node*2 + 1,(i+j)/2 + 1,j )  );
    return s_tree[node];
}

int srch_tree(int node,int lft,int rght,int i,int j) /// i & j are the srch criteria we are looking for
{
    if(i>rght || j<lft) return -1; /// outside the range

    if( lft>=i && rght<=j ) return s_tree[node];

    int mx=srch_tree(node*2 , lft, (lft+rght)/2 ,i,j ) ;
    mx=max(mx, srch_tree(node*2 + 1, (lft+rght)/2 + 1, rght,i,j ) );

    return mx;
}

int main(void)
{
    mem(dp,-1);
//    mem(tre_e,-1);
    dp[1]=1;dp[2]=2;
    for(ll i=3;i<MAX;i++) rec(i);
    segment_tree(1,1,MAX);

    int i,j,val;
    while(scanf("%d %d",&i,&j)==2)
    {
        val=srch_tree(1,1,MAX, min(i,j) , max(i,j)  );
        print3(i,j,val);
    }

    return 0;
}

