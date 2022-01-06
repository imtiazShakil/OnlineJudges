/*
ID: shakil1
PROG: barn1
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
#define MAX 100000
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

struct rng
{
    int low,high,dist;
};
vector<rng>v;
bool com(rng a,rng b)
{
    return a.dist<b.dist;
//    if(a.dist>b.dist) return false;
//    else return true;
}
int main(void)
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);

    rng tmp;
    int m,s,c,barn[MAX],val,plate=0,strt=oo,stp=0;v.clear();
    scanf("%d %d %d",&m,&s,&c);mem(barn,0);
    while(c--)
    {
        scanf("%d",&val);barn[val]=1;strt=min(strt,val);stp=max(val,stp);
    }
    for(int i=strt,flag=0;i<=stp;i++)
    {
        if(flag==0 && barn[i]) plate++;
        flag=barn[i];
    }
//    print2(strt,stp);
    for(int i=strt;i<stp;i++)
    {
        if(barn[i])
        {
            if(barn[i+1]) continue;
            else
            {
                int j;
                for(j=i+1;j<=stp && barn[j]!=1 ;j++) ;
                tmp.low=i;
                tmp.high=j;
                tmp.dist=j-i;
                v.pb(tmp);
                i=--j;
            }
        }
    }
    sort(all(v),com);
//    for(int i=0;i<SZ(v);i++) print3(v[i].low,v[i].high,v[i].dist);
//    print2("plate",plate);
    int indx=0;
    while(plate>m)
    {
        for(int i=v[indx].low;i<=v[indx].high;i++ ) barn[i]=1;
        indx++;
        plate--;
    }
    int tot=0;
    for(int i=strt;i<=stp;i++) if(barn[i]) tot++;
    print1(tot);
    return 0;
}

