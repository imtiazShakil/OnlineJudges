/*
ID: shakil1
PROG: pprime
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
#define MAX 1000005
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
vector<int>ans;
bool num[MAX];
int prime[80000];
//set<int,bool>S;
void seive()
{
    int j,k=0;
    prime[0]=2;
    for(int i=3; i<MAX; i+=2)
    {
        if(!num[i])
        {
            prime[++k]=i;
            if(i<MAX/i) for(j=i*i; j<MAX; j+=i) num[j]=1;
        }
    }
//    print2(k,prime[k]);
}
int chk(int n)
{
    int sq=sqrt(n)+1;
    for(int i=0; prime[i]<sq; i++)
    {
        if((n%prime[i])==0) return 0;
    }
    return 1;
}
int main(void)
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w+",stdout);
    ans.clear();
    int d1,d2,d3,d4,d5,palindrome,a,b,len;
    seive();
    scanf("%d %d",&a,&b);
    len=log10(b)+1;
    int len2=log10(a)+1;
    bool flag=1;
    if(len>=1 && len2<=1)
    {
        if(flag)
        {
            for(d1=5;d1<=9 && flag;d1++)
            {
                if(d1>b) {break;flag=0;}
                if(chk(d1)) ans.pb(d1);
            }
        }
    }
    if(len>=2 && len2<=2)
    {
        for(d1=1; d1<=9 && flag; d1+=2)
        {
//            for(d2=0; d2<=9; d2++)
            {
                palindrome=d1*10 + d1;
//                if( chk() ) ans.pb(d1*100 + 10*d2 + d1);
                if(palindrome>b) {break;flag=0;}
                if(chk(palindrome)) ans.pb(palindrome);
            }
        }
    }
//
    if(len>=3 && len2<=3)
    {
        for(d1=1; d1<=9 && flag; d1+=2)
        {
            for(d2=0; d2<=9 && flag; d2++)
            {
                palindrome=d1*100 + 10*d2 + d1;
//                if( chk() ) ans.pb(d1*100 + 10*d2 + d1);
                if(palindrome>b) {break;flag=0;}
                if(chk(palindrome)) ans.pb(palindrome);
            }
        }
    }
    if(len>=4 && len2<=4)
    {
        for(d1=1; d1<=9 && flag; d1+=2)
        {
            for(d2=0; d2<=9 && flag; d2++)
            {
                palindrome=d1*1000 + 100*d2 +10*d2 + d1;
//                if( chk() ) ans.pb(d1*100 + 10*d2 + d1);
                if(palindrome>b) {break;flag=0;}
                if(chk(palindrome)) ans.pb(palindrome);
            }
        }
    }
    if(len>=5 && len2<=5)
    {
        for (d1 = 1; d1 <= 9 && flag; d1+=2)
        {
            for (d2 = 0; d2 <= 9 && flag; d2++)
            {
                for (d3 = 0; d3 <= 9 && flag ; d3++)
                {
                    palindrome=10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
//                    if(chk()) ans.pb(10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1);
                    if(palindrome>b) {break;flag=0;}
                    if(chk(palindrome) ) ans.pb(palindrome);
                }
            }
        }
    }
    if(len>=6 && len2<=6)
    {
        for (d1 = 1; d1 <= 9 && flag; d1+=2)
        {
            for (d2 = 0; d2 <= 9 && flag; d2++)
            {
                for (d3 = 0; d3 <= 9 && flag; d3++)
                {
                    palindrome=100000*d1 + 10000*d2 +1000*d3 +100*d3+ 10*d2 + d1;
//                    if(chk()) ans.pb(10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1);
                    if(palindrome>b) {break;flag=0;}
                    if(chk(palindrome) ) ans.pb(palindrome);
                }
            }
        }
    }
    if(len>=7 && len2<=7)
    {
        for (d1 = 1; d1 <= 9 && flag; d1+=2)
        {
            for (d2 = 0; d2 <= 9 && flag; d2++)
            {
                for (d3 = 0; d3 <= 9 && flag; d3++)
                {
                    for(d4=0;d4<=9 && flag ;d4++)
                    {
                        palindrome=1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2+ d1;
//                        if(chk() ) ans.pb(1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2+ d1);
                        if(palindrome>b) {break;flag=0;}
                        if(chk(palindrome) ) ans.pb(palindrome);
                    }
                }
            }
        }
    }
    if(len>=8 && len2<=8)
    {
        for (d1 = 1; d1 <= 9 && flag; d1+=2)
        {
            for (d2 = 0; d2 <= 9 && flag; d2++)
            {
                for (d3 = 0; d3 <= 9 && flag; d3++)
                {
                    for(d4=0;d4<=9 && flag ;d4++)
                    {
                        palindrome=10000000*d1 + 1000000*d2 + 100000*d3 + 10000*d4 + 1000*d4+100*d3 + 10*d2+ d1;
//                        if(chk() ) ans.pb(1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2+ d1);
                        if(palindrome>b) {break;flag=0;}
                        if(chk(palindrome) ) ans.pb(palindrome);
                    }
                }
            }
        }
    }

    if(len>=9 && len2<=9)
    {
        for (d1 = 9; d1 <= 9 && flag; d1+=2)
        {
            for (d2 = 0; d2 <= 9 && flag; d2++)
            {
                for (d3 = 0; d3 <= 9 && flag; d3++)
                {
                    for(d4=0;d4<=9 && flag;d4++)
                    {
                        for(d5=0;d5<=9 && flag;d5++)
                        {
                            palindrome=100000000*d1 + 10000000*d2 + 1000000*d3 + 100000*d4 + 10000*d5 + 1000*d4 + 100*d3 + 10*d2+ d1;
//                            print1(palindrome);
                            if(palindrome>b) {break;flag=0;}
                            if(chk(palindrome) ) ans.pb(palindrome);
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<SZ(ans);i++)
    {
        if(ans[i]>=a && ans[i]<=b) print1(ans[i]);
    }
    return 0;
}
