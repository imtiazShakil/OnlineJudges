/*
ID: shakil1
PROG: friday
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

ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month
using namespace std;

int n;
int day[10];
bool leap(int year)
{
    if(year%4) return false;
    else
    {
        if(year%100==0)
        {
            if(year%400==0) return true;
            else return false;
        }
        else return true;
    }
}
void gen()
{
    int start=2;
    for(int i=1900;i<1900+n;i++)
    {
        for(int j=0;j<12;j++)
        {

            day[(start+12)%7]++;
            if(j==1 && leap(i)) start+=29;
            else start+=month[j];
            start%=7;
        }
    }
}
int main(void)
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w+",stdout);

    while(scanf("%d",&n)==1)
    {
        mem(day,0);
        gen();
        printf("%d",day[0]);
        for(int i=1;i<7;i++) printf(" %d",day[i]);
        puts("");
    }
}
