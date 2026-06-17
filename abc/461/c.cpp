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
    int n,k,m;
    cin>>n>>k>>m;
    vll c(n),v(n);
        priority_queue<pll> q,q2;

    rep(i,n){cin>>c[i]>>v[i];
        c[i]--;
    q.push({v[i],c[i]});

    }
    vint used(n);
    vll ans;
    rep(i,n){
        pll now=q.top();
        q.pop();
        if(ans.size()==m){
            q2.push(now);
            continue;
        }
        if(used[now.second]==0){
            used[now.second]=1;
            ans.push_back(now.first);

        }
        else{
            q2.push(now);
        }

    }
    while(ans.size()<k){
        pll now=q2.top();
        q2.pop();
        ans.push_back(now.first);
    }
    ll x=0;
    for(ll a:ans)x+=a;
    cout<<x<<endl;
    
    

    return 0;
}
