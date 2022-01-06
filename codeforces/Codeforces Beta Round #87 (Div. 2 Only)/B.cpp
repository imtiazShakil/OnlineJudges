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

int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
vector<string>v;

struct wolf
{
    int pig;
    int row,col;
};
vector<wolf>w;

bool com(wolf a,wolf b)
{
    if(a.pig<b.pig) return true;
    else return false;
}
int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    string str;
    for(int i=0;i<n;i++) {cin>>str;v.pb(str);}

    wolf tmp;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='W')
            {
                tmp.pig=0;tmp.row=i;tmp.col=j;
                int r=i,c=j,m,n;
                for(int p=0;p<4;p++)
                {
                    m=r+rrr[p];
                    n=c+ccc[p];
                    if(m>=0 && m<SZ(v) && n>=0 && n<SZ( v[i]) )
                    {
                        if(v[m][n]=='P') tmp.pig++;
                    }
                }
                w.pb(tmp);
            }
        }

    sort(all(w),com);

    int piiig=0;

    for(int i=0;i<SZ(w);i++)
    {
        int r=w[i].row,c=w[i].col,m,n;
        for(int p=0;p<4;p++)
        {
            m=r+rrr[p];
            n=c+ccc[p];
            bool fl=0;
             if(m>=0 && m<SZ(v) && n>=0 && n<SZ( v[w[i].row] ) )
            {
                if(v[m][n]=='P') {v[m][n]='.';piiig++;fl=1;}
            }
            if(fl) break;
        }
    }
    print1(piiig);

    return 0;
}

