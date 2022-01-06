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

class StraightArray
 {
public:
int howManyMore(vector <int> nums)
{
    map<int,int>M;
    map<int,int>S;
    int count;
    for(int i=0;i<SZ(nums);i++)
    {
        M[nums[i]]=1;
    }
    for(int i=0;i<SZ(nums);i++)
    {
        int low=5;
        for(int j=0;j<5;j++)
        {

            if(nums[i]-j)
            {
                 count=0;
                for(int k=nums[i]-j,t=0;t<5;t++,k++)
                {
                    if(M.find(k)==M.end()) count++;
                }
                low=min(low,count);
            }

        }
        S[nums[i]]=low;
    }
    int mn=5;
    for(map<int,int>::iterator it=S.begin();it!=S.end();it++)
    {
        mn=min(mn,it->second);
    }
    return mn;
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
		cout << "Testing StraightArray (500.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1310287187;
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
		StraightArray _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int nums[] = { 5, 6, 7 };
				_expected = 2;
				_received = _obj.howManyMore(vector <int>(nums, nums+sizeof(nums)/sizeof(int))); break;
			}
			case 1:
			{
				int nums[] = { 5, 7, 9, 8492, 8493, 192398 };
				_expected = 2;
				_received = _obj.howManyMore(vector <int>(nums, nums+sizeof(nums)/sizeof(int))); break;
			}
			case 2:
			{
				int nums[] = {1000000000, 999999999, 2345, 1800, 654321, 0, 3};
				_expected = 3;
				_received = _obj.howManyMore(vector <int>(nums, nums+sizeof(nums)/sizeof(int))); break;
			}
			case 3:
			{
				int nums[] = { 399710788, 908814160, 716153223, 970654133, 506644631, 217544361,
				               260957226, 132981872, 483739151, 595795986, 824140293, 362514681,
				               716153227, 336131843, 406529057, 147725164 } ;
				_expected = 3;
				_received = _obj.howManyMore(vector <int>(nums, nums+sizeof(nums)/sizeof(int))); break;
			}
			case 4:
			{
				int nums[] = {0};
				_expected = 4;
				_received = _obj.howManyMore(vector <int>(nums, nums+sizeof(nums)/sizeof(int))); break;
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

