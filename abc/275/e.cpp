#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
#define Yes(q) cout << ((q) ? "Yes" : "No") << endl;
#define priv(value) print_variable(#value, value)
// 汎用的な表示関数テンプレート
// どんな型 T の変数でも受け取れるようにする
template <typename T>
void print_variable(const std::string& name, const T& value) {
    std::cout << "変数名: " << name << ", 値: " << value << std::endl;
}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const ll INFL = 4e18;


int main()
{
 
    int nn,mm,kk;
    cin>>nn>>mm>>kk;

    mint n(nn),m(mm),k(kk);

    vector<vector<mint>> dp(k.val()+1,vector<mint>(nn+1));

    dp[0][0]=1;
    rep(i,kk){

        rep(j,nn){
            //dp[i+1][j+1]を更新
            mint now;
            rep(mee,mm){
                int me=mee+1;
                if(j+1-me>=0){
                    dp[i+1][j+1]+=dp[i][j+1-me]/m;
                }
                if(me>=2){
                    dp[i+1][j+1]+=dp[i][nn+1-me]/m;
                }

            }
            // dp[i+1][j+1]=now;
        }

    }
    mint ans;
    rep(i,kk)ans+=dp[i+1][nn];
    cout<<ans.val()<<endl;





    return 0;
}
