#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
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

vpii dij={mkpr(-1,-1),mkpr(-1,0),mkpr(0,-1),mkpr(0,1),mkpr(1,0),mkpr(1,1)};

int f(int x,int y){
    return 3000*x+y;
}
int main()
{
    int n;
    cin>>n;
    // return 0;
    vint X(n),Y(n);
    dsu uf(1e8);
    set<int>st;
    rep(i,n){
        int x,y;
        cin>>x>>y;
        x+=1000;
        y+=1000;
        X[i]=x;
        Y[i]=y;
        st.insert(f(x,y));

    }
    // return 0;
    rep(k,n){
        for(auto [i,j]:dij){
            int nx=X[k]+i,ny=Y[k]+j;
            if(st.count(f(nx,ny))>0)uf.merge(f(X[k],Y[k]),f(nx,ny));
        }
    }
    // return 0;
    vector<bool> aa(1e8,false);
    int ans=0;
    rep(i,n){
        int mas=uf.leader(f(X[i],Y[i]));
        if(!aa[mas]){ans++;aa[mas]=true;}
    }
    // return 0;
    cout<<ans<<endl;

    

    return 0;
}
