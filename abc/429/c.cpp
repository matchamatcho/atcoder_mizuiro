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


int main()
{
    ll n;
    cin>>n;
    vint a(n);
    rep(i,n)cin>>a[i];
    sort(ALL(a));
    if(a[0]==a.back()){
        cout<<0<<endl;
        return 0;

    }
    ll ans=0;

    ll right=0; 
    ll left=0;

    while(left<n){
        right=left;
        while(right+1<n&&(a[left]==a[right+1])){
            right++;
        }
        ll cnt=right-left+1;
        ll rest=n-cnt;
        ans+=cnt*(cnt-1)/2*rest;
        left=right+1;


    }

    cout<<ans<<endl;
    return 0;
}
