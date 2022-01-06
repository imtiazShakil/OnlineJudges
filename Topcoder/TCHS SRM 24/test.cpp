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

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define MAX 1000
#define mem(a,b) memset(a,b,sizeof a)

using namespace std;

int main(void)
{
    map<int,int>M;
    M[-10]=1;
    M[20]=2;M[-3]=4;M[-50]=0;
    for(map<int,int>::iterator I=M.begin();I!=M.end();I++)
        cout<<I->first<<" "<<I->second<<endl;
}
