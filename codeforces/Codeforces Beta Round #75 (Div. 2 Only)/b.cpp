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

using namespace std;

string str;



string sum_up(string rev)
{

    bool flag=0;
    for(int i=(int)rev.size()-1;i>=0;i-- )
    {
        if(rev[i]-'0'==1)
        {
            rev[i]='0';
        }
        else {rev[i]='1';flag=1;break;}
    }
    if(!flag)
    {
        rev[0]='1';
        rev+="0";
    }


    return rev;
}

int main(void)
{

    ll steps,p,count;
    string nn;
    while(cin>>str)
    {
        steps=0;

        nn.clear();p=0;
        for(int i=0;i<(int)str.size();i++)
        {
            if(str[i]=='0')
            {
                p++;
            }
            else break;
        }
        for(int i=p;i<(int)str.size();i++)
        {
            nn+=str[i];
        }

        str=nn;
//        cout<<str<<endl;
        while(str!="1")
        {
            if(str[(int)str.size()-1]=='1' ) {str=sum_up(str);steps++;}
            else
            {
//                count=0;
                for(int i=(int)str.size()-1;i>=0;i-- )
                {
                    if(str[i]=='0')
                    {
                        steps++;
                        str.erase((int)str.size()-1,1);
                    }
                    else break;
                }
            }
//            cout<<str<<endl;
        }
        cout<<steps<<endl;
    }
    return 0;
}

