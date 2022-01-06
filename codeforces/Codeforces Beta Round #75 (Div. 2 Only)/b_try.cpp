#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main(void)
{
    string a;
    cin>>a;
    int step=0,p,q,i,j,k;
    bool flag;
    while(a!="1")
    {
        if(a[(int)a.size()-1]=='1' )
        {
            flag=0;
            for(i=(int)a.size()-1;i>=0;i--)
            {
                if(a[i]=='1') a[i]='0';
                else if(a[i]=='0') {a[i]='1';flag=1;break;}
            }
            if(flag==0) {a="1"+a;}
            step++;
        }
        else
        {
            for( i=(int)a.size()-1,p=0;i>=0;i--)
            {
                if( a[i]=='0' ) p++;
                else break;
            }
            step+=p;
            a.erase(i+1,p);
//            a.erase((int)a.size()-1,1);
        }

    }
    cout<<step<<endl;
}
