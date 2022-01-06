/*
ID: shakil1
PROG: comehome
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
#define MAX 300
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

struct pth
{
    int to,dst;
} ;

vector<pth>v[MAX];

int dist[MAX];
struct vertice
{
    int node;
    int dist;

    bool operator<(const vertice & x)const
    {
        return dist>x.dist;
    }
} ;

bool relax(int u,int v,int w)
{
    if( dist[u]+ w<dist[v])
    {
        dist[v]=dist[u]+w;
        return true;
    }
    return false;
}
void dijkstra(int source)
{
    for(int i='a';i<='z';i++) dist[i]=oo;
    for(int i='A';i<='Z';i++) dist[i]=oo;

    dist[source]=0;
    vertice tmp,tmp2;
    tmp.dist=0;tmp.node=source;
    priority_queue<vertice>Q;
    map<int,bool>M;
    Q.push(tmp);
    while(!Q.empty())
    {
        tmp=Q.top();Q.pop();
        if(M.find(tmp.node)!=M.end() ) continue;
        M[tmp.node]=1;
        for(int i=0;i<SZ(v[tmp.node]);i++ )
        {
            if( relax(tmp.node,v[tmp.node][i].to,v[tmp.node][i].dst ) )
            {
                tmp2.node=v[tmp.node][i].to;
                tmp2.dist=dist[ v[tmp.node][i].to ];
                Q.push(tmp2);
            }
        }
    }
    return ;
}

int main(void)
{
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w+",stdout);
    char ch1[10],ch2[10];
    char cc1,cc2;
    int n;
    scanf("%d\n",&n);
    pth tmp;
    while(n--)
    {
        scanf("%s %s %d",ch1,ch2,&tmp.dst);
//        printf("%c %c \n",ch1,ch2);
        cc1=ch1[0];cc2=ch2[0];
        tmp.to=cc2;
        v[cc1].pb(tmp);
        tmp.to=cc1;
        v[cc2].pb(tmp);
//        puts("www");
    }
    int mn_d=oo;
    char node;
    dijkstra('Z');

    for(int i='A';i<'Z';i++)
    {
        if( SZ(v[i]) )
        {
//            dijkstra(i);
            if(mn_d>dist[i] )
            {
                node=i;
                mn_d=dist[i];
            }
        }
    }
    printf("%c %d\n",node,mn_d);

    return 0;
}

