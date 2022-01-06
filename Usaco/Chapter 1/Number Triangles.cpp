/*
ID: shakil1
PROG: numtri
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
#define MAX 1005
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

vector<int>arr[MAX];
vector<int>best[MAX];

int main(void)
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w+",stdout);
    int r,val,p=1;
    scanf("%d",&r);
    while(p<=r)
    {
        for(int i=0;i<p;i++) {scanf("%d",&val);arr[p-1].pb(val);}p++;
    }
//    for(int i=0;i<r;i++,puts(""))
//        for(int j=0;j<SZ(arr[i]);j++) printf(" %d",arr[i][j]);

    for(int i=0;i<SZ(arr[r-1]) ;i++) best[r-1].pb(arr[r-1][i]);
//    for(int i=0;i<SZ(best[r-1]);i++) printf(" %d",best[r-1][i]);
    if(r>1)
    {
        for(int i=r-2;i>=0;i--)
        {
            for(int j=0;j<SZ(arr[i]);j++)
            {
                val=max(best[i+1][j],best[i+1][j+1]);
                best[i].pb(val+arr[i][j]);
            }
        }
    }
    print1(best[0][0]);

    return 0;
}

