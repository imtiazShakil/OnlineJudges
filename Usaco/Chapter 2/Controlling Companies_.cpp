/*
ID: shakil1
PROG: concom
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

//map< paii , bool>con;

int n;
struct nd
{
    int own[MAX];
}comp[MAX];

struct path
{
    int get,indx;
};

vector<path>v[MAX];
map<int,bool>M;

void rec(int node)
{
    if(M.find(node) !=M.end() ) return ;

//    print2("\nnode ",node);
    M[node]=1;
    queue<int>Q;
    map<int,bool>call;

    int top;
    for(int i=0;i<SZ(v[node]);i++ )
    {
        comp[node].own[v[node][i].indx]+=v[node][i].get;
        if( comp[node].own[v[node][i].indx] >50)
        {
//            print2("pushed initial ",v[node][i].indx);
            call[v[node][i].indx]=1;
            Q.push( v[node][i].indx );
        }
    }

    int c=0;
    while(!Q.empty())
    {
        top=Q.front();Q.pop();
//        print3("now call ",node,top);

        rec(top);
        if(top==node) continue;
        for(int i=1;i<=n;i++)
        {
            if( comp[node].own[i]+comp[top].own[i]>50  && comp[top].own[i] <50 && comp[top].own[i] >0  && call.find(i)==call.end() )
            {
//                print2("parent ",node);
//                print3("pushing ",top,i);
                Q.push(i);
                call[i]=1;
            }
            comp[node].own[i]+=comp[top].own[i];
        }
//        c++;
//        if(c>2) break;
    }

    return ;
}

int main(void)
{
//    freopen("concom.in","r",stdin);
//    freopen("concom.out","w+",stdout);
    n=0;
    int connc,u;
    path tmp;
    scanf("%d",&connc);
    while(connc--)
    {
        scanf("%d %d %d",&u,&tmp.indx,&tmp.get);
        n=max(n,u);
        n=max(n,tmp.indx);
        v[u].pb(tmp);
    }

    for(int i=1;i<=n;i++)
    {
        if(M.find(i)==M.end())
        {
//            print2("base call ",i);
            rec(i);
        }
    }
    puts("\n\n");
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=n;j++)
        {
            print3(i,j,comp[i].own[j]);
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(comp[i].own[j]>50 && i!=j) print2(i,j);
//            print3(i,j,comp[i].own[j]);
        }
    return 0;
}

