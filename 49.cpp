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
    // cout<<666<<endl;

    int V,E;
    cin>>V>>E;
        // cout<<666<<endl;

    vvi to(V,vint(V,-1));
            // cout<<666<<endl;

    rep(i,E){
        int u,v,d;
        cin>>u>>v>>d;
        // u--;v--;
        to[u][v]=d;
    }
    // cout<<777<<endl;
    vvi dp(1<<V,vint(V,INF));
    dp[0][0]=0;
    // cout<<333<<endl;
    auto rec=[&](auto self,int s,int v)->int{
        // cout<<s<<' '<<v<<endl;
        if(dp[s][v]!=INF)return dp[s][v];
        if(s==0){
            if(v==0)return 0;
            else return INF;
        }
        if((s&(1<<v))==0)return INF;

        rep(i,V){
            if(to[i][v]==-1)continue;
            if(self(self,s^(1<<v),i)==INF)continue;
            chmin(dp[s][v],self(self,s^(1<<v),i)+to[i][v]);
        }
        return dp[s][v];
    };
    int ans=rec(rec,(1<<V)-1,0);
    if(ans==INF)ans=-1;
    cout<<ans<<endl;

    

    return 0;
}
