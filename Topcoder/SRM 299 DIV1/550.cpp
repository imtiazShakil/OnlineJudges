#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

#define mem(a,b) memset(a,b,sizeof a)
#define oo (1<<25)
#define MAX 2550

using namespace std;

string big;
int dp[MAX][MAX];
int pal[MAX][MAX];

//bool is_pal(string str)
//{
//    for(int i=0,j=(int)str.size()-1;i<(int)str.size()/2 ;i++,j-- )
//    {
//        if(str[i]!=str[j]) return false;
//    }
//    return true;
//
//}

int is_pal(int x,int y)
{
    if(x>y) return 1;
    int &ret=pal[x][y];
    if(ret!=-1) return ret;

    if(big[x]==big[y])
    {
        ret=is_pal(x+1,y-1);
    }
    else   ret=0;

    return ret;
}

int rec(int start,int end)
{
//    string str=big.substr(start,end-start +1);
//    string str;str.clear();
//    for(int i=start;i<=end;i++)
//    {
//        str+=big[i];
//    }

    if( is_pal(start,end) ) return 0;

    int &ret=dp[start][end];
    if(ret!=-1) return ret;

    ret=oo;
    for(int i=start;i<end;i++)
    {
        ret=min(ret,rec(start,i) + rec(i+1,end) + 1);
    }
    return ret;

}

class PalindromePartition
{
public:
	int partition(vector <string> s)
	{
	    big.clear();
        for(int i=0;i<(int)s.size();i++)
        {
            big+=s[i];
        }
        mem(dp,-1);mem(pal,-1);
        int ans=rec(0,(int)big.size()-1);
        return ans+1;
	}
};


template<typename T> void print( T a ) {
    cerr << a;
}

void print( long long a ) {
    cerr << a << "L";
}

void print( string a ) {
    cerr << '"' << a << '"';
}

template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}

template<typename T> void assert_eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

template<typename T> void assert_eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
void assert_eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

int main( int argc, char* argv[] )
{

	PalindromePartition objectPalindromePartition;

////////	//test case0
	vector <string> param00;
	param00.push_back("AAAA");
	int ret0 = objectPalindromePartition.partition(param00);
	int need0 = 1;
	assert_eq(0,ret0,need0);

////////	//test case1
	vector <string> param10;
	param10.push_back("ABCDEFGH");
	int ret1 = objectPalindromePartition.partition(param10);
	int need1 = 8;
	assert_eq(1,ret1,need1);
//
//////////	//test case2
	vector <string> param20;
	param20.push_back("QWERTY");
	param20.push_back("TREWQWERT");
	int ret2 = objectPalindromePartition.partition(param20);
	int need2 = 5;
	assert_eq(2,ret2,need2);

////////	//test case3
	vector <string> param30;
	param30.push_back("BBCDDECAECBDABADDCEBACCCBDCAABDBADD");
	int ret3 = objectPalindromePartition.partition(param30);
	int need3 = 22;
	assert_eq(3,ret3,need3);
//
////////	//test case4
//	vector <string> param40;
//	param40.push_back("GKTQWLBWOGQCGERTMYHENNMGUNCAIRFDTPGZFRSHTEAKUGBAIJ");
//	param40.push_back("BLMJJGQYQRRSASFRMRDCUSEVUJYUXGQEZKRLGKVCGFAFVGGPFA");
//	param40.push_back("TRRCIACXCMLWOUHJNZSKXYCBPUMNLMEMWBGWTWBAKUBWICDQCB");
//	param40.push_back("SMLRETHSDQQSYGWOOXERMRLXRPFZMPBINEFSFPOAHGQXXSTHBP");
//	param40.push_back("HYDRLSLYQSDKSHTRZRYBJNVMLVGBZBQVZKPZHUVGDQUKXCMNQL");
//	param40.push_back("UMKPXWCNCNUKJWFAGKKMUHHMWSCPYTGADEXMBLSGJIXOUNZYJS");
//	param40.push_back("UWLIUAUPILVXVTDKQBETPLVPSMSZMQBTBQKEKJTCFXEYPCULBZ");
//	param40.push_back("MSZVBLBVJAXRGFLJNYAUSJZBHIUVAODPOUJGNZNBFUOWTVSEBK");
//	param40.push_back("PVPNMRYZVVNXNYHYGXOHGFFZXHFGHBQPFFCOEEDHEHWRJVYMFB");
//	param40.push_back("HJYENRLFBEEPCGBWVNAUGCJPKYMRDHAHQGXMRMTCREYEUJIZDJ");
//	param40.push_back("PKATAIKXGVURLLNXAKQMOSDXTWHNKYICFSOAYIYOQCELIKPGVY");
//	param40.push_back("QEPXOVKMNUSILPOZFEYPZZEFYVTMIEKVGOVWSOFNWOUZLUBJVZ");
//	param40.push_back("YKGECOBOSBCQKLKDFYINFGXWGYDMSPLPAFKCDEVVLUDKEZKUUS");
//	param40.push_back("YFXORCWLCPCFNSFSXTPYYIENMINHWYSAYCMELEKBVVJKXLUWAZ");
//	param40.push_back("MIKDHLAEYYTMIVOMQLYLUJQAHERLBSYSIPNXGTMRNGITXKVVSN");
//	param40.push_back("FUAJSWGDITKRQVFSBRPAKPXGIOYESLRFOKEEZCDRRYIHYBXKYZ");
//	param40.push_back("YAHPHSREYWYPZBREMDIJOXYZKIOHSBRVCQKJPATIPIDQVISHFV");
//	param40.push_back("MIQRPJIVZFNUWRUDTNEKGHOSSSVAYMSBXPCMMCWZPQXKRNBXKP");
//	param40.push_back("DTERSIZDKVFWNVATGPVNXFQDXNMSVOCGBRXRZSCAIENECIAIBZ");
//	param40.push_back("EPLGCMGLAEGXMYENDYHQZOEEJLFCZVZIJPLXYHFCJGNABFHIYN");
//	param40.push_back("WDMVASMIOSUUFCSLDIWDQFBTZEDNUXTZUJHYNJYUACGQJKTJSU");
//	param40.push_back("MPBHUYYXXISSHJLTXYYLHLMJXUTBJDOWFFNLSPZWJAQYQEDZQW");
//	param40.push_back("EXGGAWFQHRWABGJMSNIYQAKYTOGJKWTSROARTBLOMNVRUZZYWD");
//	int ret4 = objectPalindromePartition.partition(param40);
//	int need4 = 1013;
//	assert_eq(4,ret4,need4);

}

