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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const ll INFL = 4e18;
template<typename T>
vector<pair<T, T>> FACTORIZATION(T x) {
    vector<pair<T, T>> ans;
    for (T i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            T count = 0;
            while (x % i == 0) {
                count++;
                x /= i;
            }
            ans.push_back(make_pair(i, count));
        }
    }
    if (x != 1) ans.push_back(make_pair(x, 1));
    return ans;
}
#define priv(value) print_variable(#value, value)
// 汎用的な表示関数テンプレート
// どんな型 T の変数でも受け取れるようにする
template <typename T>
void print_variable(const std::string& name, const T& value) {
    std::cout << "変数名: " << name << ", 値: " << value << std::endl;
}

int main()
{
    ll k;
    cin>>k;


    
    auto f=FACTORIZATION(k);
    ll left=1,right=k;
    while(right-left>1){
        map<ll,ll>mp;
        
        ll mid=(left+right)/2;
        for(int i=1;i<=mid;++i){
        auto p=FACTORIZATION(i);
        
    
        for(auto q:p){
            mp[q.first]+=q.second;
        }
        
    }
        // priv(mid);
        bool ok=true;
        for(auto p:f){
            if(mp[p.first]<p.second){
                ok=false;
                break;
            }
            
        }
        if(ok)right=mid;
        else left=mid;
    }
    cout<<right<<endl;
    

    return 0;
}
