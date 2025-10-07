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
    int n,k;
    cin>>n>>k;
    vll a(n);
    rep(i,n)cin>>a[i];
    ll ans=INFL;
    for(int bit=0;bit<(1<<n);bit++){
        ll mx=0;
        ll now=0;
        set<ll>st;
        rep(i,n){
            if(mx<a[i]){
                st.insert(i);
                mx=a[i];

            }
            else{
                if(bit&(1<<i)){
                    now+=mx-a[i]+1;
                    st.insert(i);
                    mx=mx+1;
                
                }

            }
        }
        if(st.size()>=k)ans=min(ans,now);
    }
    cout<<ans<<endl;
    
    
    

    return 0;
}
