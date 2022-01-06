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

class MagicalGirlLevelThreeDivTwo
 {
public:
int theCount(vector <string> first, int n, long long lo, long long hi)
{		
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
		cout << "Testing MagicalGirlLevelThreeDivTwo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 6; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1312942056;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MagicalGirlLevelThreeDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string first[] = {"101", "01"};
				int n = 4;
				long long lo = 2LL;
				long long hi = 5LL;
				_expected = 2;
				_received = _obj.theCount(vector <string>(first, first+sizeof(first)/sizeof(string)), n, lo, hi); break;
			}
			case 1:
			{
				string first[] = {"01", "10"};
				int n = 5;
				long long lo = 4LL;
				long long hi = 5LL;
				_expected = 1;
				_received = _obj.theCount(vector <string>(first, first+sizeof(first)/sizeof(string)), n, lo, hi); break;
			}
			case 2:
			{
				string first[] = {"1", "11", "111"};
				int n = 46;
				long long lo = 10000LL;
				long long hi = 11000LL;
				_expected = 1001;
				_received = _obj.theCount(vector <string>(first, first+sizeof(first)/sizeof(string)), n, lo, hi); break;
			}
			case 3:
			{
				string first[] = {"0", "00", "000"};
				int n = 46;
				long long lo = 10000LL;
				long long hi = 11000LL;
				_expected = 0;
				_received = _obj.theCount(vector <string>(first, first+sizeof(first)/sizeof(string)), n, lo, hi); break;
			}
			case 4:
			{
				string first[] = {"00110110101101001111101101001011010011111011010010"};
				int n = 100;
				long long lo = 999999999999915LL;
				long long hi = 1000000000000000LL;
				_expected = 50;
				_received = _obj.theCount(vector <string>(first, first+sizeof(first)/sizeof(string)), n, lo, hi); break;
			}
			case 5:
			{
				string first[] = {"10000", "011011001011000001101000010100000111000110110", 
				                 "000001010001011000001101110", "100100000110100001010000", 
				                 "011011010", "01100000010101101110000011100011001000",
				                 "0001010", "010011000", "000101001", "00", "1"};
				int n = 91;
				long long lo = 123456LL;
				long long hi = 123654LL;
				_expected = 76;
				_received = _obj.theCount(vector <string>(first, first+sizeof(first)/sizeof(string)), n, lo, hi); break;
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

