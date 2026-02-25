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
using vvstr=vector<vstr>;
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
    int n,s;
    cin>>n>>s;
    vint a(n),b(n);
    rep(i,n)cin>>a[i]>>b[i];

    vvstr dp(n+1,vstr(s+1,""));
    dp[0][0]="a";
    map<int,string>mp;
    rep(i,n){
        rep(j,s+1){
            if(dp[i][j].size()>0){
                if(j+a[i]<=s){dp[i+1][j+a[i]]=dp[i][j]+"H";}
                if(j+b[i]<=s){dp[i+1][j+b[i]]=dp[i][j]+"T";}
            }

        }
        
    }
    if(dp[n][s].size()>0){
        cout<<"Yes"<<endl;
        rep(i,n)cout<<dp[n][s][i+1];
        cout<<endl;
        
    }
    else{
        cout<<"No"<<endl;
    }
    rep(i,n+1){
        rep(j,s+1){
            // if(dp[i][j].size()>0)cout<<"o";
            // else cout<<"x";
        }
        cout<<endl;
    }
    

    return 0;
}
