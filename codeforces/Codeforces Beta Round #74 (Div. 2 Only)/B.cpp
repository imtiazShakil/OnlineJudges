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

#define MAX 150
using namespace std;

bool mat[MAX][MAX];
int n,m;
vector<string>v;

bool valid(int row,int col)
{
    for(int i=row,j=col-1;j>=0;j--)
    {
        if(v[row][col]==v[i][j] ) return true;
    }

    for(int i=row,j=col+1;j<m;j++)
    {
        if(v[row][col]==v[i][j] ) return true;
    }

    for(int i=row-1,j=col;i>=0;i--)
    {
        if(v[row][col]==v[i][j] ) return true;
    }

    for(int i=row+1,j=col;i<n;i++)
    {
        if(v[row][col]==v[i][j] ) return true;
    }

    return false;

}
int main(void)
{
//    int n,m;
    string str;

    while(scanf("%d %d",&n,&m)==2)
    {
        v.clear();mem(mat,0);
        for(int i=0;i<n;i++)
        {
            cin>>str;
            v.pb(str);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if( valid(i,j) ) mat[i][j]=1;
            }

//        for(int i=0;i<n;i++,puts(""))
//            for(int j=0;j<m;j++)
//                cout<<mat[i][j];

        str.clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0 )
                {
                    str+=v[i][j];
                }
            }

            cout<<str<<endl;
    }
    return 0;
}

