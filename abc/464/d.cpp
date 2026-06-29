#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
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

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vll x(n),y(n-1);
    rep(i,n)cin>>x[i];
    rep(i,n-1)cin>>y[i];
    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    vector<char>c={'S','R'};
    rep(i,n){
        rep(j,2){
            ll cost =0;
            if(s[i]!=c[j])cost=x[i];
            ll t=0;
            if(i>0)t=y[i-1];
            if(c[j]=='S'){
                dp[i+1][j]=max(dp[i][0],dp[i][1]+t)-cost;
            }
            else{
                dp[i+1][j]=max(dp[i][0],dp[i][1])-cost;
            }
            
        }
    }
    rep(i,n+1){
        // printv(dp[i])
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
}

int main()
{
    int t;
    cin>>t;
    rep(i,t)solve();
    

    return 0;
}
