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
#define MAX 55
#define SZ(x) (int)x.size()
#define paii pair<int,int>
#define oo (1<<25)

char mat[MAX][MAX][MAX];
//int dp[MAX][MAX][MAX];
int pt[MAX][MAX][MAX];

using namespace std;

int n;

int rec(int i,int j,int k)
{
//    cout<<i<<" "<<j<<" "<<k<<"   "<<mat[i][j][k]<<endl;
    if(i==j && j==k && j==n-1 )
    {
        string str;
        while(i>=0 && j>=0 && k>=0)
        {
            str+=mat[i][j][k];
            if(pt[i][j][k]==0) i--;
            else if(pt[i][j][k]==1) j--;
            else if(pt[i][j][k]==2) k--;
        }
        reverse(str.begin(),str.end());
//        cout<<str<<endl;
        stack<char>s;char val;

        for(int q=0;q<SZ(str);q++)
        {
            if(str[q]=='(' || str[q]==')')
            {
                if(!s.empty())
                {
                    if(s.top() +1 == str[q]) {s.pop();continue;}
                    else s.push(str[q]);
                }
                else s.push(str[q]);
            }
        }

        if(s.empty()) {/*cout<<"ret "<<1<<endl;*/return 1;}
        else {/*cout<<"ret  "<<0<<endl;*/return 0;}
    }

//    int &ret=dp[i][j][k];
//    if(ret!=-1) return ret;
    int ret;
    ret=0;
    if(i<n-1)
    {
        if(ret==-1) return ret;
        if(ret>=1000000000L) {ret=-1;return ret;}
        pt[i+1][j][k]=0;
        ret+=rec(i+1,j,k);
        if(ret>=1000000000L) {ret=-1;return ret;}
    }

    if(ret==-1) return ret;
    if(ret>=1000000000L) {ret=-1;return ret;}

    if(j<n-1)
    {
        pt[i][j+1][k]=1;
        ret+=rec(i,j+1,k);
    }

    if(ret==-1) return ret;
    if(ret>=1000000000L) {ret=-1;return ret;}

    if(k<n-1)
    {
        pt[i][j][k+1]=2;
        ret+=rec(i,j,k+1);
    }

    if(ret>=1000000000L) ret=-1;
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
    n=N;
//    mem(dp,-1);
    int ans=rec(0,0,0);
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
		int T = time(NULL)-1309346259;
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

