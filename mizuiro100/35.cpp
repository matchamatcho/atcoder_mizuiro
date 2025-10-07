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
    int N,W;
    cin>>N>>W;
    vint v(N),w(N);
    rep(i,N){
        cin>>v[i]>>w[i];
    }
    vvi dp(N,vint(W+1,-1));
    rep(i,N){
        dp[i][0]=0;
    }
    rep(i,W+1){
        if(i==w[0]){
            dp[0][i]=v[0];
        }
    }
    for(int i=1;i<N;++i){
        rep(j,W+1){
            dp[i][j]=dp[i-1][j];
            if(j-w[i]<0)continue;
            if(dp[i-1][j-w[i]]!=-1)chmax(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    int ans=0;
    rep(i,W+1){
        chmax(ans,dp[N-1][i]);

    }
    // rep(i,N){
    //     rep(j,W+1){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans<<endl;
    

    return 0;
}
