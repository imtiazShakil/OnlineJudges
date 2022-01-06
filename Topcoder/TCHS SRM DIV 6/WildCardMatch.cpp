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
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<endl
#define PI (2*acos(0))
#define ERR 1e-5
#define ll long long
#define VI vector<int>
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x.begin(),x.end())
#define mp make_pair
#define MAX 60
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)

//ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
//ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

int dp[MAX][MAX];
string str, txt;

int rec(int i,int j)
{

    if(i==SZ(str) && j==SZ(txt)) return 0;

    int &ret=dp[i][j];
    if(ret!=-1) return ret;
    ret=oo;
    if(i<SZ(str) && j<SZ(txt))
    {
        if( str[i]==txt[j]  || txt[j]=='?' )
        {
            ret=min(ret,rec(i+1,j+1));
        }
        else
        {
            ret=min(ret,rec(i+1,j+1) + 1);///replace
            ret=min(ret,rec(i,j+1) + 1);///add 2 str
            ret=min(ret,rec(i+1,j) + 1);///del frm str
        }
    }
    else
    {
        if(j<SZ(txt)) ret=min(ret,rec(i,j+1) + 1);
        if(i<SZ(str) ) ret=min(ret,rec(i+1,j) + 1);
    }
    return ret;
}
class WildCardMatch
 {
public:
int minimalChanges(string file, string pattern)
{
    str=file;txt=pattern;
    mem(dp,-1);
    int ans=rec(0,0);
    return ans;
}
};
// BEGIN CUT HERE
    #include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "Testing WildCardMatch (600.0 points)" << endl << endl;
		for (int i = 0; i < 6; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1309343577;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WildCardMatch _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			//case 0:
			{
				string file = "abcd";
				string pattern = "bcd";
				_expected = 1;
				_received = _obj.minimalChanges(file, pattern); break;
			}
			//case 1:
			{
				string file = "abcd";
				string pattern = "b??";
				_expected = 1;
				_received = _obj.minimalChanges(file, pattern); break;
			}
			//case 2:
			{
				string file = "aaaabbb";
				string pattern = "aa????b";
				_expected = 0;
				_received = _obj.minimalChanges(file, pattern); break;
			}
			//case 3:
			{
				string file = "asdjkhajksdhajksdh";
				string pattern = "asdjkhasdjk?";
				_expected = 6;
				_received = _obj.minimalChanges(file, pattern); break;
			}
			//case 4:
			{
				string file = "niceone";
				string pattern = "ieo?e";
				_expected = 2;
				_received = _obj.minimalChanges(file, pattern); break;
			}
			case 5:
			{
				string file = "a";
				string pattern = "a?";
				_expected = 1;
				_received = _obj.minimalChanges(file, pattern); break;
			}
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

    // END CUT HERE

