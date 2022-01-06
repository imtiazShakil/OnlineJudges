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
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second
#define sqr(x) ( (x)*(x) )
#define y1 y_1

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

double A1,A2,B1,B2,C1,C2,xs,ys,xe,ye,x1,y1,x2,y2,f,t,det;
double p,q;

void sol(void)
{
    A1=y2-y1;
    B1=x1-x2;
    C1=A1*x1 + B1*y1;

    t=2*C1 - 2*A1*xs + ( sqr(A1)/B1 )*ys - B1*ys;
    t/= ( sqr(A1)/B1 + B1 );

    f=(A1/B1)*( t - ys ) + xs;

    A2=t-ye;
    B2=xe-f;
    C2=A2*xe + B2*ye;

    det=A1*B2 - A2*B1;

    p = (B2*C1 - B1*C2)/det;
    q = (A1*C2 - A2*C1)/det;

    return ;

}


int main(void)
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&xs,&ys,&xe,&ye);
//        p=0.0;
//        q=0.0;

        sol();

        p+=1e-9;
        q+=1e-9;

//        if(fabs(p-0.0 )<0.0000 ) p=0.0;
//        if( fabs(q-0.0)> ) {q=0.0;puts("tt");}

        printf("%.3lf %.3lf\n",p,q);
//        print2(p,q);
    }

    return 0;
}

