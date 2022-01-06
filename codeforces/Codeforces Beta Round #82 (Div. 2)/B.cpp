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

struct lap
{
    int spd,ram,hdd,cost,indx;
    int flag;
};
vector<lap>v;

//bool ok()
//{
//
//}

bool com(lap a,lap b)
{
    if(a.flag!=b.flag) return a.flag>b.flag;
    if(a.cost!=b.cost) return a.cost<b.cost;

}
int main(void)
{
    int n;
    lap tmp;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        tmp.indx=i+1;tmp.flag=1;
        scanf("%d %d %d %d",&tmp.spd,&tmp.ram,&tmp.hdd,&tmp.cost);
        v.pb(tmp);
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(v[i].spd<v[j].spd && v[i].ram<v[j].ram && v[i].hdd<v[j].hdd)
                {
                    v[i].flag=0;
                }
            }
        }

    sort(all(v),com);
    print1(v[0].indx);

    return 0;
}
