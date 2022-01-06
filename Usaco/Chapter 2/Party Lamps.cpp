/*
ID: shakil1
PROG: lamps
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

int n,c;

vector<int>on;
vector<int>off;
map<string,bool>M;

//vector<string>v;
bool s[4][MAX];
//bool s2[MAX];
//bool s3[MAX];
//bool s4[MAX];

void rec( int indx , bool num[] ,int depth)
{
    if(indx==4 || depth==c )
    {
        for(int i=0;i<SZ(on);i++)
        {
            if(num[on[i]]==0 ) return ;
        }
        for(int i=0;i<SZ(off);i++)
        {
            if( num[off[i]] ) return ;
        }

        string ans;ans.clear();
        for(int i=1;i<=n;i++)
        {
            if(num[i]) ans+='1';
            else ans+='0';
        }
//        v.pb(ans);
        M[ans]=1;
        return ;
    }

    bool num2[MAX];
    for(int i=1;i<=n;i++) num2[i]=num[i];

    for(int i=1;i<=n;i++)
    {
        if(s[indx][i]) num2[i]=!num[i];
    }

    rec(indx+1,num2,depth+1);
    rec(indx+1,num,depth);

    return ;

}

int main(void)
{
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w+",stdout);

    int val;
    bool arr[MAX];

    scanf("%d %d",&n,&c);
    while(scanf("%d",&val)==1 && val!=-1 )
    {
        on.pb(val);
    }
    while(scanf("%d",&val)==1 && val!=-1 )
    {
        off.pb(val);
    }

    for(int i=1;i<=n;i++) s[0][i]=1;
    for(int i=1;i<=n;i+=2) s[1][i]=1;
    for(int i=2;i<=n;i+=2) s[2][i]=1;
    for(int i=1;i<=n;i+=3) s[3][i]=1;


    for(int i=1;i<=n;i++) arr[i]=1;

//    puts("rec ");
    rec(0,arr,0);

//    sort(all(v));

    if( SZ(M) ==0) puts("IMPOSSIBLE");
//    else for(int i=0;i<SZ(v);i++) print1(v[i]);

    else
    {
        for(map<string,bool>::iterator it=M.begin();it!=M.end();it++) print1(it->fs);
    }
    return 0;
}

