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
    int n,m;
    cin>>n>>m;
    vint s(n-1);
    rep(i,n-1)cin>>s[i];
    vint a(m);
    rep(i,m)cin>>a[i];
    vint ss={0};
    rep(i,n-1)ss.push_back((ss.back()+s[i])%100000);
    int now=0;
    int ans=0;
    rep(i,m){
        // cout<<now<<" "<<now+a[i]<<endl;
        ans+=ss[max(now,now+a[i])]-ss[min(now+a[i],now)];
        ans%=100000;
        now+=a[i];

    }
    cout<<ans<<endl;

    

    return 0;
}
