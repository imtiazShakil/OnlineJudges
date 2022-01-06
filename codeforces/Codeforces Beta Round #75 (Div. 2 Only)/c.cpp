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
#define oo (1<<25)
#define MAX 10000

using namespace std;
string s1,s2;

int dp[MAX][MAX];
//char add_str[MAX][MAX];

int rec(int i,int j)
{
//    if(i<=-1 && j>0 ) return oo;
//    if(i>0 && j<=-1) return oo;
    if(i==(int)s1.size() && j==(int)s2.size() ) return 0;
    else if(i>(int)s1.size() || j>(int)s2.size() ) return oo;


    int &ret=dp[i][j];
    if(ret!=-1) return ret;

    ret=oo;
    int mn,mn2,sm;
    if(i<(int)s1.size() && j<(int)s2.size())
    {
        if(s1[i]==s2[j]) ret=min(ret,rec(i+1,j+1));
        else
        {
//            puts("call");
            mn=rec(i+1,j);
            mn2=rec(i,j+1)+1;
            sm=min(mn,mn2);
            if(ret>sm)
            {
                ret=sm;
//                if(sm==mn2) add_str[j]=s2[j];
            }
//            ret=min(ret,mn);
        }
    }
    else
    {
//        puts("call");
        if(i<(int)s1.size() ) ret=min(ret,rec(i+1,j) ) ;
        else if(j<(int)s2.size() )
        {
            mn=rec(i,j+1)+1;
            if(ret>mn)
            {
                ret=mn;
//                add_str[j]=s2[j];
            }
//            ret=min(ret,rec(i,j+1) + 1);
        }
    }

    return ret;

}
int main(void)
{
    bool col[300],col2[300];
    bool flag;
    int swapped;
    while(cin>>s1>>s2)
    {
        flag=0;
        mem(dp,-1);//mem(table,0);
//        mem(add_str,0);
//        reverse(s1.begin(),s1.end());reverse(s2.begin(),s2.end());
        mem(col,0);mem(col2,0);
        for(int i=0;i<(int)s1.size();i++)
            col[s1[i]]=1;
        for(int i=0;i<(int)s2.size();i++)
            if( col[s2[i]]==0 )
            {
                flag=1;break;
            }
        if(flag) {cout<<-1<<endl;continue;}

//        for(int i=0;i<(int)s1.size();i++)
//        {
//            if(s1[i])
//        }
        int ans=rec(0,0);
//        for()
        cout<<ans<<endl;
    }
    return 0;
}

