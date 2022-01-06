/*
ID: shakil1
PROG: calfflac
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

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
int pos[2000000];
int main(void)
{
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w+",stdout);

    int mx_len=0,low,high;
    string org,str,trim;org.clear();
    while(getline(cin,str))
    {
        org+=(str+'\n');
    }
    org.erase(SZ(org)-1);
//    print1(org);
    for(int i=0;i<SZ(org);i++)
    {
        if(isalpha(org[i])) {trim+=tolower(org[i]);pos[SZ(trim)-1]=i;}
    }
//    print1(trim);
//    for(int i=0;i<SZ(trim);i++) print1(pos[i]);

    for(int i=0;i<SZ(trim);i++)
    {
        int sum=1,r,l;bool flag=0;
        for(int k=1;sum<2000;k++)
        {
            if(i+k>SZ(trim) || i-k<0 ) break;
            if(trim[i+k]==trim[i-k]) {sum+=2;l=pos[i-k];r=pos[i+k];flag=1;}
            else break;
        }
        if(mx_len<sum && flag)
        {
            low=l;high=r;mx_len=sum;
        }
        sum=0;
        for(int k=1;sum<2000;k++)
        {
            if(i+k>SZ(trim) || i-k+1<0 ) break;
            if(trim[i-k+1]==trim[i+k]) {sum+=2;l=pos[i-k+1];r=pos[i+k];}
            else break;
        }
        if(mx_len<sum)
        {
            low=l;high=r;mx_len=sum;
        }
//        print2(i,mx_len);
    }
    print1(mx_len);
    for(int i=low;i<=high;i++) printf("%c",org[i]);
    puts("");
    return 0;
}

