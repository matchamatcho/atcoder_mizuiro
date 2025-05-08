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
    int n;
    cin>>n;
    vll h(n),s(n);
    rep(i,n)cin>>h[i]>>s[i];
    ll wa=0,ok=INFL;
    auto check=[&](ll x)->bool{
        vll a;

        rep(i,n){
            if(x<h[i])return false;
            if(x==h[i])a.push_back(1);
            else a.push_back((x-h[i])/s[i]+1);
        }
        sort(a.begin(), a.end());
        // cout<<n<<endl;
        // cout<<x<<endl;
        if(x==102){
            // printv(a);
        }
        rep(i,n-1)if(a[i+1]<=i+1)return false;
        return true;


    };
    while(ok-wa>1){
        ll mid=(wa+ok)/2;
        if(check(mid))ok=mid;
        else wa=mid;
        // cout<<mid<<endl;
    }
    cout<<ok<<endl;
    

    return 0;
}
