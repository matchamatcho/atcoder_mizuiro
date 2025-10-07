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
    int r,c;
    cin>>r>>c;
    vvi a(r,vint(c));
    rep(i,r)rep(j,c)cin>>a[i][j];
    int ans=0;
    for(int bit=0;bit<(1<<r);++bit){
        vvi now=a;
        rep(i,r){
            if(bit&(1<<i)){
                rep(j,c){
                    now[i][j]=1-a[i][j];
                }

            }
        }
        int cnt=0;
        rep(j,c){
            int cnt2=0;
            rep(i,r){
                if(now[i][j]==1)cnt2++;
            }
            cnt+=max(cnt2,r-cnt2);
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;

    

    return 0;
}
