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

map<string,int>M;
map<string,int>S;

class NetworkXOneTimePad
 {
public:
int crack(vector <string> plaintexts, vector <string> ciphertexts)
{
    M.clear();
    S.clear();
    string str;

    for(int i=0;i<SZ( plaintexts );i++ )
    {

        for(int j=0;j<SZ( ciphertexts ) ;j++)
        {
            str.clear();
            for(int p=0;p<SZ( plaintexts[0] );p++ )
            {
                if( plaintexts[i][p]==ciphertexts[j][p] ) str+='0';
                else str+='1';
            }
//            print1(str);
            M[str]=1;
        }

    }
    bool flag,flag2,fff;
    for(map<string,int>::iterator I=M.begin();I!=M.end();I++)
    {
        fff=1;
        for(int i=0;i<SZ( ciphertexts ) ;i++)
        {
            flag=0;
            for(int j=0;j<SZ( plaintexts );j++ )
            {
                flag2=1;
                for(int p=0;p<SZ( plaintexts[0]  );p++  )
                {
                    if( plaintexts[j][p]==ciphertexts[i][p]  && I->fs[p]=='1' ) {flag2=0;break;}
                    if( plaintexts[j][p]!=ciphertexts[i][p]  && I->fs[p]=='0' ) {flag2=0;break;}
                }
                if(flag2) {flag=1;break;}
            }
            if(flag==0) {fff=0;break;}
        }
        if(fff) S[I->fs]=1;
    }
    return SZ(S);
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
		cout << "Testing NetworkXOneTimePad (500.0 points)" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1314718441;
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
		NetworkXOneTimePad _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			//case 0:
			{
				string plaintexts[] = {"110", "001"};
				string ciphertexts[] = {"101", "010"};
				_expected = 2;
				_received = _obj.crack(vector <string>(plaintexts, plaintexts+sizeof(plaintexts)/sizeof(string)), vector <string>(ciphertexts, ciphertexts+sizeof(ciphertexts)/sizeof(string))); break;
			}
			//case 1:
			{
				string plaintexts[] = {"00" , "01", "10", "11"};
				string ciphertexts[] = {"00" , "01", "10", "11"};
				_expected = 4;
				_received = _obj.crack(vector <string>(plaintexts, plaintexts+sizeof(plaintexts)/sizeof(string)), vector <string>(ciphertexts, ciphertexts+sizeof(ciphertexts)/sizeof(string))); break;
			}
			//case 2:
			{
				string plaintexts[] = {"01", "10"};
				string ciphertexts[] = {"00"};
				_expected = 2;
				_received = _obj.crack(vector <string>(plaintexts, plaintexts+sizeof(plaintexts)/sizeof(string)), vector <string>(ciphertexts, ciphertexts+sizeof(ciphertexts)/sizeof(string))); break;
			}
			case 3:
			{
			    string plaintexts[] =  {"11101010000", "00111111011", "00011100000", "01000111000", "00000001000", "00010100100", "11011111100", "11001110111", "11100001101", "00010101011", "00000110001", "11101000001", "00001001101", "11110101101", "10001000100", "01010001011", "01001001011", "00011001001", "01011100001", "01011010101"} ;
//				string plaintexts[] = {"000", "111", "010", "101", "110", "001"};
				string ciphertexts[] = {"10011001110", "00101110001", "00010000010", "11111001011", "00010111011", "11011111101", "11111011010", "11100100111", "11110000111", "01001101011", "00000101110", "00000100001", "01000000001", "00011000111"};
				_expected = 1;
				_received = _obj.crack(vector <string>(plaintexts, plaintexts+sizeof(plaintexts)/sizeof(string)), vector <string>(ciphertexts, ciphertexts+sizeof(ciphertexts)/sizeof(string))); break;
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

