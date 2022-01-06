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

paii prn(string str)
{
    int fl=0;
    string ad_1="lios";
    string ad_2="liala";

    string n_1="etr";
    string n_2="etra";

    string vrb1="initis";
    string vrb2="inites";


    string tmp;

    tmp.clear();
    for(int i=SZ(str)-4;i>=0 && i<SZ(str);i++ )
    {
        tmp+=str[i];
    }
    if(tmp==ad_1) return mp(1,1);
    if(tmp==n_2) return mp(2,2);


    tmp.clear();
    for(int i=SZ(str)-5;i>=0 && i<SZ(str);i++ )
    {
        tmp+=str[i];
    }
    if(tmp==ad_2) return mp(1,2);


    tmp.clear();
    for(int i=SZ(str)-3;i>=0 && i<SZ(str);i++ )
    {
        tmp+=str[i];
    }
    if(tmp==n_1) return mp(2,1);


    tmp.clear();
    for(int i=SZ(str)-6;i>=0 && i<SZ(str);i++ )
    {
        tmp+=str[i];
    }
    if(tmp==vrb1) return mp(3,1);
    if(tmp==vrb2) return mp(3,2);


    return mp(0,0);


}

int main(void)
{
    freopen("in.txt","r",stdin);

    int adj=0,noun=0,vrb=0;
    int ml=0,fml=0;

    string str;
    paii res;
    bool fl=0;

    while(cin>>str)
    {
//        print1(str);
        res=prn(str);
//        print2(res.fs,res.sc);

        if(res.fs==0) fl=1;

        if( res.fs==1)
        {
            if(noun || vrb) fl=1;
            adj=1;
        }
        if(res.fs==2)
        {
            if(vrb || noun ) fl=1;
            noun=1;
        }
        if(res.fs==3)
        {
            if(noun==0) fl=1;
            vrb=1;
        }

        if(res.sc==1) ml++;
        else if(res.sc==2) fml++;

    }
    if(ml && fml) fl=1;
    if(fl) puts("NO");
    else puts("YES");

    return 0;
}

