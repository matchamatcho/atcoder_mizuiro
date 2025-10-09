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
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
    ll n,m;
    cin>>n>>m;
    dsu uf(n);
    vvi to(n);
    rep(i,m){
        int u,v;
        cin>>u>>v;
        u--;v--;
        uf.merge(u,v);
        to[u].push_back(v);
        to[v].push_back(u);
    }
    vint color(n,-1);
    pll cnt(0,0);
    auto dfs=[&](auto self,int v,int p=-1,int pc=-1)->void{

        

        for(auto nv:to[v]){
            if(nv==p)continue;
            if(color[nv]==color[v]){
                // cout<<v<<" "<<nv<<endl;
                cout<<0<<endl;
                // cout<<"dame"<<endl;
                exit(0);
            }
            if(color[nv]==-1){
                color[nv]=1-color[v];
                cnt.first += (color[nv]==0);
                cnt.second += (color[nv]==1);
                self(self,nv,v,color[nv]);
            }
        }
        return;

    };
    ll ans=n*(n-1)/2-m;
    // cout<<ans<<endl;

    vvi gr=uf.groups();
   

    rep(i,gr.size()){
        if(color[gr[i][0]]!=-1)continue;
        cnt=pll(0,0);
        color[gr[i][0]]=0;
        cnt.first++;
        dfs(dfs,gr[i][0]);
        ans-=(cnt.first*(cnt.first-1))/2;
        ans-=(cnt.second*(cnt.second-1))/2;
     

    }
    cout<<ans<<endl;
    

    return 0;
}
