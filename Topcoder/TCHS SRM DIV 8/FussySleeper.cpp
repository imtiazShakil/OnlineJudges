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



#define pb push_back


using namespace std;

class FussySleeper
 {
public:
vector <int> nextTime(vector <int> currentTime, int elephants)
{
    int val=currentTime[0];
    val=val*100+currentTime[1];
    int ans;
    if(val==2359) val=-1;
    for(int i=val+1;i<=2359;i++)
    {
        if(i%100>59) continue;
        if(i%elephants==0) {ans=i;break;}
        if(i==2359) i=-1;
    }
    vector<int>v;
    v.pb(ans/100);
    v.pb(ans%100);
    return v;

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
		cout << "Testing FussySleeper (250.0 points)" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1310385812;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FussySleeper _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int currentTime[] = {23, 59};
				int elephants = 100;
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.nextTime(vector <int>(currentTime, currentTime+sizeof(currentTime)/sizeof(int)), elephants); break;
			}
			case 1:
			{
				int currentTime[] = {20, 30};
				int elephants = 23;
				int __expected[] = {20, 47 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.nextTime(vector <int>(currentTime, currentTime+sizeof(currentTime)/sizeof(int)), elephants); break;
			}
			case 2:
			{
				int currentTime[] = {23,55};
				int elephants = 1;
				int __expected[] = {23, 56 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.nextTime(vector <int>(currentTime, currentTime+sizeof(currentTime)/sizeof(int)), elephants); break;
			}
			case 3:
			{
				int currentTime[] = {0, 0};
				int elephants = 999;
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.nextTime(vector <int>(currentTime, currentTime+sizeof(currentTime)/sizeof(int)), elephants); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

    // END CUT HERE

