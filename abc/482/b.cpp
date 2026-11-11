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


int main()
{
    vstr s(5);
    rep(i,5)cin>>s[i];
    int ans=5;
    rep(i,5){
        int now=5;
        rep(j,5){
            if(s[i][j]=='o')now--;
        }
        chmin(ans,now);


    }
    rep(i,5){
        int now=5;
        rep(j,5){
            if(s[j][i]=='o')now--;
        }
        chmin(ans,now);
        

    }
    int now=5;
    rep(i,5){
        if(s[i][i]=='o')now--;
    }
    chmin(ans,now);
    now=5;
    rep(i,5){
        if(s[4-i][4-i]=='o')now--;
    }
    chmin(ans,now);
    cout<<ans<<endl;

    

    return 0;
}
