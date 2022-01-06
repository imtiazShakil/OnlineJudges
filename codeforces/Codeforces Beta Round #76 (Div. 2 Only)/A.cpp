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
    map<string,int>M;
    string str,s1,s2,s3,s4,s5,s6,s7,s8,s9,s0;
    cin>>str;
    string tmp;
//    string ans;ans.clear();
    cin>>s0;cin>>s1;cin>>s2;cin>>s3;cin>>s4;cin>>s5;cin>>s6;cin>>s7;cin>>s8;cin>>s9;
    M[s0]=0;M[s1]=1;M[s2]=2;M[s3]=3;M[s4]=4;M[s5]=5;M[s6]=6;M[s7]=7;M[s8]=8;M[s9]=9;
    for(int i=0;i<10;i++)
    {
        tmp+=str[i];
    }
    cout<<M[tmp];
    tmp.clear();

    for(int i=10;i<20;i++)
    {
        tmp+=str[i];
    }
    cout<<M[tmp];
    tmp.clear();

    for(int i=20;i<30;i++)
    {
        tmp+=str[i];
    }
    cout<<M[tmp];
    tmp.clear();

    for(int i=30;i<40;i++)
    {
        tmp+=str[i];
    }
    cout<<M[tmp];
    tmp.clear();

    for(int i=40;i<50;i++)
    {
        tmp+=str[i];
    }
    cout<<M[tmp];
    tmp.clear();

    for(int i=50;i<60;i++)
    {
        tmp+=str[i];
    }
    cout<<M[tmp];
    tmp.clear();

    for(int i=60;i<70;i++)
    {
        tmp+=str[i];
    }
    cout<<M[tmp];
    tmp.clear();

    for(int i=70;i<80;i++)
    {
        tmp+=str[i];
    }
    cout<<M[tmp];
    tmp.clear();
    puts("");


    return 0;
}

