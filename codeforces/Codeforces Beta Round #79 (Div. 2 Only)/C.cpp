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
#define rep(x,n)        for(x=0;x<(int)(n);x++)
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
map<char,int>M;
struct ch
{
    char c;int freq;
};
vector<ch>v;
bool com(ch a,ch b)
{
    return a.freq<b.freq;
}
int main(void)
{
    string str;
    ch tmp;
    cin>>str;
    int cut,val,s=0;
    scanf("%d",&cut);
    for(int i=0;i<SZ(str);i++) M[str[i]]++;
    for(map<char,int>::iterator it=M.begin();it!=M.end();it++)
    {
        tmp.c=it->fs;
        tmp.freq=it->sc;
        v.pb(tmp);
    }
    sort(all(v),com);
    for(int i=0;i<SZ(v) && cut;i++)
    {
        val=min(cut,v[i].freq);
//        v[i].freq-=val;
        M[v[i].c]-=val;
        cut-=val;
    }
    for(map<char,int>::iterator it=M.begin();it!=M.end();it++)
    {
        if(it->second) s++;
    }
    print1(s);
    for(int i=0;i<SZ(str);i++)
    {
        if( M[str[i]] )
        {
            printf("%c",str[i]);
            M[str[i]]--;
        }
    }
    puts("");
    return 0;
}
