/*
ID: shakil1
PROG: beads
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
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

int main(void)
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w+",stdout);
    int mx,end,ln;bool flag;int c1,c2;
    string str;
    char ch;
    while(cin>>ln>>str)
    {
        mx=0;
        for(int i=0;i<SZ(str);i++)
        {
            ch=str[i];
            c1=0;
            for(int j=i;j<i+SZ(str);j++)
            {
                if(str[j%SZ(str)]==ch || str[j%SZ(str)]=='w') {c1++;end=j;}
                else if(ch=='w' && str[j%SZ(str)]!='w') {ch=str[j%SZ(str)];c1++;end=j;}
                else break;
            }
            c2=0;end%=SZ(str);
            ch=str[(i-1+SZ(str))%SZ(str)];
            for(int j=i-1+SZ(str),p=0;p<SZ(str) && j%SZ(str)!=end ; j--,p++)
            {
                if(str[j%SZ(str)]==ch || str[j%SZ(str)]=='w') c2++;
                else if(ch=='w' && str[j%SZ(str)]!='w') {ch=str[j%SZ(str)];c2++;}
                else break;
            }
            mx=max(mx,c1+c2);

        }
        print1(mx);
    }
    return 0;
}

