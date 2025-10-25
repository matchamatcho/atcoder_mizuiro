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
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) (x).begin(),(x).end()
#define printv(x); for(auto now : x) cout << now << " "; cout << endl;
#define Yes(q) cout << ((q) ? "Yes" : "No") << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const ll INFL = 4e18;
#define priv(value) print_variable(#value, value)
// 汎用的な表示関数テンプレート
// どんな型 T の変数でも受け取れるようにする
template <typename T>
void print_variable(const std::string& name, const T& value) {
    std::cout << "変数名: " << name << ", 値: " << value << std::endl;
}


int main()
{
    ll n,m,c;
    cin>>n>>m>>c;
    vll a(n);
    rep(i,n)cin>>a[i];
    sort(ALL(a));
    vll aa(2*n);
    rep(i,n)aa[i]=a[i];
    
    rep(i,n)aa[i+n]=a[i]+m;
    ll left=1;
    ll right=0;
    ll ans=0;
    ll pleft=-1;
    // printv(aa);
    rep(left,n){
        if((aa[left+1]==aa[left]))continue;
        right=max(left,right);
        while(right+1<2*n&&((aa[right]==aa[right+1])||(right-left<c))){
            right++;
        }
        // cout<<"left:"<<left<<" right:"<<right<<endl;
        ll t=aa[left+1]-aa[left];
        ll cnt=right-left;
        // priv(t);
        // priv(cnt);
        
        ans+=cnt*t;
        pleft=left;

    }
    right=left;
    while(right+1<2*n&&((aa[right]==aa[right+1])||(right-left+1<c))){
        right++;
    }

    cout<<ans<<endl;

    return 0;
}
