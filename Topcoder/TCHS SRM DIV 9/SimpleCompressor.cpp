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

bool chk(string str)
{
    for(int i=0;i<SZ(str);i++)
    {
        if(str[i]=='[' || str[i]==']' ) return true;
    }
    return false;
}

class SimpleCompressor
 {
public:
string uncompress(string toUncompress)
{
    int strt,end;
    int mul;
    string tmp,tmp2;
    while( chk( toUncompress ) )
    {
        tmp.clear();
        for(int i=0;i<SZ( toUncompress );i++)
        {
            if( toUncompress[i]=='[' )
            {
                tmp2.clear();

                int cnt=1,strt=i;
                mul=toUncompress[strt+1]-'0';
                for(int p=i+1;p<SZ( toUncompress );p++ )
                {
                    if( toUncompress[p]==']' ) cnt--;
                    else if( toUncompress[p]=='['  ) cnt++;
                    if(cnt==0) {end=p;break;}
                }
                tmp2=toUncompress.substr( strt+2,end-1 - (strt+2) +1 );

                for(int p=0;p<mul;p++) tmp+=tmp2;

                i=end;
            }
            else tmp+=toUncompress[i];
        }
        toUncompress=tmp;
    }
    return toUncompress;
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
		cout << "Testing SimpleCompressor (500.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1317050450;
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
		SimpleCompressor _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string toUncompress = "C[6AB]C";
				_expected = "CABABABABABABC";
				_received = _obj.uncompress(toUncompress); break;
			}
			case 1:
			{
				string toUncompress = "C[2[3AB]]C";
				_expected = "CABABABABABABC";
				_received = _obj.uncompress(toUncompress); break;
			}
			case 2:
			{
				string toUncompress = "CO[1N]TEST";
				_expected = "CONTEST";
				_received = _obj.uncompress(toUncompress); break;
			}
			case 3:
			{
				string toUncompress = "[2[2AB]]";
				_expected = "ABABABAB";
				_received = _obj.uncompress(toUncompress); break;
			}
			case 4:
			{
				string toUncompress = "AAAAAAAAAAAAAAAAAAAAA";
				_expected = "AAAAAAAAAAAAAAAAAAAAA";
				_received = _obj.uncompress(toUncompress); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

    // END CUT HERE

