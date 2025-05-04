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
    vector<pair<ld,ld> >xy;
    rep(i,n){
        ld x,y;
        cin>>x>>y;
        xy.push_back(mkpr((ld)x,(ld)y));
        // cout<<x<<' '<<y<<endl;


    }
    vint p(n);
    int k=1;
    rep(i,n)k*=1+i;
    // cout<<k<<endl;
    rep(i,n)p[i]=i;
    long double sum=0;
    do{
        rep(i,n-1){
            long double dx=xy[p[i]].first-xy[p[i+1]].first,dy=xy[p[i]].second-xy[p[i+1]].second;
            // cout<<dx<<endl;
            sum+=sqrtl(dx*dx+dy*dy);
        }
    }while(next_permutation(p.begin(), p.end()));
    sum /= (ld)k;
    printf("%.10Lf\n",sum);

    

    return 0;
}
