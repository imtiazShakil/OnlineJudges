/*
ID: shakil1
PROG: fracdec
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

//bool col[MAX];

int main(void)
{
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);

    int n,d,mod;

    map<int,int>M;
    vector<int>v;
    string div,frac,tmp;
    stringstream ss;

    scanf("%d %d",&n,&d);

    ss<<n/d;
    ss>>div;
    div+=".";

//    print2("div ",div);

    mod=n%d;
    bool fl=0,rep=0;
    int rep_num;
    M[mod]=1;
//    col[mod]=1;
    v.pb(mod);
//    print2("blah ",mod);

//    print2("mod ",M[mod]);
    while(mod)
    {
        if(mod/d ==0 && fl==0)
        {
            fl=1;
            mod=mod*10;
            if(M.find(mod)!=M.end() )  {rep=1;rep_num=mod;frac+= ( ( mod/d) +'0' );break;}
            else M[mod]=1;
        }
        else if(mod/d==0 && fl)
        {
            frac+='0';
            mod=mod*10;

            v.pb(mod);
            if(M.find(mod)!=M.end() )  {rep=1;rep_num=mod;frac+= ( ( mod/d) +'0' );break;}
            else M[mod]=1;
        }
        else
        {
//            ss.clear();
//            ss<<mod/d;
//            tmp.clear();
//            ss>>tmp;
//            frac+=tmp;
            frac+= ( ( mod/d) +'0' );
            mod=mod%d;
            fl=0;
            v.pb(mod);
            if(M.find(mod)!=M.end() )  {rep=1;rep_num=mod;break;}
            else M[mod]=1;
//            col[mod]=1;
        }

//        if(mod==0) break;

    }//while(mod!=0);

    if(rep)
    {
        int indx;
//        print2("rep num",rep_num);

//        for(int i=0;i<SZ(v);i++) print2("modded num ",v[i]);

        for(int i=0;i<SZ(v);i++)
        {
            if(rep_num==v[i] )
            {
                indx=i;break;
            }
        }
        frac.insert(indx,"(");
        frac+=")";
    }
    if(SZ(frac)==0) frac="0";
    string ans=div+frac;

//    print2("frac ",frac);

    for(int i=0;i<SZ(ans);i++)
    {
        if(i%76==0 && i) puts("");
        cout<<ans[i];
    }
    puts("");
//    print1(ans);

    return 0;
}

