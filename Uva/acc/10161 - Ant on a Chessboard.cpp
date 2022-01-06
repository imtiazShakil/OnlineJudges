#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

#define ll long long
#define sqr(x) ((x)*(x))
using namespace std;

int main(void)
{
    ll itm,r,c,lev,sqr_lv;
    while(scanf("%lld",&itm)==1 && itm)
    {
        lev=sqrt(itm);
        if( sqr(lev) != itm) lev++;
        sqr_lv=sqr(lev);
//        cout<<lev <<" "<<sqr_lv<<endl;
        if(lev%2)
        {
            if( sqr_lv==itm ) {r=lev;c=1;cout<<c<<" "<<r<<endl;continue;}
            if( sqr_lv-lev<itm ) {r=lev;c=abs( sqr_lv -itm )+1 ; cout<<c<<" "<<r<<endl;continue; }
            else {r=abs( (sqr_lv-lev*2 +2 )-itm)+1;c=lev; cout<<c<<" "<<r<<endl;continue; }
        }
        else
        {
            if( sqr_lv==itm ) {r=1;c=lev;cout<<c<<" "<<r<<endl;continue;}
            if( sqr_lv-lev<itm ) {c=lev;r=abs( sqr_lv -itm )+1 ; cout<<c<<" "<<r<<endl;continue; }
            else {c=abs( (sqr_lv-lev*2 +2 )-itm)+1;r=lev; cout<<c<<" "<<r<<endl;continue; }
        }
    }
    return 0;
}
