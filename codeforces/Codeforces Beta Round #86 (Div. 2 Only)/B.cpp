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
map<string,int>M;
//vector<int>st[20];
//int conflct[20];
map<int,string>M2;

vector<int>ans;
struct nd
{
    int indx;
    int conf;
}node[20];

bool mat[20][20];

bool com(nd a, nd b)
{
    if(a.conf!=b.conf) return a.conf<b.conf;
    return a.indx<b.indx;
}

int main(void)
{
    nd tmp;
    int n,m;
    string str,str2;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        cin>>str;
//        M[str]=i+1;
        v.pb(str);
    }
    sort(all(v));
    for( int i=0;i<SZ(v);i++ ) {M[v[i]]=i;M2[i]=v[i]; }

//    for(map<string,int>::iterator it=M.begin();it!=M.end();it++) print2(it->first,it->sc);

    for(int i=0;i<m;i++)
    {
        cin>>str>>str2;
//        tmp.indx=M[str];
        node[M[str]].conf++;
        node[M[str2]].conf++;

        mat[ M[str]][ M[str2]]=1;
        mat[ M[str2]][ M[str]]=1;
//        print1(mat[ M[str]][ M[str2]]);

    }

//    for(int i=0;i<n;i++)
//        for(int j=0;j<n;j++) print3(i,j,mat[i][j]);

    for(int i=0;i<n;i++) node[i].indx=i;

//    for(int i=0;i<n;i++)
//    {
//
//        print2(node[i].indx,node[i].conf);
//
//    }
    sort(node,&node[n],com );

//    puts("sorted");

//    for(int i=0;i<n;i++)
//    {
//
//        print2(node[i].indx,node[i].conf);
//
//    }


//    for(int i=0;i<)
    for(int i=0;i<n;i++)
    {
//        if(SZ(ans)==0) ans.pb(node[i].indx);
//        else
//        {
            bool fl=0;
            for(int j=0;j<SZ(ans);j++)
            {
                if( mat[node[i].indx][ans[j]] ) fl=1;
            }
            if(!fl) ans.pb(node[i].indx);
//        }
    }
    print1(SZ(ans));
    vector<string>vvv;

    for(int i=0;i<SZ(ans);i++)
    {
//        print1(ans[i]);
        vvv.pb( M2[ans[i]] );
    }
    sort(all(vvv));

    for(int i=0;i<SZ(vvv);i++) print1(vvv[i]);
    return 0;
}

