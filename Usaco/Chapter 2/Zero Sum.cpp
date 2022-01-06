/*
ID: shakil1
PROG: zerosum
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

char str[30];
//string str;
vector<string>v;
int n;

bool ok(void)
{
//    char st_op[30];
    int num[10],len=0,len2=0;
    char oprnd[10];

    for(int i=0;i<n*2-1; )
    {
        if( i+1>=n*2-1 ) {num[len++]=str[i]-'0';i+=2;}
        else if( str[i+1]=='+'|| str[i+1]=='-'  ) {num[len++]=str[i]-'0';i+=2;}
        else
        {
            int p=str[i]-'0';i+=2;
            while(str[i+1]==' ' && i+1<n*2-1 )
            {
                p=p*10 + str[i]-'0';
                i+=2;
            }
            p=p*10+str[i]-'0';
            num[len++]=p;
            i+=2;
        }
    }

//    for(int i=0;i<len;i++) printf("%d ",num[i]);
//    puts("");

    for(int i=1;i<n*2-1;i+=2)
    {
        if(str[i]!=' ') oprnd[len2++]=str[i];
    }

    int ans=num[0];
    for(int i=0;i<len2;i++)
    {
        if(oprnd[i]=='+') ans+=num[i+1];
        if(oprnd[i]=='-') ans-=num[i+1];
    }
//    print2("ans ",ans);

    if(ans) return false;
    else return true;

//    char st_op;
//    int st_num[10],top=0;
//
////    mem(st_op,0);
//    mem(st_num,0);
//
//    for(int i=0;i<n*2-1;i++)
//    {
//        if( isdigit(str[i]) )
//        {
//            if(top==0) st_num[top++]=str[i]-'0';
//            else
//            {
//                if(st_op=='+') st_num[0]+=(str[i]-'0');
//                if(st_op=='-') st_num[0]-=(str[i]-'0');
//                if(st_op==' ') st_num[0]=st_num[0]*10 + (str[i]-'0');
//            }
//        }
//        else st_op=str[i];
//    }
//
//    if(st_num[0]==0) return true;
//    else return false;

//    return true;
}

void rec(int depth)
{
    if(depth==n*2-1)
    {
         if(ok())  v.pb(str);//print1(str);
        return ;
    }

    if(depth%2==0)
    {
        str[depth]=depth/2 + 1 +'0';
        rec(depth+1);
    }
    else
    {
        str[depth]='+';
        rec(depth+1);

        str[depth]='-';
        rec(depth+1);

        str[depth]=' ';
        rec(depth+1);
    }
    return ;
}

int main(void)
{
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w+",stdout);

    scanf("%d",&n);
//    str="";
//    str="1-2 3-4 5 6 7";
//    if(ok() ) puts("do it");
    rec(0);
    sort(all(v));
    for(int i=0;i<SZ(v);i++) print1(v[i]);

    return 0;
}
