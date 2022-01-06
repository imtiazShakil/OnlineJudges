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
#define rep(x,n)        for(x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

class TrainingCamp
{
public:
	vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics)
	{
	    vector<string>v;string str;
        bool flag;
        for(int s=0;s<SZ( attendance );s++)
        {
            str.clear();
            for(int i=0;i<SZ( problemTopics );i++)
            {
                flag=1;
                for(int j=0;j<SZ( problemTopics[i] );j++)
                {
                    if(problemTopics[i][j]=='X' && attendance[s][j]=='-') flag=0;
                }
                if(flag) str+='X';
                else str+='-';

            }
            v.pb(str);
        }
        return v;
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

	TrainingCamp objectTrainingCamp;

	//test case0
	vector <string> param00;
	param00.push_back("XXX");
	param00.push_back("XXX");
	param00.push_back("XX-");
	vector <string> param01;
	param01.push_back("---");
	param01.push_back("XXX");
	param01.push_back("-XX");
	param01.push_back("XX-");
	vector <string> ret0 = objectTrainingCamp.determineSolvers(param00,param01);
	vector <string> need0;
	need0.push_back("XXXX");
	need0.push_back("XXXX");
	need0.push_back("X--X");
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("-XXXX");
	param10.push_back("----X");
	param10.push_back("XXX--");
	param10.push_back("X-X-X");
	vector <string> param11;
	param11.push_back("X---X");
	param11.push_back("-X---");
	param11.push_back("XXX--");
	param11.push_back("--X--");
	vector <string> ret1 = objectTrainingCamp.determineSolvers(param10,param11);
	vector <string> need1;
	need1.push_back("-X-X");
	need1.push_back("----");
	need1.push_back("-XXX");
	need1.push_back("X--X");
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("-----");
	param20.push_back("XXXXX");
	vector <string> param21;
	param21.push_back("XXXXX");
	param21.push_back("-----");
	param21.push_back("--X-X");
	vector <string> ret2 = objectTrainingCamp.determineSolvers(param20,param21);
	vector <string> need2;
	need2.push_back("-X-");
	need2.push_back("XXX");
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("-");
	param30.push_back("X");
	param30.push_back("X");
	param30.push_back("-");
	param30.push_back("X");
	vector <string> param31;
	param31.push_back("-");
	param31.push_back("X");
	vector <string> ret3 = objectTrainingCamp.determineSolvers(param30,param31);
	vector <string> need3;
	need3.push_back("X-");
	need3.push_back("XX");
	need3.push_back("XX");
	need3.push_back("X-");
	need3.push_back("XX");
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back("X----X--X");
	param40.push_back("X--X-X---");
	param40.push_back("--X-X----");
	param40.push_back("XXXX-X-X-");
	param40.push_back("XXXX--XXX");
	vector <string> param41;
	param41.push_back("X----X-X-");
	param41.push_back("-----X---");
	param41.push_back("-X----X-X");
	param41.push_back("-X-X-X---");
	param41.push_back("-----X---");
	param41.push_back("X-------X");
	vector <string> ret4 = objectTrainingCamp.determineSolvers(param40,param41);
	vector <string> need4;
	need4.push_back("-X--XX");
	need4.push_back("-X--X-");
	need4.push_back("------");
	need4.push_back("XX-XX-");
	need4.push_back("--X--X");
	assert_eq(4,ret4,need4);

}

