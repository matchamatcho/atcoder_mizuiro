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

vint di={0, 1, 0, -1};
vint dj={1, 0, -1, 0};

int main()
{
    int w,h;
    cin >> w >> h;
    vvi ice(h, vint(w));
    rep(i, h) {
        rep(j, w) {
            cin >> ice[i][j];
        }
    }
    // rep(i,h){
    //     rep(j,w){
    //         cout<<ice[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    

    auto dfs=[&](auto self,int i,int j,vvi visited)->int{
        visited[i][j] = 1;
        int cnt=0;
        rep(k,4){
            int ni=i+di[k];
            int nj=j+dj[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (ice[ni][nj] == 0||visited[ni][nj]>0) continue;
            cnt=max(cnt,self(self,ni,nj,visited));
        }

        return cnt+1;

    };
    int ans=0;
    rep(i,h){
        rep(j,w){
            if (ice[i][j] == 0) continue;
            ans=max(ans,dfs(dfs,i,j,vvi(h,vint(w,0))));
        }
    }
    cout<<ans<<endl;

    
    

    return 0;
}
