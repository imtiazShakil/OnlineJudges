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
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
vector<int>v;
int main(void)
{
    int n,val,ans,strt,stp;
    while(scanf("%d",&n)==1 && n)
    {
//        M.clear();
        v.clear();
        while(n--)
        {
            scanf("%d",&val);
            v.pb(val);
        }
        ans=-1;
        sort(all(v));
        for(int i=SZ(v)-1;i>1;i--)
        {
            strt=0;
            stp=i-1;

            while(stp>strt && stp>=0 && strt<i )
            {

                val=v[strt]+v[stp];
                if(val>v[i]) stp--;
                else if(val<v[i]) strt++;
                else if(val==v[i]) {ans=max(ans,v[i]);break;}
            }
            if(ans!=-1) break;
        }
        print1(ans);
    }

    return 0;
}

