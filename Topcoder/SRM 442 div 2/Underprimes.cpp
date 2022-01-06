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
#define MAX 100005
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

int prm[10000];
bool num[MAX];
int freq[MAX];

void seive(void)
{
    int j,k=0;

    num[1]=1;
    for(int i=4;i<MAX;i+=2) num[i]=1;

    prm[0]=2;freq[2]=1;
    for(int i=3;i<MAX;i+=2)
    {
        if(!num[i])
        {
            prm[++k]=i;
            freq[i]=1;
            if(i<MAX/i) for( j=i*i;j<MAX;j+=i) num[j]=1;
        }
    }
    print2(k+1,prm[k]);
    return ;
}
int rec(int n)
{
    int &ret=freq[n];
    if(ret!=-1) return ret;
    int srt=sqrt(n)+1;
    for(int i=0;prm[i]<srt;i++)
    {
        if(n%prm[i]==0)
        {
            ret=rec(n/prm[i]) + 1;
            return ret;
        }
    }
}
bool ok(int n)
{
    return !num[n];
}
class Underprimes
 {
public:
int howMany(int A, int B)
{
    mem(freq,-1);
    seive();
    int cnt=0;
    for(int i=A;i<=B;i++)
    {
        if( ok(rec(i)) ) {cnt++;}
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
		cout << "Testing Underprimes (500.0 points)" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1316593006;
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
		Underprimes _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 2;
				int B = 10;
				_expected = 5;
				_received = _obj.howMany(A, B); break;
			}
			case 1:
			{
				int A = 100;
				int B = 105;
				_expected = 2;
				_received = _obj.howMany(A, B); break;
			}
			case 2:
			{
				int A = 1;
				int B = 100000;
				_expected = 0;
				_received = _obj.howMany(A, B); break;
			}
			case 3:
			{
				int A = 123;
				int B = 456;
				_expected = 217;
				_received = _obj.howMany(A, B); break;
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

