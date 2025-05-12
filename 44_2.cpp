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
    vint table;
    for(int i=1;i*(1+i)*(2+i)/6<1e6;++i){
        table.push_back(i*(1+i)*(2+i)/6);
    }
    vint dp(1e6+1,INF),dp2(1e6+1,INF);
    rep(i,1e6)dp[i]=i;
    rep(i,1e6)dp2[i]=i;
    for(int i = 1; i*(1+i)*(2+i)/6<1e6;++i){
        vint old=dp,old2=dp2;
        for(int j=1;j<1e6;++j){
            if(j-table[i]>=0){
                dp[j]=min(old[j],dp[j-table[i]]+1);
                if(table[i]&1)dp2[j]=min(old2[j],dp2[j-table[i]]+1);
            }
        }
    }
    while(1){
        int N;
        cin >> N;
        if(N==0)break;
        cout << dp[N] << " " << dp2[N] << endl;
    }

    return 0;
}
