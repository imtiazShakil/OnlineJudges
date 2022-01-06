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
#define MAX 1005
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
int pair[4][4];
vector<int>v[4];
vector<int>indx[4][4];

int main(void)
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w+",stdout);

    int n,a,b;


    scanf("%d",&n);
    for(int i=0;i<n;i++) {scanf("%d",&arr[i]);org_arr[i]=arr[i];}
    sort(arr,arr+n);

    for(int i=0;i<n;i++)
    {
        if(arr[i]==org_arr[i]) {done[i]=1;continue;}
        pair[org_arr[i]][arr[i]]++;
        indx[org_arr[i]][arr[i]].pb(i);
        v[org_arr[i]].pb(i);
    }

    for(int i=0;i<n;i++)
    {
//        print3("i-> ",i,done[i]);
        if(done[i]==0)
        {

            a=org_arr[i];b=arr[i];
            done[i]=1;
//            if(i==4) print3("sp ",a,b);
//            if(i==4) print2("pai ",pair[b][a]);

            if(pair[b][a]>0)
            {
                swp++;
                pair[b][a]--;
                for(int j=0;j<SZ(indx[b][a]);j++ )
                {
                    if( done[ indx[b][a][j] ] ==0)
                    {
                        org_arr[i]=b;
                        org_arr[indx[b][a][j]]=a;
                        done[indx[b][a][j]]=1;

                        break;
                    }
                }
            }
            else
            {

                swp++;
                for(int j=0;j<SZ(v[b]);j++ )
                {
                    if( done[v[b][j]]==0 && v[b][j]>=0 )
                    {
//                        print2("loc ",v[b][j]);
                        org_arr[i]=b;
                        org_arr[v[b][j]]=a;
                        pair[ a ][ arr[v[b][j]] ]++;
                        indx[a][arr[v[b][j]]].pb(v[b][j]);

                        v[a].pb(v[b][j]);
                        v[b][j]=-1;
                        break;
                    }
                }
            }
//            for(int i=0;i<n;i++) printf(" %d",org_arr[i]);puts("");
        }

    }

//    for(int i=0;i<n;i++) printf(" %d",arr[i]);puts("");
    print1(swp);
    return 0;
}

