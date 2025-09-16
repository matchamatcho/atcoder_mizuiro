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
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
ll mod=1e9+7;
int main()
{
    ll n,q;
    cin>>n>>q;
    vll a(n),c(q);
    rep(i,n)cin>>a[i];
    rep(i,q)cin>>c[i];
    vll sa;
    sa.push_back(0);
    rep(i,n-1){
        sa.push_back(modpow(a[i],a[i+1],mod));

    }
    // printv(sa)

    rep(i,n-1){
        sa[i+1]=(sa[i+1]+sa[i])%mod;
    }
    // printv(sa)
    ll ans=0;
    ans=ans+sa[c[0]-1]-sa[0];
    // cout<<ans<<endl;
    rep(i,q-1){
        ans=ans+sa[max(c[i+1],c[i])-1]-sa[min(c[i],c[i+1])-1];
        ans=(ans+mod)%mod;
        // cout<<ans<<endl;

    }
    
    ans=(ans+mod)%mod;
    ans=ans+sa[c[q-1]-1]-sa[0];
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
    
    

    return 0;
}
