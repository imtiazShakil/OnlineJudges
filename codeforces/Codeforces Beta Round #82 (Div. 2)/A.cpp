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

map<char,int>M;

bool trump(char a, char b,char t)
{
    if(a==t && b!=t) return true;
    return false;
}
bool card(char a, char b)
{
    int n1=M[a],n2=M[b];

    if(n1>n2) return true;
    else return false;
}

int main(void)
{
    M['6']=1;
    M['7']=2;
    M['8']=3;
    M['9']=4;
    M['T']=5;
    M['J']=6;
    M['Q']=7;
    M['K']=8;
    M['A']=9;

    string tr,fst,scnd;
    cin>>tr;
    cin>>fst>>scnd;
    if(trump(fst[1],scnd[1],tr[0]) ) {puts("YES");return 0;}
    if( fst[1]==scnd[1] )
    {
        if(card(fst[0],scnd[0]) ) {puts("YES");return 0;}
    }
    puts("NO");
    return 0;
}

