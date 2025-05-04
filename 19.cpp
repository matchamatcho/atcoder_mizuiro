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
    int D;
    cin>>D;
    int n,m;
    cin>>n>>m;
    vint d(n);
    rep(i,n-1)cin>>d[i+1];
    d.push_back(D);
    sort(d.begin(), d.end());
    vint k(m);
    rep(i,m)cin>>k[i];
    ll ans=0;
    rep(mi,m){
        int pos=upper_bound(d.begin(), d.end(),k[mi])-d.begin();
        ans+=min(k[mi]-d[pos-1],d[pos]-k[mi]);


    }
    cout<<ans<<endl;
    

    return 0;
}
