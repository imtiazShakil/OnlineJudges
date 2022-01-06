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
#define MAX 100
#define mod 1000000000
using namespace std;

int dp[MAX][MAX][30];

int rrr[]={-1,-1,-1,0,1,1,1,0};
int ccc[]={-1,0,1,1,1,0,-1,-1};

vector<string>mat;

int len,max_r,max_c;

int rec(int row,int col,int depth)
{
    if(depth ==len-1 ) return 1;

    int &ret=dp[row][col][depth];
    if(ret!=-1) return ret;

    ret=0;
    int r,c;
    for(int i=0;i<8;i++)
    {
        r=row+rrr[i];
        c=col+ccc[i];
        if(r>=0 && r<=max_r && c>=0 && c<=max_c )
        {
            if( mat[r][c]== mat[row][col] + 1 )
            {
                ret+=rec(r,c,depth+1) ;
                if(ret>=mod)
                {
                    ret=mod;
                    return ret;
                }
            }
        }
    }
    return ret;
}
class AlphabetCount
{
public:
	int count(vector <string> grid, int length)
	{
        mat.clear();
        mat=grid;len=length;
        max_r=(int)grid.size()-1;max_c=(int)grid[0].size() -1;
        mem(dp,-1);
        int ans=0;
        for(int i=0;i<=max_r;i++)
            for(int j=0;j<=max_c;j++)
            {
                if(mat[i][j]=='A')
                {
                    ans+=rec(i,j,0);
                    if(ans>=mod) {ans=mod;return ans;}
                }
            }
//        int ans=rec(0,0,0);
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

	AlphabetCount objectAlphabetCount;

	//test case0
	vector <string> param00;
	param00.push_back("ABC");
	param00.push_back("CBZ");
	param00.push_back("CZC");
	param00.push_back("BZZ");
	param00.push_back("ZAA");
	int param01 = 3;
	int ret0 = objectAlphabetCount.count(param00,param01);
	int need0 = 7;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("AAAA");
	param10.push_back("AAAA");
	param10.push_back("AAAA");
	int param11 = 1;
	int ret1 = objectAlphabetCount.count(param10,param11);
	int need1 = 12;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("ABAB");
	param20.push_back("BABA");
	param20.push_back("ABAB");
	param20.push_back("BABA");
	int param21 = 2;
	int ret2 = objectAlphabetCount.count(param20,param21);
	int need2 = 24;
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("HIJKLMNOPQZZZONMLKHIDZYQR");
	param30.push_back("GYXWVUTSRASTZZPSTUJGECPXS");
	param30.push_back("FZABCDEFARQPUQRAAAVWFBOWT");
	param30.push_back("EONMJIHGAJMNOVAAAAAYXANUV");
	param30.push_back("DCBLKDEFIEKLEDWAAAZFGHMLK");
	param30.push_back("UVAZYBCGHFDFCAYXNPQZEDIJA");
	param30.push_back("TSWXAKLZGCZBGZIJOMZRUTCBZ");
	param30.push_back("RQPONMJIHBAZZHZZKLZZSVWXY");
	int param31 = 26;
	int ret3 = objectAlphabetCount.count(param30,param31);
	int need3 = 7;
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back("CZC");
	param40.push_back("ZBZ");
	param40.push_back("AZA");
	int param41 = 3;
	int ret4 = objectAlphabetCount.count(param40,param41);
	int need4 = 4;
	assert_eq(4,ret4,need4);

	//test case5
	vector <string> param50;
	param50.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	param50.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	param50.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	int param51 = 26;
	int ret5 = objectAlphabetCount.count(param50,param51);
	int need5 = 1000000000;
	assert_eq(5,ret5,need5);

	//test case6
	vector <string> param60;
	param60.push_back("BDBCBACABDDCCADCBDDCBDDDBCCCCABACADDDCCCBADDDBADCA");
	param60.push_back("DCBBBACBDBACCADABCCAABACDBADBCBBABACBCADADCBDABBBD");
	int param61 = 4;
	int ret6 = objectAlphabetCount.count(param60,param61);
	int need6 = 20;
	assert_eq(6,ret6,need6);

}

