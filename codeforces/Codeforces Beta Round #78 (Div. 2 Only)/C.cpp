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
map<string,int>M;
vector<string>v;

void rec(string str)
{
    if(M[str]) return ;
    string tmp(6,0);



    return ;
}
int main(void)
{
    int c=0;
    string str,tmp(6,0);
    cin>>str;
    sort(all(str));
    do
    {
//        print2(str,c);c++;
        v.pb(str);

    }while(next_permutation(&str[0],&str[0]+SZ(str)));

    c=0;
    for(int i=0;i<SZ(v);i++)
    {
        if(M.find(v[i])==M.end())
        {
//            rec(v[i]);
            M[v[i]]=1;

            str=v[i];
            ///head fixed 34/23 fixed
            tmp[2]=str[2];
            tmp[3]=str[3];

            tmp[0]=str[4];
            tmp[1]=str[5];
            tmp[4]=str[1];
            tmp[5]=str[0];
            M[tmp]=1;
//            print1(tmp);

            tmp[0]=str[5];
            tmp[1]=str[4];
            tmp[4]=str[0];
            tmp[5]=str[1];
            M[tmp]=1;
//            print1(tmp);

            tmp[1]=str[0];
            tmp[0]=str[1];
            tmp[4]=str[5];
            tmp[5]=str[4];
            M[tmp]=1;
//            print1(tmp);


            ///01 fixed
            tmp[0]=str[0];tmp[1]=str[1];

            tmp[3]=str[2];
            tmp[2]=str[3];
            tmp[4]=str[5];
            tmp[5]=str[4];
            M[tmp]=1;//rec(tmp);



            tmp[2]=str[5];
            tmp[3]=str[4];
            tmp[4]=str[2];
            tmp[5]=str[3];
            M[tmp]=1;//rec(tmp);


            tmp[2]=str[4];
            tmp[3]=str[5];
            tmp[4]=str[3];
            tmp[5]=str[2];
            M[tmp]=1;//rec(tmp);

            ///45 fixed
            tmp[4]=str[4];
            tmp[5]=str[5];

            tmp[0]=str[1];
            tmp[1]=str[0];
            tmp[2]=str[3];
            tmp[3]=str[2];
            M[tmp]=1;//rec(tmp);

            tmp[0]=str[2];
            tmp[1]=str[3];
            tmp[2]=str[1];
            tmp[3]=str[0];
            M[tmp]=1;//rec(tmp);

            tmp[0]=str[3];
            tmp[1]=str[2];
            tmp[2]=str[0];
            tmp[3]=str[1];
            M[tmp]=1;//rec(tmp);
            c++;

        }
//        break;
    }

//    for(int i=0;i<SZ(v);i++)
//    {
//        if(M.find(v[i])==M.end()) c++;
//    }
    if(c==0) c++;
    print1(c);
    return 0;
}

