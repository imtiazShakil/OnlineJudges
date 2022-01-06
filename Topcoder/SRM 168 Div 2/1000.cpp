#include <iostream>
#include <stdio.h>

#define oo (1<<30)

using namespace std;
int mx_width,height;
vector<int>tm;

int rec(int col,int worker)
{
    if(col==mx_width+1 && worker==(int)tm.size() ) return 0;
    if( col<mx_width+1  && worker>=(int)tm.size() ) return oo;
    if(worker<(int)tm.size() && col>=mx_width+1 ) return oo;

    int ret=oo,val=0;
    for(int i=col;i<=mx_width;i++)
    {
        val=max( rec(i+1,worker+1),(i-col+1)*height*tm[worker]);
        ret=min(ret,val);
    }
    return ret;
}
int main(void)
{

}
