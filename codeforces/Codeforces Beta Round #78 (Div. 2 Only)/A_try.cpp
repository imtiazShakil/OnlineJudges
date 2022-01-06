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

int main(void)
{
    string str,org;
    bool add,vasilsa;
    while(cin>>str)
    {
        add=0,vasilsa=0;
        org.clear();
        for(int i=0;i<SZ(str);i++)
        {
            if(str[i]=='.')
            {
                if(str[i+1]>='5') add=1;
                if(str[i-1]=='9') vasilsa=1;
                break;
            }
            org+=str[i];
        }

        if(!add && !vasilsa) print1(org);
        else if(vasilsa) puts("GOTO Vasilisa.");
        else
        {
//            if(org[SZ(org)-1]=='9')
//            else
            {
                org[SZ(org)-1]++;
                print1(org);
            }
        }

    }
    return 0;
}

