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
    vector<vector<pll>> to(n,vpll(n,mkpr(-1,-1)));
    rep(i,m){
        int u,v;
        ll d,t;
        cin>>u>>v>>d>>t;
        u--;v--;
        to[u][v]=mkpr(d,t);
        to[v][u]=mkpr(d,t);

    }
    vvll dp(1<<n,vll(n,-1));
    vint p(n,-1);
    vll go(n);
    vvll cnt(1<<n,vll(n,0));
    auto rec=[&](auto self,int s,int v)->ll{
        if(s==0){
            if(v==0)return dp[s][v]=0;
            else return dp[s][v]=INFL;
        }
        if(dp[s][v]!=-1)return dp[s][v];
        dp[s][v]=INFL;
        

        if((s&(1<<v))==0)return dp[s][v];
        ll cnt=1;
        rep(i,n){
            if(to[i][v].first==-1)continue;
            if(self(self,s^(1<<v),i)==INFL)continue;
            ll fin=dp[s^(1<<v)][i]+to[i][v].first;
            if(fin>to[i][v].second)continue;
            if(dp[s][v]==fin)cnt++;
            
            if(chmin(dp[s][v],fin))cnt=1;


            
        }
        go[v]=cnt;
        return dp[s][v];

    };
    ll ans=rec(rec,(1<<n)-1,0);
    if(ans!=-1&&ans!=INFL){
        cout<<ans<<' '<<go[0]<<endl;

    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    

    return 0;
}
