/*
ID: shakil1
PROG: ttwo
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

vector<string>v;

vector<string>movs;

paii change_dir(paii old)
{
    if( old.fs ==-1 && old.sc ==0) return mp(0,1);
    if( old.fs ==0 && old.sc ==1) return mp(1,0);
    if( old.fs ==1 && old.sc ==0) return mp(0,-1);
    if( old.fs ==0 && old.sc ==-1) return mp(-1,0);
}
bool mtch(string str)
{
    for(int i=0;i<SZ(movs );i++)
    {
        if(str==movs[i]) return true;
    }
    return false;
}


int go(paii fj,paii cow)
{
    int r_fj=fj.fs,c_fj=fj.sc,r_cow=cow.fs,c_cow=cow.sc;
    bool inf=0;
    int moves=0;
    paii dir_fj=mp(-1,0);
    paii dir_cow=mp(-1,0);

    char str[20];
    string tmp;

    while( (r_fj!=r_cow || c_cow!=c_fj )  )
    {
        sprintf(str,"%d%d%d%d",r_fj,c_fj,dir_fj.fs,dir_fj.sc);
        tmp.clear();
        tmp+=str;

        sprintf(str,"%d%d%d%d",r_cow,c_cow,dir_cow.fs,dir_cow.sc);
        tmp+=str;
        if(mtch(tmp)) return 0;
        else movs.pb(tmp);

        if( r_fj+dir_fj.fs>=SZ(v)  || r_fj+dir_fj.fs <0 || c_fj+dir_fj.sc>=SZ(v[0]) || c_fj+dir_fj.sc<0 )
        {
            dir_fj=change_dir(dir_fj);
        }
        else if( v[r_fj+dir_fj.fs ][c_fj+dir_fj.sc]=='*' ) dir_fj=change_dir(dir_fj);
        else {r_fj+=dir_fj.fs ; c_fj+=dir_fj.sc;}

        if( r_cow+dir_cow.fs>=SZ(v)  || r_cow+dir_cow.fs <0 || c_cow+dir_cow.sc>=SZ(v[0]) || c_cow+dir_cow.sc<0 )
        {
            dir_cow=change_dir(dir_cow);
        }
        else if( v[r_cow+dir_cow.fs ][c_cow+dir_cow.sc]=='*' ) dir_cow=change_dir(dir_cow);
        else {r_cow+=dir_cow.fs ; c_cow+=dir_cow.sc;}

        moves++;

    }

    return moves;
}
int main(void)
{
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w+",stdout);
    paii cow,fj;
    int mv;
    string str;
    for(int i=0;i<10;i++)
    {
        cin>>str;
        v.pb(str);
    }
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            if(v[i][j]=='F') {fj.fs=i;fj.sc=j;}
            if(v[i][j]=='C') {cow.fs=i;cow.sc=j;}
        }
     mv=go(fj,cow);
     print1(mv);
     return 0;
}

