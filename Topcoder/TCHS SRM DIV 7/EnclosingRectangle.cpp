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
#define MAX 100
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)


using namespace std;

class EnclosingRectangle
 {
public:
int smallestArea(vector <string> X, vector <string> Y)
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
		cout << "Testing EnclosingRectangle (1000.0 points)" << endl << endl;
		for (int i = 0; i < 7; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1310304629;
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
		EnclosingRectangle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string X[] = { "100 200" };
				string Y[] = { "100 200" };
				_expected = 4;
				_received = _obj.smallestArea(vector <string>(X, X+sizeof(X)/sizeof(string)), vector <string>(Y, Y+sizeof(Y)/sizeof(string))); break;
			}
			case 1:
			{
				string X[] = { "10 11 13 10 11 13" };
				string Y[] = { "5 5 5 15 16 17" };
				_expected = 10;
				_received = _obj.smallestArea(vector <string>(X, X+sizeof(X)/sizeof(string)), vector <string>(Y, Y+sizeof(Y)/sizeof(string))); break;
			}
			case 2:
			{
				string X[] = { "5 6 6 7 7 8 8 9" };
				string Y[] = { "7 6 8 5 9 6 8 7" };
				_expected = 16;
				_received = _obj.smallestArea(vector <string>(X, X+sizeof(X)/sizeof(string)), vector <string>(Y, Y+sizeof(Y)/sizeof(string))); break;
			}
			case 3:
			{
				string X[] = { "4496 6443 2837 557 4098 1083 3466 1250 6126 ",
				               "3135 7598 9274 9180 5128 741 7625 8316 414 ",
				               "9071 8753 5509 1080 2797 906 3805 698 947 ",
				               "8645 9640 2596 6883 1845 9169 3922 4792 7919 ",
				               "7389 9397 4901 1343 3347 6366 9118 3148 780 ",
				               "4541 9479 483 1174 9615 8900 3067 5397 9879 ",
				               "7440 8948 846 8881 7602 6760 3327 5197 9017 ",
				               "5463 6781 2478 6270 5392 9420 9069 3609 6401 ",
				               "1810 6680 6787 9840 1031 1916 5415 1168 5154 ",
				               "2727 8834 9125 3961 4289 4750 5524 5118 5258 ",
				               "2652 7020 9770 5866 3386 6447 7960 3889 2158 ",
				               "6717" };
				string Y[] = { "6801 8243 9390 2156 5505 5509 3442 6663 1294 ",
				               "9979 1008 5644 7516 5442 5909 4550 2431 2779 ",
				               "419 4744 8155 7800 2944 4169 1633 1464 7353 ",
				               "5365 1548 3073 8596 4461 2540 4664 5057 1870 ",
				               "4782 4028 8003 9175 2592 4520 2420 6955 519 ",
				               "2141 1580 5170 9138 4268 9724 1093 5633 9820 ",
				               "3411 9789 6200 7661 2296 8644 8259 8631 4342 ",
				               "574 530 6664 8812 161 8141 6210 2803 3209 ",
				               "8090 6380 3498 3014 7650 7062 8853 5939 4578 ",
				               "8647 4020 4844 3362 4930 9447 1346 6162 8242 ",
				               "9276 6967 589 6960 5467 8768 9018 8155 3886 ",
				               "7274" };
				_expected = 37305252;
				_received = _obj.smallestArea(vector <string>(X, X+sizeof(X)/sizeof(string)), vector <string>(Y, Y+sizeof(Y)/sizeof(string))); break;
			}
			case 4:
			{
				string X[] = { "5481    3318      5721      9019 ",
				               "1618       9762  1654     2275 ",
				               "5361    307 6833             9456  ",
				               "7473 6088 9685 2725" };
				string Y[] = { "1181     7762        3889    7015 ",
				               "    5445   9063        2510           8229 ",
				               "   4390      6454   9197    708 ",
				               "  2221    9012     2665      8308" };
				_expected = 25959465;
				_received = _obj.smallestArea(vector <string>(X, X+sizeof(X)/sizeof(string)), vector <string>(Y, Y+sizeof(Y)/sizeof(string))); break;
			}
			case 5:
			{
				string X[] = {  "1242 9594 6816 833 6587 7183 9355 7087 ",
				                "  ",
				                "8675 5944 786 3597 1327 9884 7138 8073 ",
				                "",
				                "3017 5468 331 8136" };
				string Y[] = { "1105 7791 7865 8119 ",
				               "9950 8261 5988 1708 ",
				               "1615 5400 487 4837 4712 5777 3819 ",
				               "",
				               "5063 5143 5990 2895 4375",
				                "" };
				_expected = 18598707;
				_received = _obj.smallestArea(vector <string>(X, X+sizeof(X)/sizeof(string)), vector <string>(Y, Y+sizeof(Y)/sizeof(string))); break;
			}
			case 6:
			{
				string X[] = { "100", " 200" };
				string Y[] = { "100 2", "00" };
				_expected = 4;
				_received = _obj.smallestArea(vector <string>(X, X+sizeof(X)/sizeof(string)), vector <string>(Y, Y+sizeof(Y)/sizeof(string))); break;
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

