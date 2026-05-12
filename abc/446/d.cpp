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

void solve(){
    int n,d;
    cin>>n>>d;
    vint a(n),b(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    queue<int>q;
    rep(i,n){

        rep(j,a[i]){
            q.push(i);
        }
        rep(j,b[i]){
            q.pop();
        }
        while(q.size()>0&&(i-q.front()>=d)){
            q.pop();
        }
        
    }
    cout<<q.size()<<endl;
    
}

int main()
{
    int t;
    cin>>t;
    rep(i,t)solve();

    
    

    return 0;
}
