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
#define MAX 10005
#define max_vertice MAX
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

int n,m;
int peop[MAX];
//vector<int>v[MAX];

bool col[MAX];
//bool col2[MAX];
//
//void bfs(int num)
//{
//    int row,i,p;
//    queue<int>Q;
//
//    Q.push(num);
//
//    col[num]=1;
//
//    while(!Q.empty())
//    {
//        row=Q.front();
//        Q.pop();
//        col[row]=1;
//        for(i=0;SZ(v[row]);i++)
//        {
//            p=v[row][i];
//            if(col[p]==0)
//            {
//                Q.push(p);
//            }
//        }
//    }
//}
//
//void new_bfs(int num)
//{
//    int p,q;
//    queue<int>Q;
//    Q.push(num);
//    col2[num]=1;
//    while(!Q.empty())
//    {
//
//    }
//
//}




int parent[max_vertice];
int rank[max_vertice];

int find_set(int vertice)
{
    if(vertice!=parent[vertice])
        parent[vertice]=find_set(parent[vertice]);

    return parent[vertice];
}

void link(int u,int v)
{
    if(rank[u]>rank[v]) parent[v]=u;
    else parent[u]=v;

    if(rank[u]==rank[v])
        rank[v]++;

    return ;
}
void make_set(int vertice)
{
    rank[vertice]=0;
    parent[vertice]=vertice;

    return ;
}

void u_nion(int u,int v)
{
    link(find_set(u),find_set(v));
}


int main(void)
{
//    stack<int>s;
    int val1,val2,p,sum;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {scanf("%d",&peop[i]);make_set(i);}

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&val1,&val2);
        u_nion(val1,val2);
//        v[val1].pb(val2);v[val2].pb(val1);

    }

    bool flag=1;
    for(int i=0;i<n;i++)
    {
        if(col[i]==0)
        {
            col[i]=1;
            p=find_set(i);
            sum=peop[i];

            for(int j=0;j<n;j++)
            {
                if(col[j]==0 && find_set(j)==p)
                {
                    sum+=peop[j];
                    col[j]=1;
                }
            }
            if(sum) flag=0;
        }
    }
    if(flag) puts("POSSIBLE");
    else puts("IMPOSSIBLE");
    return 0;
}
