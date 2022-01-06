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
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define MAX 60

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

int main(void)
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w+",stdout);

    string str;
    bool flag=0,flag2;
    int cas;
    scanf("%d ",&cas);

    while(cas--)
    {
        flag2=0;
        while(getline(cin,str))
        //while(cin>>str)
        {
            if(SZ(str)==0) break;
            for(int i=0;i<SZ(str);i++)
            {
                switch(str[i])
                {
                    case '1':str[i]='I';break;
                    case '2':str[i]='Z';break;
                    case '3':str[i]='E';break;
                    case '4':str[i]='A';break;
                    case '5':str[i]='S';break;
                    case '6':str[i]='G';break;
                    case '7':str[i]='T';break;
                    case '8':str[i]='B';break;
                    case '9':str[i]='P';break;
                    case '0':str[i]='O';break;
                }
            }
            if(flag==1 && flag2==0) puts("");
            flag2=1;
            cout<<str<<endl;
        }
        flag=1;
    }
    return 0;
}

