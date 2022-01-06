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
#define all(x) x.begin(),x.end()
#define mp make_pair
#define MAX 100
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)


using namespace std;

bool mtch(char A,char B)
{
    if(A=='R' && B=='S') return true;
    if(A=='P' && B=='R') return true;
    if(A=='S' && B=='P') return true;
    return false;
}
int pt(string s1,string s2)
{
    if( mtch(s1[1],s2[1]) )
    {
        if(mtch(s1[0],s2[0])) return 2;
        if(s1[0]==s2[0]) return 1;
        else return 0;
    }
    else return 0;
}
bool com(pair<int,paii>a, pair<int,paii>b)
{
    if( a.second.second>b.second.second ) return true;
    else return false;
}
class DoubleRoshambo
 {
public:
int maxScore(vector <string> A, vector <string> E)
{
    map<int,int>M_item,M_A;
    int mx_pt=0,pts,indx;
    vector<pair<int,paii> >v;
    paii p;
    pair<int,paii>PP;
//    string tmp1(2,'0'),tmp2(2,'0');
    for(int i=0;i<SZ(A);i++)
    {
        pts=0;PP.first=i;
        for(int j=0;j<SZ(E);j++)
        {
            p.first=j;
            p.second=pt(A[i],E[j]);
            PP.second=p;
            v.pb(PP);
        }
    }
    sort(all(v),com);
//    for(int i=0;i<SZ(v);i++)  print3(v[i].first,v[i].second.first,v[i].second.second);

//    for(int j=0;j<SZ(v[i]);j++) print3(i,v[i][j].first,v[i][j].second);
    for(int i=0;i<SZ(v);i++)
    {
        if(M_item.find(v[i].second.first)==M_item.end() && M_A.find(v[i].first)==M_A.end() )
        {
            M_item[v[i].second.first]=1;
            M_A[v[i].first]=1;
            mx_pt+=v[i].second.second;
        }
    }
    return mx_pt;
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
		cout << "Testing DoubleRoshambo (1024.0 points)" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1310646871;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1024.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		_tc++;
		DoubleRoshambo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A[] = {"RR"};
				string E[] = {"SS"};
				_expected = 2;
				_received = _obj.maxScore(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(E, E+sizeof(E)/sizeof(string))); break;
			}
			case 1:
			{
				string A[] = {"SR", "PP"};
				string E[] = {"PR", "RS"};
				_expected = 1;
				_received = _obj.maxScore(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(E, E+sizeof(E)/sizeof(string))); break;
			}
			case 2:
			{
				string A[] = {"PP", "PP", "PP", "PP"};
				string E[] = {"RR", "PR", "SS", "SP"};
				_expected = 3;
				_received = _obj.maxScore(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(E, E+sizeof(E)/sizeof(string))); break;
			}
			case 3:
			{
				string A[] = {"PS", "RS", "PP", "SP", "RR", "SS", "SP"};
				string E[] = {"RP", "SP", "RR", "SR", "RS", "SP", "SS"};
				_expected = 10;
				_received = _obj.maxScore(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(E, E+sizeof(E)/sizeof(string))); break;
			}
			case 4:
			{
				string A[] = {"RS", "PS"};
				string E[] = {"RP", "PS"};
				_expected = 2;
				_received = _obj.maxScore(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(E, E+sizeof(E)/sizeof(string))); break;
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

