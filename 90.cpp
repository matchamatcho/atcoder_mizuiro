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
    int n,m;
    cin>>n>>m;
    vector<long double> xn(n),yn(n),rn(n),xm(m),ym(m),rm(m);
    rep(i,n)cin>>xn[i]>>yn[i]>>rn[i];
    rep(i,m)cin>>xm[i]>>ym[i];
    long double minr=100000.0f;
    rep(i,m){
        long double x= xm[i];
        long double y= ym[i];
        
        rep(j,n){
            long double dx = x - xn[j];
            long double dy = y - yn[j];
            long double dist = sqrtl(dx*dx + dy*dy);
            minr = min(minr, dist - rn[j]);
            
        }
        // cout<<minr<<endl;
        rm[i]=minr;

    }    
    rep(i,m)rep(j,i){
        long double dx = xm[i]-xm[j];
        long double dy = ym[i]-ym[j];
        long double dist = sqrtl(dx*dx + dy*dy) ;
        // cout<<dist<<endl;
        // cout<<dist<<" "<<(rm[i] + rm[j])<<" "<<i<<" "<<j<<endl;
        if (dist - (rm[i] + rm[j]) < 0) {chmin(rm[i],dist/2);
        chmin(rm[j],dist/2);}
    }
    // printv(rm)
    long double ans=10000000.0f;
    for(auto x:rm)chmin(ans,x);
    for(auto x:rn)chmin(ans,x);
    cout<<fixed<<setprecision(10)<<ans<<endl;

    return 0;
}
