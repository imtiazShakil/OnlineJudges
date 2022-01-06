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
#define MAX 2005
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

map<int,int>M;
vector<int>v[MAX];
int level[MAX];
int mx_lev;
int dgre[MAX];

void dfs(int source)
{
    if(M.find(source)!=M.end()) return ;
    M[source]=1;

    for(int i=0;i<SZ(v[source]);i++ )
    {
        level[v[source][i]]=level[source]+1;
        mx_lev=max(mx_lev,level[source]+1);
        dfs(v[source][i]);
    }
}

int main(void)
{
    int n,p;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p);
        if(p>0)
        {
            v[p].pb(i);
            dgre[i]++;
        }
    }
//    vector<int>st;
    queue<int>Q;
    for(int i=1;i<=n;i++)
    {
        if(dgre[i]==0)
        {
            Q.push(i);
        }
    }

//    for(int i=1;i<=n;i++)
//    {
//        if(M.find(i)==M.end())
//        {
//            dfs(i);
//        }
//    }
    while(!Q.empty())
    {
        if(M.find(Q.front())==M.end())
        {
            dfs(Q.front());
        }
        Q.pop();
    }
    print1(mx_lev+1);

    return 0;
}
