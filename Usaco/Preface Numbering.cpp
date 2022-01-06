/*
ID: shakil1
PROG: preface
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
#define MAX 3600
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second

using namespace std;

struct roman
{
//    int I,V,X,L,C,D,M;
    int tp[7];
};

roman dp[MAX];
bool col[MAX];
int arr[]={1000,500,100,50,10,5,1};
int sp[]={900,400,90,40,9,4};
string str[]={"M" ,"D", "C","L","X","V","I"};

roman rec(int n)
{
//    print1(n);
    if(col[n]) return dp[n];

    roman &ret=dp[n];
    roman tmp;
    col[n]=1;

    for(int i=0;i<7;i++)
    {
        if(n>=arr[i])
        {
            ret.tp[i]+=(n/arr[i]);
            tmp=rec(n%arr[i]);
            for(int i=0;i<7;i++) ret.tp[i]+=tmp.tp[i];
            break;
        }
        else if(i<6)
        {
            if(n>=sp[i])
            {
                tmp=dp[sp[i]];
                for(int i=0;i<7;i++) ret.tp[i]+=tmp.tp[i];
                tmp=rec(n%sp[i]);
                for(int i=0;i<7;i++) ret.tp[i]+=tmp.tp[i];
                break;
            }
        }
    }
    return ret;
}

int main(void)
{
    freopen("preface.in","r",stdin);
    freopen("preface.out","w+",stdout);

    col[0]=1;
    col[4]=1;{dp[4].tp[6]=1;dp[4].tp[5]=1;}
    col[9]=1;{dp[9].tp[6]=1;dp[9].tp[4]=1;}
    col[40]=1;{dp[40].tp[4]=1;dp[40].tp[3]=1;}
    col[90]=1;{dp[90].tp[4]=1;dp[90].tp[2]=1;}
    col[400]=1;{dp[400].tp[2]=1;dp[400].tp[1]=1;}
    col[900]=1;{dp[900].tp[2]=1;dp[900].tp[0]=1;}

//    rec(1984);
//
//    for(int i=0;i<7;i++) print1(dp[1984].tp[i]);

    int n;
    roman sum,tmp2;for(int i=0;i<7;i++) sum.tp[i]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        tmp2=rec(i);
        for(int i=0;i<7;i++) sum.tp[i]+=tmp2.tp[i];
    }
    for(int i=6;i>=0;i--)
    {
        if(sum.tp[i]) print2(str[i],sum.tp[i]);
    }
//    puts("");
    return 0;
}

