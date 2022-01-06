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

vector<string>v;

bool valid(int prc,int days)
{
    int tot=0,item=SZ(v[0]),mon,cost;
    for(int i=0;i<min(days,7);i++)
    {
        cost=oo;
        for(int p=0;p<item;p++)
        {
            mon=0;
            for(int j=i;j<days;j+=7)
            {
                if(isdigit(v[j][p])) mon+=(v[j][p]-'0');
                else if(isalpha(v[j][p]))
                {
                    if(isupper(v[j][p])) mon+=(v[j][p]-'A' + 10);
                    else mon+=(v[j][p]-'a'+36);
                }
            }
            cost=min(cost,mon);
        }
        tot+=cost;
        if(tot>prc) return false;
    }
    return true;
}


class MysteriousRestaurant
 {
public:


int maxDays(vector <string> prices, int budget)
{
    v=prices;
    for(int i=SZ(prices);i>=0;i--)
    {
        if(valid(budget,i) ) return i;
    }
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
		cout << "Testing MysteriousRestaurant (512.0 points)" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1310644707;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 512.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MysteriousRestaurant _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string prices[] = {"26", "14", "72", "39", "32", "85", "06"};
				int budget = 13;
				_expected = 5;
				_received = _obj.maxDays(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), budget); break;
			}
			case 1:
			{
				string prices[] = {"26", "14", "72", "39", "32", "85", "06", "91"};
				int budget = 20;
				_expected = 8;
				_received = _obj.maxDays(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), budget); break;
			}
			case 2:
			{
				string prices[] = {"SRM", "512"};
				int budget = 4;
				_expected = 0;
				_received = _obj.maxDays(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), budget); break;
			}
			case 3:
			{
				string prices[] = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"};
				int budget = 256;
				_expected = 10;
				_received = _obj.maxDays(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), budget); break;
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

