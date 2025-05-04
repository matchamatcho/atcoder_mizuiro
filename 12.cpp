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
    vvi xy(n,vint(n));
    rep(i,m){
        int x,y;
        cin>>x>>y;
        x--;y--;
        xy[x][y]=1;
        xy[y][x]=1;
    }
    rep(i,n)xy[i][i]=1;
    int ans=0;
    for(int bit=0;bit<(1<<n);++bit){
        bool ok=true;
        int cnt=0;
        rep(i,n){
            if(bit&(1<<i)){
                cnt++;
                rep(j,n){
                    if(bit&(1<<j)){
                        // cnt++;
                        if(xy[i][j]==0)ok=false;
                    }
                }
            }
        }
        if(ok)ans=max(ans,cnt);
    }
    cout<<ans<<endl;

    

    return 0;
}
