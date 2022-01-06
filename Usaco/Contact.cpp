/*
ID: shakil1
PROG: contact
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
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define MAX 60

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

struct patterns
{
    string str;
    int freq;
};
vector<patterns>v;

bool com(patterns a,patterns b)
{
    if(a.freq!=b.freq) return a.freq>b.freq;
    else if( SZ(a.str)!=SZ(b.str) ) return SZ(a.str)<SZ(b.str);
    else return a.str<b.str;
}
int main(void)
{
    freopen("contact.in","r",stdin);
    freopen("contact.out","w+",stdout);
    map<string,int>M;
    int a,b,n;
    string   str2,str;
    scanf("%d %d %d",&a,&b,&n);
    while(cin>>str2)
    {
        str+=str2;
    }

    for(int len=a;len<=b;len++ )
    {
        for(int i=0;i+len<=SZ(str);i++)
        {
            M[ str.substr(i,len) ]++;
        }
    }
    patterns tmp;
    for(map<string,int>::iterator it=M.begin();it!=M.end();it++)
    {
        tmp.str=it->fs;
        tmp.freq=it->sc;
        v.pb(tmp);
//        print2(it->fs,it->sc);
    }
    sort(all(v),com);
//    int mn=min(SZ(v),n);
    int frq=-1;
    int cnt;
    int tot=0;
    cnt=0;
    for(int i=0;i<SZ(v);i++ )
    {

        if(v[i].freq!=frq)
        {
            tot++;
            if(tot>n) break;
            if(i) puts("");
            frq=v[i].freq;
            print1(frq);
            cnt=1;
            cout<<v[i].str;
        }
        else
        {
            if(cnt<6) {cout<<" "<<v[i].str;cnt++;}
            else {puts(""); cout<<v[i].str ; cnt=1;}

        }
    }
    puts("");
    return 0;
}

