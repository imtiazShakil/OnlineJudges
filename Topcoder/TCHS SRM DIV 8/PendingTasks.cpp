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
#define all(x) x.begin(),x.end()
#define mp make_pair
#define MAX 100
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)


using namespace std;

class PendingTasks
 {
public:
int latestProcess(vector <int> supertasks)
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
		cout << "Testing PendingTasks (1000.0 points)" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1310390580;
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
		PendingTasks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int supertasks[] = {4,4,4,4,-1};
				_expected = 2;
				_received = _obj.latestProcess(vector <int>(supertasks, supertasks+sizeof(supertasks)/sizeof(int))); break;
			}
			case 1:
			{
				int supertasks[] = {1,2,3,4,-1};
				_expected = 4;
				_received = _obj.latestProcess(vector <int>(supertasks, supertasks+sizeof(supertasks)/sizeof(int))); break;
			}
			case 2:
			{
				int supertasks[] = {-1};
				_expected = 0;
				_received = _obj.latestProcess(vector <int>(supertasks, supertasks+sizeof(supertasks)/sizeof(int))); break;
			}
			case 3:
			{
				int supertasks[] = {6,6,6,7,7,7,8,8,-1};
				_expected = 7;
				_received = _obj.latestProcess(vector <int>(supertasks, supertasks+sizeof(supertasks)/sizeof(int))); break;
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

