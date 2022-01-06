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

int rrr[]={1,1,-1,-1,2,-2,2,-2 };int ccc[]={2,-2,2,-2,1,1,-1,-1};
int dst_x,dst_y;
vector<int>jt;

bool bfs(int x_cor,int y_cor)
{

    int row,col,i,p,q,v1,v2,d;
    queue<int>Q;
    map<paii,bool>M;

    Q.push(x_cor);
    Q.push(y_cor);
    M[mp(x_cor,y_cor)]=1;

    while(!Q.empty())
    {
        row=Q.front();Q.pop();
        col=Q.front();Q.pop();
        for(i=0;i<8;i++)
        {
            for(int j=0;j<SZ(jt);j++)
            {
                d=jt[j];
                if( abs(rrr[i])==1 )
                    v1=rrr[i]*d;
                 else if( abs(rrr[i])==2 )
                 {
                     if(rrr[i]==2) v1=1;
                     else v1=-1;
                 }

                if( abs(ccc[i])==1 )
                    v2=ccc[i]*d;
                 else if( abs(ccc[i])==2 )
                 {
                     if(ccc[i]==2) v2=1;
                     else v2=-1;
                 }


                p=row+v1;
                q=col+v2;
                if( M.find(mp(p,q))==M.end() && p<=1000000000 && p>=-1000000000 && q<=1000000000 && q>=-1000000000 )
                {
                    Q.push(p);
                    Q.push(q);
                    M[mp(p,q)]=1;
                    if(p==dst_x && q==dst_y) return true;
                }
            }
        }
    }
    return false;

}
class MagicalGirlLevelOneDivOne
 {
public:
string isReachable(vector <int> jumpTypes, int x, int y)
{
    int chk=0;
    if(x==0 && y==0) return "YES";
    dst_x=x;dst_y=y;
    jt=jumpTypes;
    chk=bfs(0,0);

    if(chk) return "YES";
    else return "NO";
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
		cout << "Testing MagicalGirlLevelOneDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 4; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1312954579;
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
		MagicalGirlLevelOneDivOne _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int jumpTypes[] = {2};
				int x = 5;
				int y = 4;
				_expected = "YES";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}
			case 1:
			{
				int jumpTypes[] = {3};
				int x = 5;
				int y = 4;
				_expected = "NO";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}
			case 2:
			{
				int jumpTypes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				int x = 1000000000;
				int y = -999999999;
				_expected = "YES";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}
			case 3:
			{
				int jumpTypes[] = {999999999};
				int x = 999999999;
				int y = 0;
				_expected = "NO";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
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

