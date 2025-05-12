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
    while(1){
        int N,M;
        cin >> N >> M;
        if(N==0&&M==0)break;
        vint C(M),x(N);
        rep(i,M) cin >> C[i];
        rep(i,N) cin >> x[i];
        vvi dp(256,vint(256,INF));
        rep(i,256)dp[i][i]=0;
        rep(i,N){//de-ta
            vvi old(256,vint(256,INF));
            swap(dp,old);
            rep(j,256){//shokiti
                if(j!=128)continue;
                rep(k,256){//imanoatai
                    if(old[j][k]==INF)continue;
                    rep(l,M){
                        int next=k+C[l];
                        if(next>255)next=255;
                        if(next<0)next=0;
                        chmin(dp[j][next],old[j][k]+(x[i]-next)*(x[i]-next));
                        if(dp[j][next]==0&&0){cout <<i<<" "<< j << " " << k << " " <<l<<" "<< next << " " << dp[j][next] << endl;
                        return 0;}
                    }
                }
                // printv(dp[j]);
            }
        }
        // break;
        int ans=INF;
        rep(i,256){
            rep(j,256){
                chmin(ans,dp[i][j]);
            }
        }
        cout << ans << endl;

    }
    
    

    return 0;
}
