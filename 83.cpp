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
    ll n,m;
    cin>>n>>m;
    vll p(m);
    rep(i,m)cin>>p[i];
    vll a(n-1),b(n-1),c(n-1);
    rep(i,n-1)cin>>a[i]>>b[i]>>c[i];
    vll num(n);
    rep(i,m-1){
        num[min(p[i],p[i+1])-1]++;
        num[max(p[i],p[i+1])-1]--;

    }

    rep(i,n-1)num[i+1]+=num[i];
    ll ans=0;
    // printv(num);
    rep(i,n-1){
        ll useA=num[i]*a[i];
        ll useB=num[i]*b[i]+c[i];
        ans+=min(useA,useB);
        // cout<<useA<<" "<<useB<<endl;

    }
    cout<<ans<<endl;
    

    return 0;
}
