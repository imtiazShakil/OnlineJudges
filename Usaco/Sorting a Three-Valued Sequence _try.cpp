/*
ID: shakil1
PROG: sort3
LANG: C++
*/
//#include <map>
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
#define MAX 2005
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)
#define rep(x,n)        for(x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define fs      first
#define sc      second
#define pair pai
///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
int swp=0;
bool done[MAX];
int arr[MAX];
int org_arr[MAX];


int main(void)
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w+",stdout);

    int n,a,b;


    scanf("%d",&n);
    for(int i=0;i<n;i++) {scanf("%d",&arr[i]);org_arr[i]=arr[i];}
    sort(arr,arr+n);
//    puts("got ");
    for(int i=0;i<n;i++)
    {
        if(arr[i]==org_arr[i]) {done[i]=1;continue;}
    }


    for(int i=0;i<n;i++)
    {
//        print3("i-> ",i,done[i]);
        if(done[i]==0)
        {
            swp++;
            a=org_arr[i];b=arr[i];
            done[i]=1;
            bool flag=0;
            for(int j=i+1;j<n;j++)
            {
                if(done[j]==0 && org_arr[j]==b && arr[j]==a)
                {
//                    swp++;
                    done[j]=1;
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(done[j]==0 && org_arr[j]==b )
                    {
                        org_arr[j]=a;break;
                    }
                }
            }
        }

    }

//    for(int i=0;i<n;i++) printf(" %d",arr[i]);puts("");
    print1(swp);
    return 0;
}


