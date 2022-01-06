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
#include <stdio.h>

#define mem(a,b) memset(a,b,sizeof a)
#define oo (1<<30)

using namespace std;

int dp[55][55][200];
int upr;

int rec(int my,int barhp,int enm)
{
    if(enm-my>my) return oo;
    if(barhp<=0 && enm<=0 && my>0) return 0;
    if(my<=0 && (barhp>0 || enm>0 ) ) return oo;

    int &ret=dp[my][barhp][enm];
    if(ret!=-1) return ret;
    ret=oo;
    int ms,barracks,enms;

    for(int i=my,j=0;i>=0 && j<=enm ;i--,j++)
    {
        barracks=max(0,barhp-i);
        if(barracks>0)
        {
            ret=min(ret,rec(my-(enm-j),barracks,enm-j +upr ) +1);
        }
        else
        {
            ret=min(ret,rec(my-(enm-j),barracks,enm-j) +1);
        }
    }
    return ret;
}
class BarracksEasy
{
public:
	int attack(int myUnits, int barHp, int unitsPerRound)
	{
        mem(dp,-1);
        upr=unitsPerRound;
        int ans=rec(myUnits,barHp,0);
        if(ans>=oo) return -1;
        else return ans;
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

	BarracksEasy objectBarracksEasy;

	//test case0
	int param00 = 10;
	int param01 = 11;
	int param02 = 15;
	int ret0 = objectBarracksEasy.attack(param00,param01,param02);
	int need0 = 4;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 3;
	int param11 = 10;
	int param12 = 4;
	int ret1 = objectBarracksEasy.attack(param10,param11,param12);
	int need1 = -1;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 2;
	int param21 = 10;
	int param22 = 1;
	int ret2 = objectBarracksEasy.attack(param20,param21,param22);
	int need2 = 9;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 11;
	int param31 = 12;
	int param32 = 9;
	int ret3 = objectBarracksEasy.attack(param30,param31,param32);
	int need3 = 2;
	assert_eq(3,ret3,need3);

	int param40 = 22;
	int param41 = 48;
	int param42 = 21;
	int ret4 = objectBarracksEasy.attack(param40,param41,param42);
	int need4 = 16;
	assert_eq(4,ret4,need4);


}

