#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define _USE_MATH_DEFINES  // exposes constants, eg. M_PI
#define S(n)                scanf("%d",&n)
#define SLL(n)              scanf("%lld",&n)
#define SD(n)               scanf("%lf",&n)
#define SS(n)               scanf("%s",n)
#define INF                 INT_MAX
#define LINF                LLONG_MAX
#define EPS                 std::numeric_limits<double>::epsilon()
#define ABS(x)              ((x)<0?-(x):(x))
#define FOR(i,a,b)          for(int i=a;i<b;++i)
#define RFOR(i,a,b)         for(int i=(a)-1,_b(b);i>=_b;--i)
#define REP(i,n)            for(int (i)=0;(i)<(int)(n);++(i))
#define RREP(i,n)           for(int (i)=n;(i)>=(int)0;--(i))
#define DREP(a)             sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)      (lower_bound(all(arr),ind)-arr.begin())
#define FOREACH(c,itr)      for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define mp                  make_pair
#define pb                  push_back
#define tri(a,b,c)          mp(a,mp(b,c))
#define fst                 first
#define snd                 second
//#define FILL(a,v)           memset(a,v,sizeof(a))
#define SQT(a)              ((a)*(a))
//#define MAX(a,b)            ((a)>(b)?(a):(b))
//#define MIN(a,b)            ((a)<(b)?(a):(b))
#define ALL(x)              x.begin(),x.end()
#define SZ(v)               ((int)(v.size()))
#define LOG(a)              (cerr<<"\tline#"<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(args...)      {cerr<<"\tcase#"<<(cc+1)<<": ";dbg,args;cerr<<endl;}
struct debugger {
    template<typename T> debugger& operator, (const T& v) {
        std::cerr << v << " ";
        return *this;
    }
} dbg;
typedef long long       LL;
typedef long long       ll;
typedef unsigned long long ULL;
typedef unsigned int    uint;
typedef std::pair<int, int>  PII;
typedef std::pair<LL, LL>    PLL;
typedef std::pair<int, PII>  TRI;
typedef std::vector<int>     VI;
typedef std::vector<LL>      VL;
typedef std::vector<std::string>  VS;
typedef std::vector<PII>     VII;
typedef std::vector<PLL>     VLL;
typedef std::vector<TRI>     VT;
typedef std::vector<VI>      VVI;
typedef std::vector<VL>      VVL;
typedef std::vector<VII>     VVII;
typedef std::vector<VLL>     VVLL;
typedef std::vector<VT>      VVT;
typedef std::complex<double> pt;
typedef std::complex<LL>     pti;
const double PI   = M_PI;
template<class T> inline T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}
inline double round(double x)
{
    const double sd = 100; // accuracy = 2 dp
    return int(x * sd + (x < 0 ? -0.5 : 0.5)) / sd;
}
inline int cmp(double x, double y = 0, double tol = EPS)
{
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
template<typename T> inline void print(T *array, int size)
{
    printf("\tarray[] = [");

    for(int i = 0; i < size; ++i) {
        printf("%lld", (LL)array[i]);

        if(i < size - 1) printf(" ");
    }

    printf("]\n");
}
template<typename T> inline void print(T **array, int size1, int size2)
{
    printf("\tarray[][] = [");

    for(int i = 0; i < size1; ++i) {
        for(int j = 0; j < size2; ++j) {
            printf("%lld", (LL)array[i][j]);

            if(j < size2 - 1) printf(" ");
        }

        printf("]\n");
    }
}

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T> inline void write(T x)
{
    int i = 20;
    char buf[21];
    // buf[10] = 0;
    buf[20] = '\n';

    do
    {
        buf[--i] = x % 10 + '0';
        x/= 10;
    }while(x);
    do
    {
        putchar(buf[i]);
    } while (buf[i++] != '\n');
}

template <typename T> inline T readInt()
{
    T n=0,s=1;
    char p=getchar();
    if(p=='-')
        s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-')
        p=getchar();
    if(p=='-')
        s=-1,p=getchar();
    while(p>='0'&&p<='9') {
        n = (n<< 3) + (n<< 1) + (p - '0');
        p=getchar();
    }

    return n*s;
}

template<typename T,
        template <typename, typename = std::allocator<T>> class Container>
Container<T> splitString(const std::string & source) {
    std::stringstream ss(source);
    Container<T> cont{std::istream_iterator<T>(ss), std::istream_iterator<T>()};
    return cont;
}