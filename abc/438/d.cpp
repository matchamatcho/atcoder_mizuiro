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
    int N;
    cin>>N;
    vll A(N),B(N),C(N);
    rep(i,N){cin>>A[i];

    }
    rep(i,N)cin>>B[i];
    rep(i,N)cin>>C[i];
    vll sa={0},sb={0},sc={0};
    rep(i,N)sa.push_back(sa.back()+A[i]);
    rep(i,N)sb.push_back(sb.back()+B[i]);
    rep(i,N)sc.push_back(sc.back()+C[i]);
    vll bc(N+1);
    rep(i,N+1)bc[i]=sb[i]-sc[i];
    rep(i,N-2){
        bc[N-1-2-i]=max(bc[N-1-2-i],bc[N-1-2-i+1]);
    }
    ll ans=0;
    rep(i,N-2){
        ll now=0;
        now=sa[1+i]-sb[1+i]+sc[N]+bc[i];
        ans=max(ans,now);

    }
    cout<<ans<<endl;

    return 0;
}
