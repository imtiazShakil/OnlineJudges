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
#define MAX 15
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)


using namespace std;

int dp[MAX][MAX][MAX][MAX*MAX*MAX];
char mat[MAX][MAX][MAX];
int n;
int lm=1000000000;

///this is a classical example of how to check parenthesis balance
///we used int x in our recursion
///which adds 1 if we find '(' in str
///And minus 1 if we find ')' in str
///if value of x==0 then this is valid
///otherwise not valid


ll rec(int i,int j,int k,int x)
{
    if(i>n || j>n || k>n ) return 0;
    if(x<0) return 0;
    if(i==n && j==n && k==n)
    {
        if(x<0) return 0;
        if(mat[i][j][k]==')') x--;
        else if(mat[i][j][k]=='(') x++;
        if(x) return 0;
        else return 1;
    }
    int &ret=dp[i][j][k][x];
    if(ret!=-1) return ret;
    ret=0;

    if(mat[i][j][k]==')') x--;
    else if(mat[i][j][k]=='(') x++;

    ret+=rec(i+1,j,k,x);if(ret>lm ) {ret=lm+1;return ret;}
    ret+=rec(i,j+1,k,x);if(ret>lm ) {ret=lm+1;return ret;}
    ret+=rec(i,j,k+1,x);if(ret>lm ) {ret=lm+1;return ret;}



    return ret;

}
class BracketMaze
 {
public:
int properPaths(vector <string> maze, int N)
{
    int p=0,q=0,r=0;
    for(int i=0;i<SZ(maze);i++)
    {
        for(int j=0;j<SZ(maze[i]);j++ )
        {
           mat[p][q][r]=maze[i][j];
           r++;
           if(r==N)
           {
               r=0;q++;
               if(q==N)
               {
                   q=0;
                   p++;
               }
           }
        }
    }
    n=N-1;
    mem(dp,-1);


    int ans=rec(0,0,0,0);
    if(ans>lm) return -1;
    return ans;

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
		cout << "Testing BracketMaze (900.0 points)" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1309360902;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BracketMaze _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string maze[] = {"()()()()"};
				int N = 2;
				_expected = 2;
				_received = _obj.properPaths(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), N); break;
			}
			case 1:
			{
				string maze[] = {")()()()("};
				int N = 2;
				_expected = 0;
				_received = _obj.properPaths(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), N); break;
			}
			case 2:
			{
				string maze[] = { "..........................." };
				int N = 3;
				_expected = 90;
				_received = _obj.properPaths(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), N); break;
			}
			case 3:
			{
				string maze[] = {"..(....)"};
				int N = 2;
				_expected = 2;
				_received = _obj.properPaths(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), N); break;
			}
			case 4:
			{
				string maze[] = { "(.........................)"};
				int N = 3;
				_expected = 90;
				_received = _obj.properPaths(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), N); break;
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

