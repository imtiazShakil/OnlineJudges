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

//ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
//ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;
int arr[]={0,1,2};

bool valid(int h,int m,int s)
{
//    stringstream ss;
//    ss<<hr;
//    int h,m,s;
//    ss>>h;
//    ss.clear();ss<<mn;
//    ss>>m;
//    ss.clear();ss<<sc;
//    ss>>s;
    if(h>=1 && h<=12 && m>=0 && m<=59 && s>=0 && s<=59) return true;
    else return false;
}
class DigitalDisplay
 {
public:
int waysToInterpret(string display)
{
    int count=0;
    int t[3];
    t[0]=(display[0]-'0')*10 + display[1]-'0';
    t[1]=(display[3]-'0')*10 + display[4]-'0';
    t[2]=(display[6]-'0')*10 + display[7]-'0';

    while(next_permutation(arr,arr+3))
    {
//        cout<<arr[0]<<arr[1]<<arr[2]<<endl;
        if(valid(t[arr[0]],t[arr[1]],t[arr[2]]) ) count++;
    }
    if(valid(t[0],t[1],t[2])) count++;
    return count;
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
		cout << "Testing DigitalDisplay (250.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1309342747;
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
		DigitalDisplay _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string display = "21:23:01";
				_expected = 2;
				_received = _obj.waysToInterpret(display); break;
			}
			case 1:
			{
				string display = "00:00:00";
				_expected = 0;
				_received = _obj.waysToInterpret(display); break;
			}
			case 2:
			{
				string display = "01:02:03";
				_expected = 6;
				_received = _obj.waysToInterpret(display); break;
			}
			case 3:
			{
				string display = "59:59:01";
				_expected = 2;
				_received = _obj.waysToInterpret(display); break;
			}
			case 4:
			{
				string display = "01:01:59";
				_expected = 4;
				_received = _obj.waysToInterpret(display); break;
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

