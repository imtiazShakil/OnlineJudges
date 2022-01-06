/*
ID: shakil1
PROG: namenum
LANG: C++
*/

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
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<"c"<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define MAX 100
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
int num[20],n,c=0;
string ss[12];
char sol[MAX];
map<string,bool>M;
char ans[4700][MAX];

void bt(int depth)
{
    if(depth==n)
    {
        if(M.find(sol)!=M.end()) strcpy(ans[c++],sol);
        return ;
    }
    for(int i=0;i<3;i++)
    {
        sol[depth]=ss[num[depth]][i];
        bt(depth+1);
    }
    return ;
}
int main(void)
{
    ss[2]="ABC";ss[3]="DEF";ss[4]="GHI";ss[5]="JKL";ss[6]="MNO";ss[7]="PRS";ss[8]="TUV";ss[9]="WXY";
    FILE *fp=fopen("dict.txt","r");

    char str[200],tmp[200];
    int cnt=0;
    while(cnt<4617)
    {
        fscanf(fp,"%s",str);
        M[str]=1;
        cnt++;
    }
//    for(map<string,bool>::iterator it=M.begin();it!=M.end();it++) print1(it->first);
    fclose(fp);
    fp=fopen("namenum.in","r");
    fscanf(fp,"%s",tmp);
    int len=strlen(tmp);mem(num,0);n=len;
    for(int i=0;i<len;i++)
        num[i]=tmp[i]-'0';
    mem(sol,0);
    bt(0);
    fclose(fp);fp=fopen("namenum.out","w+");
//    print1(ans);
    if(c==0) {fprintf(fp,"NONE\n");fclose(fp); return 0;}
    for(int i=0;i<c;i++)
    {
        fprintf(fp,"%s\n",ans[i]);
    }
    fclose(fp);

    return 0;
}

