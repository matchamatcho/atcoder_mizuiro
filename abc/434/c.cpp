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

void solve(){
    ll n,h;
    cin>>n>>h;
    ll mx=h,mn=h;
    ll prevt=0;
    vll tt(n),lll(n),uu(n);
    rep(i,n){
        cin>>tt[i]>>lll[i]>>uu[i];
    }

    rep(i,n){
        ll t,l,u;

        t=tt[i];
        l=lll[i];
        u=uu[i];

        ll dt=t-prevt;
        mx+=dt;
        mn-=dt;
        mn=max(mn,1LL);

        if(mx<l||mn>u){
            // cout<<mn<<" "<<mx<<" "<<l<<" "<<u<<" "<<t<<" "<<prevt<<endl;
            cout<<"No"<<endl;
            return;
        }
        chmin(mx,u);
        chmax(mn,l);
        prevt=t;

    }
    cout<<"Yes"<<endl;
    return;
}

int main()
{
    int t;
    cin>>t;
    while(t--)solve();
    

    return 0;
}
