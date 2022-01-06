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

class YetAnotherIncredibleMachine
 {
public:
int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls)
{
    ll val=1,c;
    int mn,mx;
    for(int i=0;i<SZ( platformLength );i++)
    {
        mn=platformMount[i] - platformLength[i];
        mx=platformMount[i] + platformLength[i];
        c=0;
//        print2(mn,mx);
        for(int j=mn;j+platformLength[i]<=mx;j++)
        {
            bool flag=1;
            for(int q=0;q<SZ(balls);q++)
            {
                if( j<=balls[q] && balls[q]<=j+platformLength[i] ) flag=0;
            }
            if(flag) c++;
        }
        val=val*c;
        val=val%1000000009LL;
    }
    return val;
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
		cout << "Testing YetAnotherIncredibleMachine (500.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1311679168;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		YetAnotherIncredibleMachine _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int platformMount[] = {7};
				int platformLength[] = {10};
				int balls[] = {3,4};
				_expected = 3;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
			}
			case 1:
			{
				int platformMount[] = {1,4};
				int platformLength[] = {3,3};
				int balls[] = {2,7};
				_expected = 1;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
			}
			case 2:
			{
				int platformMount[] = {4,4,4};
				int platformLength[] = {10,9,8};
				int balls[] = {1,100};
				_expected = 27;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
			}
			case 3:
			{
				int platformMount[] = {0};
				int platformLength[] = {1};
				int balls[] = {0};
				_expected = 0;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
			}
			case 4:
			{
				int platformMount[] = {100, -4215, 251};
				int platformLength[] = {400, 10000, 2121};
				int balls[] = {5000, 2270, 8512, 6122};
				_expected = 250379170;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
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

