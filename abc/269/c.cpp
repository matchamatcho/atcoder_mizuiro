#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
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
    ll n;
    cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    vll a;
    ll s=0;
    for(ll i=0;i<60;i++){
        if((n>>i)&1){
            // cout<<i<<" " <<((ll (1))<<i)<<endl;
            a.push_back((ll)1<<i);
            s+=1<<i;
        }
    }
    // printv(a);
    ll m=576461302059761664;
    // cout<<m<<endl;
    // cout<<s<<endl;
    bitset<60> bs(m);
	// cout << bs << endl;

    set<ll>ans;
    for(ll i=0;i<(1<<(a.size()));i++){
        ll now=0;
        for(ll j=0;j<a.size();++j){
            if((i>>j)&1){
                now+=a[j];
            }
        }
        ans.insert(now);

    }
    for(auto x:ans){
        cout<<x<<endl;
    }
    

    return 0;
}
