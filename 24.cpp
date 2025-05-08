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
    vvi to(n);

    rep(i,n){
        int a;
        cin>>a;
        int k;
        cin>>k;
        rep(j,k){

            int b;
            cin>>b;
            to[i].push_back(b-1);
        }
    }
    vint start(n),end(n);
    auto dfs=[&](auto self,int now,int t)->int{
        start[now]=t;
        int nt=t;
        
        for(auto next:to[now]){
            if(start[next]!=0)continue;
            t+=self(self,next,t+1);
        }
        end[now]=t+1;
        return end[now]-start[now]+1;
    };
    int dt=1;
    // dfs(dfs,0,1);
    rep(i,n){
        if(start[i]==0)dt+=dfs(dfs,i,dt);
    }
    rep(i,n){
        cout<<i+1<<' '<<start[i]<<' '<<end[i]<<endl;
    }
    

    return 0;
}
