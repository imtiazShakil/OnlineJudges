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

class TrainingCamp
 {
public:
    vector <string>  determineSolvers(vector <string> attendance, vector <string> problemTopics)
{
    vector<string>v;string str;
    bool flag;
    for(int s=0;s<SZ( attendance );s++)
    {
        str.clear();
        for(int i=0;i<SZ( problemTopics );i++)
        {
            flag=1;
            for(int j=0;j<SZ( problemTopics[i] );j++)
            {
                if(problemTopics[i][j]=='X' && attendance[s][j]=='-') flag=0;
            }
            if(flag) str+='X';
            else str+='-';

        }
        v.pb(str);
    }
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
		cout << "Testing TrainingCamp (250.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1311678157;
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
		TrainingCamp _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string attendance[] = {"XXX",
				                       "XXX",
				                       "XX-"};
				string problemTopics[] = {"---",
				                          "XXX",
				                          "-XX",
				                          "XX-"};
				string __expected[] = {"XXXX", "XXXX", "X--X" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.determineSolvers(vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string)), vector <string>(problemTopics, problemTopics+sizeof(problemTopics)/sizeof(string))); break;
			}
			case 1:
			{
				string attendance[] = {"-XXXX",
				                       "----X",
				                       "XXX--",
				                       "X-X-X"};
				string problemTopics[] = {"X---X",
				                          "-X---",
				                          "XXX--",
				                          "--X--"};
				string __expected[] = {"-X-X", "----", "-XXX", "X--X" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.determineSolvers(vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string)), vector <string>(problemTopics, problemTopics+sizeof(problemTopics)/sizeof(string))); break;
			}
			case 2:
			{
				string attendance[] = {"-----",
				                       "XXXXX"};
				string problemTopics[] = {"XXXXX",
				                          "-----",
				                          "--X-X"};
				string __expected[] = {"-X-", "XXX" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.determineSolvers(vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string)), vector <string>(problemTopics, problemTopics+sizeof(problemTopics)/sizeof(string))); break;
			}
			case 3:
			{
				string attendance[] = {"-",
				                       "X",
				                       "X",
				                       "-",
				                       "X"};
				string problemTopics[] = {"-",
				                          "X"};
				string __expected[] = {"X-", "XX", "XX", "X-", "XX" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.determineSolvers(vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string)), vector <string>(problemTopics, problemTopics+sizeof(problemTopics)/sizeof(string))); break;
			}
			case 4:
			{
				string attendance[] = {"X----X--X",
				                       "X--X-X---",
				                       "--X-X----",
				                       "XXXX-X-X-",
				                       "XXXX--XXX"};
				string problemTopics[] = {"X----X-X-",
				                          "-----X---",
				                          "-X----X-X",
				                          "-X-X-X---",
				                          "-----X---",
				                          "X-------X"};
				string __expected[] = {"-X--XX", "-X--X-", "------", "XX-XX-", "--X--X" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.determineSolvers(vector <string>(attendance, attendance+sizeof(attendance)/sizeof(string)), vector <string>(problemTopics, problemTopics+sizeof(problemTopics)/sizeof(string))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

    // END CUT HERE

