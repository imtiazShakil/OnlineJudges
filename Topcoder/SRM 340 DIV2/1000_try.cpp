
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
#define MAX 55
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;

int dp[MAX][MAX][MAX];
int best[MAX][MAX][MAX];
vector <int> theory; vector <int> practical; vector <int> expire;
int skillBound;

int rec(int th,int prc,int mon)
{
    if(th>=skillBound && prc>=skillBound) return 0;
    if(mon>=(int)theory.size()) return oo;

    int &ret=dp[th][prc][mon];
    if(ret!=-1) return ret;

    ret=oo;
    int cur;
    for(int i=0;i<(int)theory.size();i++)
    {
        if(th>=theory[i]-1 && prc>=practical[i]-1 && mon<expire[i] )
        {
            cur=rec(max(th,theory[i]),max(prc,practical[i]),mon+1) + 1;
            if(cur<ret)
            {
                ret=cur;
                best[th][prc][mon]=i;
            }
        }
    }
    return ret;
}
class CsCourses
{
public:
	vector <int> getOrder(vector <int> theoreticalValue, vector <int> practicalValue, vector <int> expir, int skillBoun)
	{
	    theory=theoreticalValue;
	    practical=practicalValue;
	    expire=expir;
        skillBound=skillBoun;
        mem(dp,-1);mem(best,0);

        vector<int>seq;
        int ans=rec(0,0,0);
        if(ans>=oo) return seq;

        int th=0,prc=0,mon=0;
        while(th<skillBoun || prc <skillBoun)
        {
            int course=best[th][prc][mon];
            seq.push_back(course);
            th=max(th, theoreticalValue[course]);prc=max(prc , practicalValue[course] ) ; mon++;
        }
        return seq;
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

	CsCourses objectCsCourses;

	//test case0
	vector <int> param00;
	param00.push_back(1);
	vector <int> param01;
	param01.push_back(1);
	vector <int> param02;
	param02.push_back(1);
	int param03 = 1;
	vector <int> ret0 = objectCsCourses.getOrder(param00,param01,param02,param03);
	vector <int> need0;
	need0.push_back(0);
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(1);
	param10.push_back(2);
	param10.push_back(1);
	vector <int> param11;
	param11.push_back(2);
	param11.push_back(1);
	param11.push_back(1);
	vector <int> param12;
	param12.push_back(5);
	param12.push_back(5);
	param12.push_back(5);
	int param13 = 2;
	vector <int> ret1 = objectCsCourses.getOrder(param10,param11,param12,param13);
	vector <int> need1;
	need1.push_back(2);
	need1.push_back(0);
	need1.push_back(1);
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(1);
	param20.push_back(2);
	param20.push_back(1);
	vector <int> param21;
	param21.push_back(2);
	param21.push_back(1);
	param21.push_back(1);
	vector <int> param22;
	param22.push_back(1);
	param22.push_back(1);
	param22.push_back(1);
	int param23 = 2;
	vector <int> ret2 = objectCsCourses.getOrder(param20,param21,param22,param23);
	vector <int> need2;
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(1);
	param30.push_back(2);
	param30.push_back(1);
	vector <int> param31;
	param31.push_back(2);
	param31.push_back(1);
	param31.push_back(1);
	vector <int> param32;
	param32.push_back(3);
	param32.push_back(2);
	param32.push_back(1);
	int param33 = 2;
	vector <int> ret3 = objectCsCourses.getOrder(param30,param31,param32,param33);
	vector <int> need3;
	need3.push_back(2);
	need3.push_back(1);
	need3.push_back(0);
	assert_eq(3,ret3,need3);

	//test case4
	vector <int> param40;
	param40.push_back(1);
	param40.push_back(2);
	param40.push_back(3);
	param40.push_back(4);
	param40.push_back(5);
	param40.push_back(6);
	param40.push_back(7);
	vector <int> param41;
	param41.push_back(1);
	param41.push_back(2);
	param41.push_back(3);
	param41.push_back(4);
	param41.push_back(5);
	param41.push_back(6);
	param41.push_back(7);
	vector <int> param42;
	param42.push_back(1);
	param42.push_back(2);
	param42.push_back(3);
	param42.push_back(4);
	param42.push_back(5);
	param42.push_back(6);
	param42.push_back(7);
	int param43 = 7;
	vector <int> ret4 = objectCsCourses.getOrder(param40,param41,param42,param43);
	vector <int> need4;
	need4.push_back(0);
	need4.push_back(1);
	need4.push_back(2);
	need4.push_back(3);
	need4.push_back(4);
	need4.push_back(5);
	need4.push_back(6);
	assert_eq(4,ret4,need4);

	//test case5
	vector <int> param50;
	param50.push_back(0);
	param50.push_back(1);
	param50.push_back(2);
	param50.push_back(2);
	param50.push_back(1);
	vector <int> param51;
	param51.push_back(0);
	param51.push_back(0);
	param51.push_back(1);
	param51.push_back(2);
	param51.push_back(1);
	vector <int> param52;
	param52.push_back(9);
	param52.push_back(9);
	param52.push_back(9);
	param52.push_back(9);
	param52.push_back(9);
	int param53 = 2;
	vector <int> ret5 = objectCsCourses.getOrder(param50,param51,param52,param53);
	vector <int> need5;
	need5.push_back(4);
	need5.push_back(3);
	assert_eq(5,ret5,need5);

}
