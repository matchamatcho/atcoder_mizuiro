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

int w=2000,h=2000;

int main()
{
    int n;
    cin>>n;
    vvi g(h+1,vint(w+1,0));
    vvi gg=g;
    rep(i,n){
        int u,d,l,r;
        cin>>u>>d>>l>>r;

        u--;l--;
        g[u][l]++;
        g[d][l]--;
        g[u][r]--;
        g[d][r]++;
        gg[u][l]+=i;
        gg[d][l]-=i;
        gg[u][r]-=i;
        gg[d][r]+=i;
    }
    rep(i,h){
        rep(j,w){
            g[i][j+1]+=g[i][j];
            gg[i][j+1]+=gg[i][j];
        }
    }
    rep(j,w){
        rep(i,h){
            g[i+1][j]+=g[i][j];
            gg[i+1][j]+=gg[i][j];
        }
    }
    int painted=0;
    set<pii>st;
    rep(i,h){
        rep(j,w){
            if(g[i][j]>0)painted++;
            if(g[i][j]==1)st.insert({i,j});
        }
    }
    vint ans(n,w*h-painted);
    for(auto p:st){
        // cout<<p.first<<" "<<p.second<<" "<<gg[p.first][p.second]<<endl;
        ans[gg[p.first][p.second]]++;
    }
    rep(i,n){
        cout<<ans[i]<<endl;
    }




    return 0;
}
