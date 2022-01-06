
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

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

string excel(string str)
{
    stringstream ss;ss.clear();
    ss<<str;
    int r,c;
    char ch,ch2;
    ss>>ch>>r>>ch2>>c;
//    print2(r,c);

    int div,mod,t1,t2;
    string col,row;
    while(c)
    {
        mod=c%26;
        if(mod==0) c-=26;
        else c-=mod;
        c/=26;
        if(mod==0) col+="Z";
        else col+=(mod + 'A'-1);
    }
    reverse(all(col));
//    print2("col ",col);
    ss.clear();
    ss<<r;
    ss>>row;
//    print2("row ",row);
    return col+row;
}

string excel2(string str)
{
    string col,row;
    int r=0,c;
    for(int i=0;i<SZ(str);i++)
    {
        if(isalpha(str[i]))
        {
            col+=str[i];
        }
        else
        {
            r=r*10+str[i]-'0';
        }
    }
    stringstream ss;ss.clear();
//    ss<<str;
//    ss>>col>>r;
//    ss.clear();
    ss<<r;
    string tmp;
    ss>>tmp;

//    print2(r,col);

    row+="R"+tmp;

    c=0;
    for(int i=0;i<SZ(col)-1;i++)
    {
        if(i==0) c=(col[i]-'A' + 1)*26+ (col[i+1]-'A'+1 );
        else c=c*26+ (col[i+1]-'A'+1 );
    }
    if(SZ(col)==1)
    {
        c=col[0]-'A'+1;
    }
//    print2("int c ",c);
    tmp.clear();ss.clear();
    ss<<c;
    ss>>tmp;
    return row+"C"+tmp;

}
int main(void)
{

//    printf("%d\n",'A');
//    printf("%d\n",'Z');
//    string s=excel2("BC26");
//    print2("ans ",s);

    int n;
    scanf("%d",&n);
    string ans,q;
    bool fl=0;
    for(int i=0;i<n;i++)
    {
        fl=0;
        cin>>q;
        if(q[0]=='R' )
        {
            bool n1=0,n2=0,c=0,r=0;
            for(int i=0;i<SZ(q);i++)
            {
                if(n1==0 && n2==0 && c==0 && q[0]=='R') r=1;
                if(r==1 && n1==0 && n2==0 && c==0 && isdigit(q[i]) ) n1=1;
                if(r==1 && n1==1 && n2==0 && c==0 && q[i]=='C' ) c=1;
                if(r==1 && n1==1 && n2==0 && c==1 && isdigit(q[i]) ) n2=1;
            }
            if(n1 && n2 && c && r) fl=1;
        }
        if(fl) ans=excel(q);
        else ans=excel2(q);

        print1(ans);
    }
    return 0;
}
