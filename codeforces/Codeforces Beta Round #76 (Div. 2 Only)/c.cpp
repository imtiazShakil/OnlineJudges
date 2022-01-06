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
    int n,m,a,b;
    int count=0;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    bool flag=0;
    for(int i=1;i<=n;i+=m)
    {
        if( i>=min(a,b) && min(i+m-1,n) <=max(a,b) )
        {
            puts("1");
            if(flag==0) {flag=1;count++;}
        }
        else if(i>=a &&i<=b && min(i+m-1,n)>=a && min(i+m-1,n)>=b ) count++;
        else if(i<=a &&i<=b && min(i+m-1,n)<=b && min(i+m-1,n)>=a ) count ++;

    }
    print1(count);
    return 0;
}


