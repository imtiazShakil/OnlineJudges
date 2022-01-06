#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

#define oo (1<<25)


#define mem(a,b) mem(a,b,sizeof a)
#define pb push_back
#define mp make_pair

using namespace std;
int j_len,b_len;
bool lucky[5000];
int how_many[5000];

//int dp[5000][5000][3][2];
int gen()
{
    int i,j,num,count=0;
    bool flag;
    for(i=0;i<5000;i++)
    {
        num=i;
        flag=0;
        while(num)
        {
            if(num%10 !=4 && num%10!=7 ) {flag=1;break;}
            num/=10;}
        if(flag==0) {lucky[i]=1;count++;}
        how_many[i]=count;
//        cout<<how_many[i]<<endl;
    }
}
int rec(int i,int j,int depth,bool player)
{
//    cout<<i<<" "<<j<<" "<<depth<<" "<<player<<endl;
    if(depth==2)
    {
        int num,count=0;
        bool flag=0;
        for(int st=i;st<=j;st++)
        {
            num=st;
            flag=0;
            while(num)
            {
                if(num%10 !=4 && num%10!=7 ) {flag=1;break;}
                num/=10;
            }
            if(flag==0) count++;
        }
        return count;
    }

//    int &ret=dp[i][j][depth][player];
//    if(ret!=-1) return ret;
    int ret;
    if(player==0) ret=0;
    else ret=oo;
    int mx=-1,lft,right;
    vector< pair<int,int> >v;
    if(player==0)
    {
        for(int q=i;q<=j;q++)
        {
            if(q+j_len-1 <=j )
            {
                if(mx<how_many[q+j_len-1]-how_many[q] )
                {
                    mx=how_many[q+j_len-1]-how_many[q];
                    lft=q;
                    right=q+j_len-1;
                }

            }
        }
        for(int q=i;q<=j;q++)
        {
            if(q+j_len-1 <=j )
            {
                if(mx==how_many[q+j_len-1]-how_many[q] )
                {
//                    mx=how_many[q+j_len-1]-how_many[q];
                    lft=q;
                    right=q+j_len-1;
                    v.pb(mp(lft,right));
                }

            }
        }
        for(int q=0;q<(int)v.size();q++)
        {
            ret=max(ret,rec(v[q].first,v[q].second,depth+1,!player) );
        }
    }


    if(player==1)
    {
        for(int q=i;q<=j;q++)
        {
            if(q+b_len-1 <=j )
            {
                ret=min(ret,rec(q,q+b_len-1,depth+1,!player) );
            }
        }
    }

    return ret;

}
class TheLuckyGameDivTwo
{
public:
	int find(int a, int b, int jLen, int bLen)
	{
//	    memset(dp,-1,sizeof dp);
        gen();
	    j_len=jLen;b_len=bLen;
        int ans=rec(a,b,0,0);
        return ans;
	}
};


template<typename T> void print( T a ) {
    cerr << a;
}

void print( long long a ) {
    cerr << a << "L";
}

void print( string a ) {
    cerr << '"' << a << '"';
}

template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}

template<typename T> void assert_eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

template<typename T> void assert_eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
void assert_eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

int main( int argc, char* argv[] )
{

	TheLuckyGameDivTwo objectTheLuckyGameDivTwo;

	//test case0
	int param00 = 44;
	int param01 = 45;
	int param02 = 1;
	int param03 = 1;
	int ret0 = objectTheLuckyGameDivTwo.find(param00,param01,param02,param03);
	int need0 = 1;
	assert_eq(0,ret0,need0);

//	test case1
	int param10 = 1;
	int param11 = 100;
	int param12 = 100;
	int param13 = 100;
	int ret1 = objectTheLuckyGameDivTwo.find(param10,param11,param12,param13);
	int need1 = 6;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 4;
	int param21 = 8;
	int param22 = 3;
	int param23 = 2;
	int ret2 = objectTheLuckyGameDivTwo.find(param20,param21,param22,param23);
	int need2 = 1;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 1;
	int param31 = 100;
	int param32 = 75;
	int param33 = 50;
	int ret3 = objectTheLuckyGameDivTwo.find(param30,param31,param32,param33);
	int need3 = 2;
	assert_eq(3,ret3,need3);

}

