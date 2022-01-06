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
#define rep(x,n)        for(int x=0;x<(int)(n);x++)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcount(i))
#define fs      first
#define sc      second

///ll rrr[]={1,0,-1,0};ll ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///ll month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

//vector<int>num;
map<int,int>M;

bool ok(int num)
{
    string str;
    stringstream ss;
    ss<<num;
    ss>>str;
    for(int i=0;i<SZ(str);i++)
    {
        if(str[i]!='5' && str[i]!='8') return false;
    }
    return true;

}
class FortunateNumbers
 {
public:
int getFortunate(vector <int> a, vector <int> b, vector <int> c)
{
    for(int i=0;i<SZ(a);i++)
        for(int j=0;j<SZ(b);j++)
            for(int k=0;k<SZ(c);k++)
            {
                M[a[i]+b[j]+c[k]]=1;
            }

    int cnt=0;
    for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
    {
        if(ok(it->fs) ) cnt++;
    }
    return cnt;
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
		cout << "Testing FortunateNumbers (250.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1313856131;
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
		FortunateNumbers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = { 1, 10, 100 };
				int b[] = { 3, 53 };
				int c[] = { 4, 54 };
				_expected = 2;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = { 47 };
				int b[] = { 500 };
				int c[] = { 33 };
				_expected = 0;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = { 100, 1, 10, 100, 1, 1 };
				int b[] = { 3, 53, 53, 53, 53, 53, 53 };
				int c[] = { 4, 54, 4, 54, 4, 54 };
				_expected = 2;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = { 500, 800 };
				int b[] = { 50, 80 };
				int c[] = { 5, 8 };
				_expected = 8;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = { 30000, 26264 };
				int b[] = { 30000, 29294 };
				int c[] = { 30000, 29594 };
				_expected = 3;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
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

