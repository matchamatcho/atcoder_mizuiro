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
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    set<pii> sta,stb;
    vint aa={0},bb={0};


    vint aindex;
    rep(i,n){
        if(s[i]=='a'){
            aa.push_back(aa.back()+1);
            bb.push_back(bb.back());
        }
        else{
            aa.push_back(aa.back());
            bb.push_back(bb.back()+1);
        }
    }

    int indexa=1,indexb=1;
    ll ans=0;

    rep(i,n){
        while(indexa+1<n&&aa[indexa+1]-aa[i+1]<a){
            indexa++;
        }
        while(indexb+1<n&&bb[indexb+1]-bb[i+1]<b){
            indexb++;
        }
        ans+=min(indexa,indexb)-i;
        cout<<i<<" "<<indexa<<" "<<indexb<<" "<<ans<<endl;

    }
    cout<<ans<<endl;


    



    return 0;
}
