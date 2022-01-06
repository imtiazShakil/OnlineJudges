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
map<string,int>M1;
map<string,int>M2;
map<string,int>N;

int main(void)
{
//    freopen("out.txt","r",stdin);
    string str;
    int n,m;
    double k;
    int val;
    scanf("%d %d %lf",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        cin>>str>>val;
        M1[str]=val;
    }
    for(int i=0;i<m;i++)
    {
        cin>>str;
        M2[str]=0;
    }
    for(map<string,int>::iterator it=M1.begin();it!=M1.end();it++)
    {
        if((int)((double)it->sc *k + 1e-8) >=100 )  N[it->fs]=(int)((double)it->sc * k + 1e-8);
    }

    for(map<string,int>::iterator it=M2.begin();it!=M2.end();it++)
    {
        if(N.find(it->fs) ==N.end() ) N[it->fs]=0;
    }
    print1(SZ(N));
    for(map<string,int>::iterator it=N.begin();it!=N.end();it++)
        print2(it->fs,it->sc);
    return 0;
}

