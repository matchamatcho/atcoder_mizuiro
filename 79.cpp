//出来てない
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
    int n,m,Q;
    cin>>n>>m>>Q;
    vll l(m),r(m);
    rep(i,m)cin>>l[i]>>r[i];
    vll p(Q),q(Q);
    rep(i,Q)cin>>p[i]>>q[i];
    vll s(n+1);
    vll st(n+1),ed(n+1);

    rep(i,m){
        for(int j=l[i];j<=r[i];j++)s[j]++;
        st[l[i]]++;
        ed[r[i]]++;
    }
    rep(i,n) st[i+1] += st[i];
    rep(i,n) ed[i+1] += ed[i];
    // printv(s);
    rep(i,n) s[i+1] += s[i];
    // printv(s);
    printv(st);
    printv(ed);
    rep(i,Q){
        
    }
    
    

    return 0;
}
