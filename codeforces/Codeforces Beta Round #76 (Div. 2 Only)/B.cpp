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
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x.begin(),x.end())
#define mp make_pair
#define MAX 60
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

int main(void)
{
    int n,p;
    scanf("%d",&n);
    vector<int>m;
    vector<int>v[6];
    int a,b;
    map<paii,int>M;
    while(n--)
    {
        scanf("%d %d",&a,&b);
        M[mp(a,b)]=1;M[mp(b,a)]=1;
        v[a].pb(b);v[b].pb(a);
    }
    bool flag_ac=0;
    for(int i=1;i<=5;i++)
    {
        if(SZ(v[i])<2) continue;
        else
        {
            m.clear();
            for(int j=0;j<SZ(v[i]);j++) m.pb(v[i][j]);

            for(int j=0;j<SZ(m);j++)
                for(int q=j+1;q<SZ(m);q++)
                {
                    if(M[ mp(m[j],m[q]) ])
                    {
                        flag_ac=1;
                        break;
                    }
                }
        }
    }
    if(flag_ac) {puts("WIN");return 0;}

    bool flag_uac=0;
    for(int i=1;i<=5;i++)
    {
        if(SZ(v[i])>2) continue;
        else
        {
            m.clear();
            map<int,int>mm;
            for(int j=0;j<SZ(v[i]);j++) mm[v[i][j]]=1;
            mm[i]=1;

            for(int j=1;j<=5;j++)
            {
                if(mm[j]==0) m.pb(j);
            }

            for(int j=0;j<SZ(m);j++)
                for(int q=j+1;q<SZ(m);q++)
                {
                    if(M[ mp(m[j],m[q]) ]==0)
                    {
                        flag_uac=1;
                        break;
                    }
                }
        }
    }
    if(flag_uac) {puts("WIN");return 0;}
    else puts("FAIL");

    // puts("WIN");
    //else puts("FAIL");
    return 0;
}

