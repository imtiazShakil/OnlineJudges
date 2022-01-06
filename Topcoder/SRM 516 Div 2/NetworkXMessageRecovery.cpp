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

//vector<int>v[300];
//int v[300];
map<int,int>ind;
map<int,int>v[300];
int dgree[300];

class NetworkXMessageRecovery
 {
public:
string recover(vector <string> messages)
{
    for(int i=0;i<SZ( messages ) ;i++)
        for(int j=0;j<SZ( messages[i] );j++ )
        {
            ind[ messages[i][j] ]=1;
        }

    for(int i=0;i<SZ( messages ) ;i++)
    {
        for(int j=0;j<SZ( messages[i] ) -1 ;j++)
        {
            if( v[ messages[i][j] ].find( messages[i][j+1]  )==v[ messages[i][j] ].end() ) dgree[messages[i][j+1]]++;
            v[ messages[i][j] ][messages[i][j+1]]=1;

//            print2(messages[i][j],messages[i][j+1]);

//            ind[ messages[i][j+1] ]++;
        }
    }
//    int choice,ch_ind=oo;
//    for(map<int,int>::iterator it=ind.begin();it!=ind.end();it++)
//    {
//        if(it->sc< ch_ind) { choice=it->fs;ch_ind=it->sc;  }
//        if(it->sc== ch_ind )
//        {
//            if(it->fs < choice) choice=it->fs;
//        }
//    }
//
//    dfs(choice);
    int top;
    priority_queue< int, std::vector<int>, std::greater<int> >Q;

    for(map<int,int>::iterator it=ind.begin();it!=ind.end();it++)
    {
        if( dgree [it->fs] ==0 ) Q.push(it->fs);//printf("push %c\n",it->fs);}
    }
    string str;

    while(!Q.empty())
    {
        top=Q.top();Q.pop();
//        printf("top %c \n",top);
        str+= top ;

        for(map<int,int>::iterator I=v[top].begin();I!=v[top].end();I++ )
        {
            dgree[ I->fs ]--;
//            print3(I->fs,"  degree ",dgree[ I->fs ]);
            if( dgree[I->fs]<=0 ) Q.push(I->fs);
        }
    }
//    print1(str);
    return str;

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
		cout << "Testing NetworkXMessageRecovery (1000.0 points)" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1314719424;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		NetworkXMessageRecovery _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			//case 0:
			{
				string messages[] = {"acd", "bce"};
				_expected = "abcde";
				_received = _obj.recover(vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;
			}
			case 1:
			{
			    string messages[] = {"fn", "B", "f", "l", "EFs", "BG", "l", "f", "rz", "n"};
				_expected = "BEFGflnrsz";
				_received = _obj.recover(vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;

//				string messages[] = {"ed", "dc", "cb", "ba"};
//				_expected = "edcba";
//				_received = _obj.recover(vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;

			}
			//case 2:
			{
				string messages[] = {"Fox", "Ciel", "FoxCiel"};
				_expected = "FoxCiel";
				_received = _obj.recover(vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;
			}
			//case 3:
			{
				string messages[] = {"a", "A"};
				_expected = "Aa";
				_received = _obj.recover(vector <string>(messages, messages+sizeof(messages)/sizeof(string))); break;
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

