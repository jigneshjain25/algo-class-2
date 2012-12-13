//{
//{
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include <list>
#include <queue>
#include <cassert>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <fstream>
//}

using namespace std;
typedef vector<int> VI;
typedef long long LL;
typedef pair<int, int > PII;

#define pb push_back

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

#define debug(args...)      {dbg,args; cout<<endl;}
struct debugger
{
  template<typename T> debugger& operator , (const T& v)
  {
    cout<<v<<" ";
    return *this;
  }
} dbg;

//}

int main(){
    ifstream fin("jobs.txt");
    int w[10001],l[10001],n,t1,t2,count=0;
    float t;
    fin>>n;
    while(1)
    {
        if(fin.eof())break;
        fin>>w[count]>>l[count];

        count++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            float one =float(w[i])/float(l[i]);
            float two =float(w[j])/float(l[j]);
            if(one<two)
            {
                t1=w[i];
                w[i]=w[j];
                w[j]=t1;

                t1=l[i];
                l[i]=l[j];
                l[j]=t1;


            }

        }
    }

    unsigned long long ans=0;
    int lo=0;
    for(int i=0;i<n;i++)
        {
            lo+=l[i];
            ans+=w[i]*lo;
        }
        cout<<ans;



}
