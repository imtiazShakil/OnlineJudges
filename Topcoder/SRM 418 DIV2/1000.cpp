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

int dp[100][100];
int upr,my_unit;

int rec(int bar_hp,int my_sol,int enm_sol)
{
//    printf("bar %d mine %d enemy %d \n",bar_hp,my_sol,enm_sol);
    if(my_sol>my_unit) return oo;
    if( (bar_hp>0 || enm_sol>0) && my_sol<0  ) return oo;   //{puts("ret oo");return oo;}
    if(bar_hp<=0 && enm_sol<=0 && my_sol>=0 ) return 0; //{puts("ret 0");return 0;}

    int &ret=dp[bar_hp][my_sol];
    if(ret!=-1) return ret;

//    int enm;
    ret=oo;
    for(int i=my_sol,j=0;i>=0;i--,j++)
    {
        if(bar_hp-i>0)
        {
//            if(enm_sol>0 && j>enm_sol) enm=0;
//            if()
            /*if( enm_sol-j>=0 )*/ ret=min(ret,rec(bar_hp-i,my_sol-(enm_sol-j),enm_sol-j+upr) +1 );

//            if(enm_sol>0 && j>enm_sol ) ret=min(ret,rec(bar_hp-i,my_sol,upr) +1 );
//            else ret=min(ret,rec(bar_hp-i,my_sol,upr) +1 );
        }
        else
        {
            /*if( enm_sol-j>=0 )*/ ret=min(ret,rec(bar_hp-i,my_sol-(enm_sol-j),enm_sol-j) +1 );
//            if(enm_sol>0 && j>enm_sol ) ret=min(ret,rec(bar_hp-i,my_sol,0) +1 );
        }
    }
//    printf("ret %d\n",ret);
    return ret;
}
class BarracksEasy
{
public:
	int attack(int myUnits, int barHp, int unitsPerRound)
	{
	    my_unit=myUnits;
	    mem(dp,-1);
        upr=unitsPerRound;
        int ans=rec(barHp,myUnits,0);
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

////////////	//test case0
	int param00 = 10;
	int param01 = 11;
	int param02 = 15;
	int ret0 = objectBarracksEasy.attack(param00,param01,param02);
	int need0 = 4;
	assert_eq(0,ret0,need0);

//////	//test case1
	int param10 = 3;
	int param11 = 10;
	int param12 = 4;
	int ret1 = objectBarracksEasy.attack(param10,param11,param12);
	int need1 = -1;
	assert_eq(1,ret1,need1);
//
//////	//test case2
	int param20 = 2;
	int param21 = 10;
	int param22 = 1;
	int ret2 = objectBarracksEasy.attack(param20,param21,param22);
	int need2 = 9;
	assert_eq(2,ret2,need2);

//////	//test case3
	int param30 = 11;
	int param31 = 12;
	int param32 = 9;
	int ret3 = objectBarracksEasy.attack(param30,param31,param32);
	int need3 = 2;
	assert_eq(3,ret3,need3);

}

