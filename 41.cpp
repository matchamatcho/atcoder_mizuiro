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
    int N,D;
    cin >>D >> N;
    vint d(D);
    rep(i,D) cin >> d[i];
    vint a(N),b(N),c(N);
    rep(i,N) cin >> a[i] >> b[i] >> c[i];
    vvi dp(D,vint(N,-1));
    rep(i,N){
        if(a[i]<=d[0] && d[0]<=b[i]){
            dp[0][i]=0;
        }

    }
    // printv(dp[0]);
    for(int i=1;i<D;++i){
        rep(j,N){
            if(a[j]<=d[i] && d[i]<=b[j]){
                rep(k,N){
                    if(dp[i-1][k]!=-1){
                        dp[i][j]=max(dp[i-1][k]+abs(c[j]-c[k]),dp[i][j]);
                    }
                }
            }
        }
        // printv(dp[i]);
    }
    int ans=0;
    rep(i,N){
        chmax(ans,dp[D-1][i]);
    }
    cout << ans << endl;


    return 0;
}
