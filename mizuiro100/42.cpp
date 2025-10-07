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
    int N,M;
    cin >> N >> M;
    vint D(N),C(M);
    rep(i,N) cin >> D[i];
    rep(i,M) cin >> C[i];
    vvi dp(M+1,vint(N+1,INF));
    rep(i,M+1)dp[i][0] = 0;
    rep(i,M) {
        rep(j,N) {
            if(dp[i][j]!= INF) {
                dp[i+1][j+1]=dp[i][j]+D[j]*C[i];
            }
            if(dp[i][j+1]!= INF) {
                chmin(dp[i+1][j+1],dp[i][j+1]);
            }
        }
    }
    int ans = INF;
    rep(i,M+1) {
        chmin(ans,dp[i][N]);
    }
    cout<<dp[M][N]<<endl;

    

    return 0;
}
