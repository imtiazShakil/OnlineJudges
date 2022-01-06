#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

struct block
{
    int base,width,height;
};

int hit[200];
vector<block>v;
bool com(block a,block b)
{
    if(a.base!=b.base) {if( a.base>b.base ) return false;else  return true;}
    if(a.width!=b.width) {if( a.width>b.width ) return false;else  return true;}
    if( a.height>b.height ) return false;
    else  return true;
}

int gen()
{
    int i,j,mx=0;

    for(i=0;i<(int)v.size();i++)
    {
        hit[i]=0;
        for(j=i-1;j>=0;j--)
        {
            if( v[j].base<v[i].base && v[j].width<v[i].width   )
            {
                hit[i]=max(hit[i],hit[j]+v[i].height  );
            }
        }
        if(hit[i]==0) hit[i]=v[i].height;
        mx=max(mx,hit[i]);
    }
    return mx;

}

int main(void)
{
    int i,j,ans,cas=0,dim[3],n;
    int arr[]={0,1,2};
    block tmp;
    while(scanf("%d",&n)==1 && n)
    {
        v.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&dim[0],&dim[1],&dim[2]);
            tmp.base=dim[0];tmp.width=dim[1];tmp.height=dim[2];
            v.pb(tmp);
            while(next_permutation(arr,arr+3) )
            {
                tmp.base=dim[arr[0]];tmp.width=dim[arr[1]];tmp.height=dim[arr[2]];
                v.pb(tmp);
            }
        }
        sort(v.begin(),v.end(),com);
//        for(i=0;i<(int)v.size();i++) cout<<v[i].base<<" "<<v[i].width<<" "<<v[i].height<<endl;
        ans=gen();
        printf("Case %d: maximum height = %d\n",++cas,ans);
    }

    return 0;
}
