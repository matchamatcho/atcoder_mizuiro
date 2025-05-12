#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
// using mint = modint998244353;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll,ll>;
using vstr = vector<string>;
using vint = vector<int>;
using vvi = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
#define mkpr make_pair
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) (x).begin(),(x).end()
#define printv(x); for(auto now : x) cout << now << " "; cout << endl;
#define yes(q) cout << ((q) ? "Yes" : "No") << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF =1001001001;
const ll INFL = 4e18;


int main()
{
    vector<vector<double>> x={{1,2},{2,1},{0,-1},{-1,1},{2,3},{3,2}};
    vector<double>m1={2,1},m2={1,1},m11={0,0},m22={0,0};
    
    rep(i,6){
        double a=(x[i][0]-m1[0])*(x[i][0]-m1[0])+(x[i][1]-m1[1])*(x[i][1]-m1[1]);
        double b=(x[i][0]-m2[0])*(x[i][0]-m2[0])+(x[i][1]-m2[1])*(x[i][1]-m2[1]);

    }
    
    

    return 0;
}
