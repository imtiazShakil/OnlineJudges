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

string org;
vector<bool>cas;
char luck;
vector<string>v;
bool probs[100000000];

int main(void)
{
    string tmp;
    int n,dig;
    bool flag;
    mem(probs,0);

    scanf("%d",&n);
    for(int i=0;i<n;i++) {cin>>tmp;v.pb(tmp);}
    cin>>org;
    cin>>luck;

    for(int i=0;i<SZ(org);i++)
    {
        if(islower(org[i])) cas.pb(0);
        else cas.pb(1);
    }

    for(int i=0;i<SZ(v);i++)
    {
        dig=SZ(v[i])-1;
        for(int j=0;j+dig<SZ(org);j++)
        {
            flag=1;
            for(int k=0;k<=dig;k++)
            {
                if(tolower(org[j+k])!=tolower(v[i][k])) flag=0;
            }
            if(flag)
            {
                for(int k=0;k<=dig;k++) probs[j+k]=1;
            }
        }
    }

    bool array[300];
    mem(array,0);
    array[tolower(luck)]=1;
    array[toupper(luck)]=1;

    for(int i=0;i<SZ(org);i++)
    {
        if(probs[i])
        {
            if(tolower(org[i])==tolower(luck))
            {
                for(int p='a';p<='z';p++)
                {
                    if(array[p]==0)
                    {
                        org[i]=p;
                        break;
                    }
                }
            }
            else org[i]=luck;
        }
    }
    for(int i=0;i<SZ(org);i++)
    {
        if(cas[i]) org[i]=toupper(org[i]);
        else org[i]=tolower(org[i]);
    }
    cout<<org<<endl;
//    puts("");
    return 0;
}

