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
    int N ,W;
    cin >> N >> W;
    vint v(N),w(N);
    rep(i,N) cin >> v[i] >> w[i];
    vvi dp(N+1, vector<int>(W+1,-1));
    dp[0][0]=0;
    rep(i,N+1) dp[i][0] = 0;
    rep(i,N){
        rep(j,W+1){
            dp[i+1][j]=dp[i][j];
            if(j-w[i]<0)continue;
            chmax(dp[i+1][j],dp[i][j-w[i]]+v[i]);
            if(dp[i+1][j-w[i]] == -1)continue;
            chmax(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);


            
        }
    }
    int ans=0;
    rep(i,N+1){
        rep(j,W+1){
            if(dp[i][j]==INF)continue;
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;

    

    return 0;
}
