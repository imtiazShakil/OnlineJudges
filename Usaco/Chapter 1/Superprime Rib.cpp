/*
ID: shakil1
PROG: sprime
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
#define MAX 1000000
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

bool num[MAX];
int prime[80000],n;
//vector<int>ans;
void seive()
{
    int j,k=0;
    prime[0]=2;
    for(int i=3; i<MAX; i+=2)
    {
        if(!num[i])
        {
            prime[++k]=i;
            if(i<MAX/i) for(j=i*i; j<MAX; j+=i) num[j]=1;
        }
    }
//    print2(k,prime[k]);
}
int chk(int n)
{
    if(n==1) return 0;
    int sq=sqrt(n)+1;
    for(int i=0; prime[i]<sq; i++)
    {
        if((n%prime[i])==0) return 0;
    }
    return 1;
}

void rec(int num,int depth)
{
    if(chk(num)==0) return ;
    if(depth==n-1)
     {
         if(chk(num)) {print1(num);/*ans.pb(num);*/return ;}
         else return ;
     }
     for(int i=1;i<=9;i+=2)
     {
         rec(num*10+i,depth+1);
     }
     return ;
}

int main(void)
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w+",stdout);
    seive();
    scanf("%d",&n);
    rec(2,0);
    for(int i=3;i<=9;i+=2) rec(i,0);

    return 0;
}

