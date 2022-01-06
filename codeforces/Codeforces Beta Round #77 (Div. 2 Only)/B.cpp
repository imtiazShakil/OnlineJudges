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

vector<ll>lucky;

void gen()
{
    lucky.clear();
    int arr1[]={4,7};
    int arr2[]={4,4,7,7};
    int arr3[]={4,4,4,7,7,7};
    int arr4[]={4,4,4,4,7,7,7,7};
    int arr5[]={4,4,4,4,4,7,7,7,7,7};

    ll val=0;
    for(int i=0;i<2;i++)
    {
        val=val*10 + arr1[i];
    }
    lucky.pb(val);
//    cout<<val<<endl;

    while(next_permutation(arr1,arr1+2))
    {
        val=0;
        for(int i=0;i<2;i++)
        {
            val=val*10 + arr1[i];
        }
        lucky.pb(val);
    }

    val=0;
    for(int i=0;i<4;i++)
    {
        val=val*10 + arr2[i];
    }
    lucky.pb(val);
//    cout<<val<<endl;
    while(next_permutation(arr2,arr2+4))
    {
        val=0;
        for(int i=0;i<4;i++)
        {
            val=val*10 + arr2[i];
        }
        lucky.pb(val);
    }

//    ll val=0;
    val=0;
    for(int i=0;i<6;i++)
    {
        val=val*10 + arr3[i];
    }
    lucky.pb(val);
//    cout<<val<<endl;
    while(next_permutation(arr3,arr3+6))
    {
        val=0;
        for(int i=0;i<6;i++)
        {
            val=val*10 + arr3[i];
        }
        lucky.pb(val);
    }


    val=0;
    for(int i=0;i<8;i++)
    {
        val=val*10 + arr4[i];
    }
    lucky.pb(val);
//    cout<<val<<endl;
    while(next_permutation(arr4,arr4+8))
    {
        ll val=0;
        for(int i=0;i<8;i++)
        {
            val=val*10 + arr4[i];
        }
        lucky.pb(val);
    }


    val=0;
    for(int i=0;i<10;i++)
    {
        val=val*10 + arr5[i];
    }
    lucky.pb(val);
//    cout<<val<<endl;
    while(next_permutation(arr5,arr5+10))
    {
        ll val=0;
        for(int i=0;i<10;i++)
        {
            val=val*10 + arr5[i];
        }
        lucky.pb(val);
    }





}

int bin_srch(ll item)
{
    int low=0;
    int high=SZ(lucky)-1;
    int mid=(low+high)/2;
    while(lucky[mid]!=item && high>low)
    {
        if(lucky[mid]>item) high=mid-1;
        if(lucky[mid]<item) low=mid+1;
        mid=(low+high)/2;
    }
    return mid;
}
int main(void)
{
    gen();
//    for(int i=0;i<SZ( lucky );i++) cout<<lucky[i]<<endl;

    ll itm,lowest;
    cin>>itm;
    int indx=bin_srch(itm);
//    cout<<"vvv "<<lucky[indx]<<endl;
    if(lucky[indx]==itm) {cout<<lucky[indx]<<endl;return 0;}
    else
    {
//        lowest=lucky[indx];
        for(int i=0;i<3;i++)
        {
            if(indx-i>=0)
            {
                if(lucky[indx-i]>=itm && lowest>lucky[indx-i] )
                    lowest=lucky[indx-i];
            }
        }

        for(int i=0;i<3;i++)
        {
            if(indx+i<SZ(lucky))
            {
                if(lucky[indx+i]>=itm && lucky[indx+i]<lowest )
                    lowest=lucky[indx+i];
            }
        }


    }
    cout<<lowest<<endl;
    return 0;
}

