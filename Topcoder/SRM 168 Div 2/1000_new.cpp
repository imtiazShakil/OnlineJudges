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

#define mem(a,b) memset(a,b,sizeof a)
#define oo (1<<30)

using namespace std;

int mx_width,height;
vector<int>tm_;
int dp[1009][60];


int rec(int col,int worker)
{
//    printf("col %d worker %d \n",col,worker);

    int &ret=dp[col][worker];

    if(col==mx_width+1 && worker<=(int)tm_.size() ) {return 0;}
    if( col<mx_width+1  && worker>=(int)tm_.size() ) {return oo;}
//    if(worker<(int)tm.size() && col>=mx_width+1 ) return oo;

    if(ret!=-1) return ret;
    ret=oo;
    int val=0;
    for(int i=col;i<=mx_width;i++)
    {
        val=max( rec(i+1,worker+1), (i-col+1)*height*tm_[worker]);
        ret=min(ret,val);
    }
    return ret;
}


class WindowWasher
{
public:
	int fastest(int width, int height_, vector <int> washTimes)
	{
	    mem(dp,-1);
	    tm_.clear();
        mx_width=width;height=height_;
        sort(washTimes.begin(),washTimes.end());
//        for(int i=0;i<(int)washTimes.size();i++) cout<<washTimes[i]<<endl;
        tm_=washTimes;

        int ans=rec(1,0);
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

	WindowWasher objectWindowWasher;

//	//test case0
	int param00 = 10;
	int param01 = 10;
	vector <int> param02;
	param02.push_back(60);
	int ret0 = objectWindowWasher.fastest(param00,param01,param02);
	int need0 = 6000;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 10;
	int param11 = 10;
	vector <int> param12;
	param12.push_back(60);
	param12.push_back(60);
	int ret1 = objectWindowWasher.fastest(param10,param11,param12);
	int need1 = 3000;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 10;
	int param21 = 10;
	vector <int> param22;
	param22.push_back(60);
	param22.push_back(30);
	int ret2 = objectWindowWasher.fastest(param20,param21,param22);
	int need2 = 2100;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 1000;
	int param31 = 1000;
	vector <int> param32;
	param32.push_back(1000);
	int ret3 = objectWindowWasher.fastest(param30,param31,param32);
	int need3 = 1000000000;
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 421;
	int param41 = 936;
	vector <int> param42;
	param42.push_back(111);
	param42.push_back(56);
	param42.push_back(931);
	param42.push_back(22);
	param42.push_back(445);
	param42.push_back(90);
	param42.push_back(14);
	param42.push_back(222);
	int ret4 = objectWindowWasher.fastest(param40,param41,param42);
	int need4 = 2450448;
	assert_eq(4,ret4,need4);

	//test case5
	int param50 = 25;
	int param51 = 25;
	vector <int> param52;
	param52.push_back(1);
	param52.push_back(625);
	int ret5 = objectWindowWasher.fastest(param50,param51,param52);
	int need5 = 625;
	assert_eq(5,ret5,need5);

	//test case6
	int param60 = 12;
	int param61 = 754;
	vector <int> param62;
	param62.push_back(728);
	param62.push_back(734);
	param62.push_back(147);
	param62.push_back(464);
	param62.push_back(6);
	param62.push_back(703);
	param62.push_back(254);
	int ret6 = objectWindowWasher.fastest(param60,param61,param62);
	int need6 = 54288;
	assert_eq(6,ret6,need6);

}

