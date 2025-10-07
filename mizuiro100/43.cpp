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
    int N;
    cin >> N;
    vstr S(5);
    rep(i, 5) cin >> S[i];
    vvi dp(N,vint(3,INF));
    //{RBW012}
    dp[0][1]=dp[0][2]=dp[0][0]=0;
    rep(i,5){
        if(S[i][0]!='R')dp[0][0]++;
    }
    rep(i,5){
        if(S[i][0]!='B')dp[0][1]++;
    }
    rep(i,5){
        if(S[i][0]!='W')dp[0][2]++;
    }
    vvi cnt(N,vint(3,0));
    rep(i,5)rep(j,N){
        if(S[i][j]=='R')cnt[j][0]++;
        if(S[i][j]=='B')cnt[j][1]++;
        if(S[i][j]=='W')cnt[j][2]++;
    }
    Rep(i,1,N){
        rep(j,3){
            rep(k,3){
                if(j==k)continue;
                dp[i][j]=min(dp[i-1][k]+5-cnt[i][j],dp[i][j]);
            }
        }
      
    }
    int ans=INF;
    rep(i,3){
        ans=min(ans,dp[N-1][i]);
    }
    cout << ans << endl;
    return 0;
}
