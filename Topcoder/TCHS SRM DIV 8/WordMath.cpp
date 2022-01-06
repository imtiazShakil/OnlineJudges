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

class WordMath
 {
public:
int maximumSum(vector <string> summands)
{
    int arr[300];mem(arr,0);
    map<char,int>M;
    for(int i=0;i<SZ(summands);i++)
    {
        for(int j=0;j<SZ(summands[i]);j++)
        {
            M[summands[i][j]]=1;
        }
    }
    char str[20];mem(str,0);
    int len=M.size();
    int k=0;
    for(map<char,int>::iterator it=M.begin();it!=M.end();it++)
    {
        str[k++]=it->first;
    }
    int start=10-len,val;
    int p=start;
    int sum,mx=0;

    printf("%s\n",str);
    for(int i=0;i<len;i++,p++) arr[str[i]]=p;
        sum=0;
        for(int j=0;j<SZ(summands);j++)
        {
            val=0;
            for(int k=0;k<SZ(summands[j]);k++)
            {
                val*=10;
                val+=arr[summands[j][k]];
            }
            sum+=val;
        }
        mx=max(mx,sum);

    while(next_permutation(str,str+len))
    {
        p=start;
        for(int i=0;i<len;i++,p++) arr[str[i]]=p;
        sum=0;
        for(int j=0;j<SZ(summands);j++)
        {
            val=0;
            for(int k=0;k<SZ(summands[j]);k++)
            {
                val*=10;
                val+=arr[summands[j][k]];
            }
            sum+=val;
        }
        mx=max(mx,sum);

    }
    return mx;

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
		cout << "Testing WordMath (500.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1310387314;
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
		WordMath _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string summands[] = {"TOP", "CODER"};
				_expected = 99437;
				_received = _obj.maximumSum(vector <string>(summands, summands+sizeof(summands)/sizeof(string))); break;
			}
			case 1:
			{
				string summands[] = {"AAA", "AAA"};
				_expected = 1998;
				_received = _obj.maximumSum(vector <string>(summands, summands+sizeof(summands)/sizeof(string))); break;
			}
			case 2:
			{
				string summands[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
				_expected = 45;
				_received = _obj.maximumSum(vector <string>(summands, summands+sizeof(summands)/sizeof(string))); break;
			}
			case 3:
			{
				string summands[] = {"AB", "BA"};
				_expected = 187;
				_received = _obj.maximumSum(vector <string>(summands, summands+sizeof(summands)/sizeof(string))); break;
			}
			case 4:
			{
				string summands[] = {"READIEST","OPERATIC","TOPCODER","PREDICTS","RAPIDEST","ASTEROID","AIRSPEED"};
				_expected = 563639653;
				_received = _obj.maximumSum(vector <string>(summands, summands+sizeof(summands)/sizeof(string))); break;
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

