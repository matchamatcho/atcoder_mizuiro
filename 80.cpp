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
    int h ,w;
    ll k,v;
    cin>>h>>w>>k>>v;
    vvll a(h+1,vll(w+1));
    rep(i,h)rep(j,w)cin>>a[i+1][j+1];
    rep(i,h)rep(j,w+1)a[i+1][j]+=a[i][j];
    rep(i,h+1)rep(j,w)a[i][j+1]+=a[i][j];
    
    ll ans=0;
    rep(i,h)rep(j,w)Rep(ii,i+1,h+1)Rep(jj,j+1,w+1){
        ll sum=a[ii][jj]-a[ii][j]-a[i][jj]+a[i][j];
        sum+=(ll(ii-i)*(jj-j))*k;

        if(sum<=v)chmax(ans,ll(ii-i)*ll(jj-j));
    }
    cout<<ans<<endl;
    
    return 0;
}
