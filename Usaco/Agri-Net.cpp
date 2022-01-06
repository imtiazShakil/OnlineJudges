/*
ID: shakil1
PROG: agrinet
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
#define MAX 120
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

int dst[MAX][MAX];
int par[MAX],n;
int rank[MAX];

struct path
{
    int frm,to,dst;
};
vector<path>v;

void make_set(int x)
{
    par[x]=x;
    rank[x]=0;
    return ;
}
int find_set(int x)
{
    if(x!=par[x]) par[x]=find_set(par[x]);
    return par[x];
}
void link(int x,int y)
{
    if(rank[x]>rank[y])
        par[y]=x;
    else par[x]=y;

    if(rank[x]==rank[y])
        rank[y]++;
    return ;
}
void u_nion(int x,int y)
{
    link(find_set(x),find_set(y));
    return ;
}
bool com(path a ,path b)
{
    if(a.dst<b.dst) return true;
    else return false;
}
int mst(void)
{
    path tmp;
    for(int i=0;i<n;i++) make_set(i);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                tmp.frm=i;tmp.to=j;tmp.dst=dst[i][j];
                v.pb(tmp);
            }
        }
    sort(all(v),com);

    int ddd=0;
    for(int i=0;i<SZ(v);i++)
    {
        if(find_set(v[i].frm) != find_set(v[i].to) )
        {
            u_nion(v[i].frm,v[i].to);
            ddd+=v[i].dst;
        }
    }
    return ddd;
}
int main(void)
{
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w+",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)    for(int j=0;j<n;j++) scanf("%d",&dst[i][j]);

    int ans=mst();
    print1(ans);


    return 0;
}

