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

using namespace std;

struct data
{
    int th_skl,prac_skl,expire,indx;
} ;
vector<data>v;
int prc_skl,th_skl,mon;

bool com(data a ,data b)
{
    if(a.expire<=mon && b.expire>mon) return false;
    if(a.expire>mon && b.expire<=mon) return true;
    if(a.expire<=mon && b.expire<=mon) return true;

    int diff1_prc=a.prac_skl-prc_skl;
    int diff2_prc=b.prac_skl-prc_skl;
    int diff3_th=a.th_skl-th_skl;
    int diff4_th=b.th_skl-th_skl;

    bool valid1=0,valid2=0;
//    if( (diff1_prc>=0 && diff1_prc<=1) || (diff3_th>=0  && diff3_th<=1 ) ) valid1=1;
//    if( (diff2_prc>=0 && diff2_prc<=1) ||  (diff4_th>=0  && diff4_th<=1 ) ) valid2=1;

    if( ( diff1_prc<=1) && ( diff3_th<=1 ) ) valid1=1;
    if( ( diff2_prc<=1) &&  (diff4_th<=1 ) ) valid2=1;

//    cout<<"ind "<<a.indx<<" val "<<valid1<<" ind "<<b.indx<< "  val "<<valid2<<endl;
    if(valid1 && valid2==0 ) return true;
    else if(valid1==0 && valid2 ) return false;
    else if(valid1==0 && valid2==0 ) return true;
    else if(valid1 && valid2 )
    {
        if(a.expire<b.expire) return true;
        else if(b.expire<a.expire) return false;
        else if(a.expire==b.expire)
        {
            int max1=max(diff1_prc,0) + max(diff3_th,0);
            int max2=max(diff2_prc,0) + max(diff4_th,0);
    //        cout<<max1<<" "<<max2<<endl;
            if(max1>max2) return true;
            else if(max2>max1)return false;
            else if(max1==max2)
            {
                if(a.indx<b.indx) return true;
                else    return false;
            }
        }
    }

}
class CsCourses
{
public:
	vector <int> getOrder(vector <int> theoreticalValue, vector <int> practicalValue, vector <int> expire, int skillBound)
	{

        v.clear();
        vector<int>seq;seq.clear();
        prc_skl=0;th_skl=0;mon=0;
        data tmp;
        map<int,int>M;M.clear();
        for(int i=0;i<(int)theoreticalValue.size() ;i++)
        {
            tmp.th_skl=theoreticalValue[i];
            tmp.prac_skl=practicalValue[i];
            tmp.expire=expire[i];
            tmp.indx=i;
            v.push_back(tmp);
        }
        int diff1_prc,diff1_th;

	    while(prc_skl<skillBound || th_skl<skillBound)
	    {
//	        puts("sort");
            sort(v.begin(),v.end(),com);
            puts("");
            for(int p=0;p<(int)v.size();p++)
            {
                cout<<v[p].indx<<" th "<<v[p].th_skl<<"  prc "<<v[p].prac_skl<<" exp "<<v[p].expire<<endl;
            }
            bool flag=0;
            for(int p=0;p<(int)v.size();p++)
            {
                if(M.find(v[p].indx)==M.end())
                {
                    tmp=v[p];
                    M[v[p].indx]++;
                    flag=1;
                    break;
                }
            }
//            cout<<tmp.indx<<endl;
            if(!flag) break;
//            tmp=v[0];
            diff1_prc=tmp.prac_skl-prc_skl;
            diff1_th=tmp.th_skl-th_skl;

            if( tmp.expire<=mon ) break;
            else
            {
//                if( (diff1_prc<0 || diff1_prc>1 ) || diff1_th<0 || diff1_th>1 ) break;
                if( (diff1_prc>1 ) || diff1_th>1 ) break;
                prc_skl=max(prc_skl, tmp.prac_skl);
                th_skl=max(th_skl, tmp.th_skl);
                mon++;
                seq.push_back(tmp.indx);
            }
            cout<<"th skl "<<th_skl<<"  prc skl "<<prc_skl<<endl;
	    }
	    vector<int>blank;blank.clear();
	    if(prc_skl<skillBound || th_skl<skillBound) return blank;
	    return seq;
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

	CsCourses objectCsCourses;

////////////	//test case0
	vector <int> param00;
	param00.push_back(0);
	param00.push_back(2);
	param00.push_back(1);
	vector <int> param01;
	param01.push_back(1);
	param01.push_back(1);
	param01.push_back(1);
	vector <int> param02;
	param02.push_back(2);
	param02.push_back(3);
	param02.push_back(3);
	int param03 = 1;
	vector <int> ret0 = objectCsCourses.getOrder(param00,param01,param02,param03);
	vector <int> need0;
	need0.push_back(2);
	assert_eq(0,ret0,need0);

////////	//test case1
	vector <int> param10;
	param10.push_back(1);
	param10.push_back(2);
	param10.push_back(1);
	vector <int> param11;
	param11.push_back(2);
	param11.push_back(1);
	param11.push_back(1);
	vector <int> param12;
	param12.push_back(5);
	param12.push_back(5);
	param12.push_back(5);
	int param13 = 2;
	vector <int> ret1 = objectCsCourses.getOrder(param10,param11,param12,param13);
	vector <int> need1;
	need1.push_back(2);
	need1.push_back(0);
	need1.push_back(1);
	assert_eq(1,ret1,need1);

//////////	//test case2
//	vector <int> param20;
//	param20.push_back(1);
//	param20.push_back(2);
//	param20.push_back(1);
//	vector <int> param21;
//	param21.push_back(2);
//	param21.push_back(1);
//	param21.push_back(1);
//	vector <int> param22;
//	param22.push_back(1);
//	param22.push_back(1);
//	param22.push_back(1);
//	int param23 = 2;
//	vector <int> ret2 = objectCsCourses.getOrder(param20,param21,param22,param23);
//	vector <int> need2;
//	assert_eq(2,ret2,need2);
//
////////	//test case3
//	vector <int> param30;
//	param30.push_back(1);
//	param30.push_back(2);
//	param30.push_back(1);
//	vector <int> param31;
//	param31.push_back(2);
//	param31.push_back(1);
//	param31.push_back(1);
//	vector <int> param32;
//	param32.push_back(3);
//	param32.push_back(2);
//	param32.push_back(1);
//	int param33 = 2;
//	vector <int> ret3 = objectCsCourses.getOrder(param30,param31,param32,param33);
//	vector <int> need3;
//	need3.push_back(2);
//	need3.push_back(1);
//	need3.push_back(0);
//	assert_eq(3,ret3,need3);
////
//////	//test case4
//	vector <int> param40;
//	param40.push_back(1);
//	param40.push_back(2);
//	param40.push_back(3);
//	param40.push_back(4);
//	param40.push_back(5);
//	param40.push_back(6);
//	param40.push_back(7);
//	vector <int> param41;
//	param41.push_back(1);
//	param41.push_back(2);
//	param41.push_back(3);
//	param41.push_back(4);
//	param41.push_back(5);
//	param41.push_back(6);
//	param41.push_back(7);
//	vector <int> param42;
//	param42.push_back(1);
//	param42.push_back(2);
//	param42.push_back(3);
//	param42.push_back(4);
//	param42.push_back(5);
//	param42.push_back(6);
//	param42.push_back(7);
//	int param43 = 7;
//	vector <int> ret4 = objectCsCourses.getOrder(param40,param41,param42,param43);
//	vector <int> need4;
//	need4.push_back(0);
//	need4.push_back(1);
//	need4.push_back(2);
//	need4.push_back(3);
//	need4.push_back(4);
//	need4.push_back(5);
//	need4.push_back(6);
//	assert_eq(4,ret4,need4);
////
//////////	//test case5
//	vector <int> param50;
//	param50.push_back(0);
//	param50.push_back(1);
//	param50.push_back(2);
//	param50.push_back(2);
//	param50.push_back(1);
//	vector <int> param51;
//	param51.push_back(0);
//	param51.push_back(0);
//	param51.push_back(1);
//	param51.push_back(2);
//	param51.push_back(1);
//	vector <int> param52;
//	param52.push_back(9);
//	param52.push_back(9);
//	param52.push_back(9);
//	param52.push_back(9);
//	param52.push_back(9);
//	int param53 = 2;
//	vector <int> ret5 = objectCsCourses.getOrder(param50,param51,param52,param53);
//	vector <int> need5;
//	need5.push_back(4);
//	need5.push_back(3);
//	assert_eq(5,ret5,need5);

}

