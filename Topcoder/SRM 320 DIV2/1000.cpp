
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

using namespace std;

int dp[200];
//vector<int>st;
//vector<int>end;
//vector<int>prob;

struct data
{
    int st;
    int end;
    int prob;
} ;
vector<data>v;

int rec(int cur,int indx)
{
//    if( indx>=(int)v.size() ) return 0;
//    cout<<"cur "<<cur<<" indx "<<indx<<endl;

    int &ret=dp[indx];
    if(ret!=-1) return ret;

    ret=0;
    for(int i=indx;i<(int)v.size();i++)
    {
        if(cur<=v[i].st)
        {
            ret=max(ret , rec( v[i].end, i+1 ) + v[i].prob  );
        }
    }
//    cout<<"ret "<<ret<<endl;
    return ret;
}

bool com(data a , data b)
{
    if( a.end<b.end ) return true;
    else return false;
}

class ContestSchedule
{
public:
	double expectedWinnings(vector <string> contests)
	{
	    v.clear();
	    mem(dp,-1);
        stringstream ss;
        data tmp;
        for(int i=0;i<(int)contests.size();i++)
        {
            ss.clear();
            ss<<contests[i];
            ss>>tmp.st>>tmp.end>>tmp.prob;
            v.push_back(tmp);
        }
        sort(v.begin(),v.end(),com);

        int ans=rec(0,0);
        double val=ans/100.0;
        return val;
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

	ContestSchedule objectContestSchedule;

	//test case0
	vector <string> param00;
	param00.push_back("1 10 100");
	param00.push_back("10 20 100");
	param00.push_back("20 30 100");
	param00.push_back("30 40 100");
	double ret0 = objectContestSchedule.expectedWinnings(param00);
	double need0 = 4.0;
	assert_eq(0,ret0,need0);

////////	//test case1
	vector <string> param10;
	param10.push_back("10 20 20");
	param10.push_back("30 40 60");
	param10.push_back("15 35 90");
	double ret1 = objectContestSchedule.expectedWinnings(param10);
	double need1 = 0.9;
	assert_eq(1,ret1,need1);

////////	//test case2
	vector <string> param20;
	param20.push_back("1 100 85");
	param20.push_back("99 102 100");
	param20.push_back("101 200 60");
	double ret2 = objectContestSchedule.expectedWinnings(param20);
	double need2 = 1.45;
	assert_eq(2,ret2,need2);

////////	//test case3
	vector <string> param30;
	param30.push_back("1 1000000000 1");
	double ret3 = objectContestSchedule.expectedWinnings(param30);
	double need3 = 0.01;
	assert_eq(3,ret3,need3);

//////	//test case4
	vector <string> param40;
	param40.push_back("1361955 8940967 10");
	param40.push_back("628145516 644285978 17");
	param40.push_back("883515280 910484865 36");
	param40.push_back("762888635 769291174 52");
	param40.push_back("98152102 136328674 1");
	param40.push_back("9580638 20450682 50");
	param40.push_back("646139319 664648341 20");
	param40.push_back("484027666 505290970 57");
	param40.push_back("841082555 879295329 99");
	param40.push_back("940563715 966953344 4");
	param40.push_back("579113528 595261527 25");
	param40.push_back("925801172 962952912 9");
	param40.push_back("285845005 307916055 45");
	param40.push_back("403573723 410697485 10");
	param40.push_back("9467290 25698952 90");
	param40.push_back("631265400 650639733 3");
	param40.push_back("520690249 559261759 96");
	param40.push_back("491747709 531061081 86");
	param40.push_back("643215695 672420161 94");
	param40.push_back("614608448 617341712 44");
	param40.push_back("456517316 491770747 24");
	param40.push_back("806956091 828414045 88");
	param40.push_back("528156706 559510719 15");
	param40.push_back("158398859 190439269 4");
	param40.push_back("743974602 761975244 49");
	param40.push_back("882264704 887725893 1");
	param40.push_back("877444309 884479317 59");
	param40.push_back("785986538 806192822 19");
	param40.push_back("732553407 747696021 81");
	param40.push_back("132099860 148305810 97");
	param40.push_back("555144412 572785730 99");
	param40.push_back("506507263 535927950 82");
	param40.push_back("489726669 505160939 90");
	param40.push_back("793692316 804153358 99");
	param40.push_back("901329638 919179990 10");
	param40.push_back("29523791 44318662 58");
	param40.push_back("570497239 595701008 73");
	param40.push_back("706091347 730328348 23");
	param40.push_back("118054686 135301010 39");
	param40.push_back("307178252 337804001 93");
	param40.push_back("896162463 900667971 39");
	param40.push_back("271356542 273095245 80");
	param40.push_back("865692962 891795950 91");
	param40.push_back("593986003 596160000 58");
	param40.push_back("807688147 831190344 59");
	param40.push_back("468916697 496462595 92");
	double ret4 = objectContestSchedule.expectedWinnings(param40);
	double need4 = 14.12;
	assert_eq(4,ret4,need4);

}
