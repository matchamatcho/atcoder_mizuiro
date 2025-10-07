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
    ll n,m;
    cin>>n>>m;
    vll a(n);
    rep(i,n)cin>>a[i];
    vll aa=a;
    int nmm=-1;
    rep(i,n){
        int cnt=0;
        while(aa[i]%2==0){
            aa[i]/=2;
            cnt++;
        }
        if(nmm==-1)nmm=cnt;
        else if(nmm!=cnt){
            cout<<0<<endl;
            return 0;
        }
    }

    ll lcms=1;
    rep(i,n)lcms=lcm(lcms,a[i]/2);
    cout<<m/lcms-m/(lcms*2)<<endl;


    
    

    return 0;
}
