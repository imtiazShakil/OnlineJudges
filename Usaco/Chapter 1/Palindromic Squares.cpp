/*
ID: shakil1
PROG: palsquare
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
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<"c"<<endl
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

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
bool is_pal(string str)
{
    for(int i=0,j=SZ(str)-1;i<SZ(str)/2;i++,j--)
        if(str[i]!=str[j]) return false;
    return true;

}
string give_dec(int dec,int base)
{
    string ans;
    int num;
    while(dec)
    {
        if(dec%base>9) ans+=(dec%base)+'A'-10;
        else ans+=(dec%base)+'0';
        dec/=base;
    }
    reverse(all(ans));
//    print1(ans);
    return ans;
}

int main(void)
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w+",stdout);

    int b;
    scanf("%d",&b);
    string tmp,tmp2;
    for(int i=1;i<=300;i++)
    {
        tmp=give_dec(i*i,b);
        if(is_pal(tmp))
        {
            tmp2=give_dec(i,b);
            print2(tmp2,tmp);
        }
    }
    return 0;
}

