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
    int m;
    cin>>m;
    vint mx(m),my(m);
    rep(i,m)cin>>mx[i]>>my[i];
    int n;
    cin>>n;
    set<pii> nxy;
    rep(i,n){
        int x,y;
        cin>>x>>y;
        nxy.insert(mkpr(x,y));
    } 
    for(auto [x,y]:nxy){
        int dx=x-mx[0],dy=y-my[0];
        // cout<<dx<<' '<<dy<<endl;
        bool ok=true;
        rep(i,m-1){
            // cout<<x<<' '<<y<<endl;
            // cout<<mx[i+1]+dx<<' '<<my[i+1]+dy<<endl;


            if(nxy.count(mkpr(mx[i+1]+dx,my[i+1]+dy))==0){
                if(dx==2&&dy==-3){
                // cout<<mx[i+1]<<' '<<my[i+1]<<endl;
            }
                // cout<<mx[i+1]+dx<<' '<<my[i+1]+dy<<endl;

                ok=false;
                break;
            }
        }
        if(ok){
            cout<<dx<<" "<<dy<<endl;
            return 0;
        }
    }
    

    

    return 0;
}
