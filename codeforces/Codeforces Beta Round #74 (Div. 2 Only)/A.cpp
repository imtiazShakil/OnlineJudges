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

using namespace std;


int main(void)
{
    int r,g,b,tm;
    while(scanf("%d %d %d",&r,&g,&b)==3)
    {
        tm=0;
        while( r>0 || g>0 || b>0)
        {
            if( tm%3 ==0)
            {
                if(r>1) r-=2;
                else r=0;
            }
            else if(tm%3 ==1 )
            {
                if(g>1) g-=2;
                else g=0;
            }
            else if(tm%3 ==2)
            {
                if(b>1) b-=2;
                else b=0;
            }
            tm++;
        }
        tm+=29;
        cout<<tm<<endl;
    }
    return 0;
}

