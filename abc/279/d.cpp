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
    ll a,b;
    cin>>a>>b;

    auto f=[&](ll x)->double{
        return (double)b*x+(double)a/sqrt(1.0+x);
    };
    
    ll low=0,high=a/b;
    while(abs(high-low)>2){
        // cout<<low<<" "<<high<<endl;
        ll mid1=(low*2+high)/3;
        ll mid2=(low+high*2)/3;
        if(f(mid1)>f(mid2)){
            low=mid1;
        }else{
            high=mid2;
        }

    }
    // cout<<f(2)<<endl;
    // cout<<f(low)<<" "<<f(high)<<endl;
    cout<<fixed<<setprecision(10)<<min(min(f(low),f(high)),f(low+1))<<endl;

    return 0;
}
