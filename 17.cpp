#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
// using mint = modint998244353;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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
#define Rep(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define printv(x)           \
    ;                       \
    for (auto now : x)      \
        cout << now << " "; \
    cout << endl;
#define yes(q) cout << ((q) ? "Yes" : "No") << endl;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
const int INF = 1001001001;
const ll INFL = 4e18;

int n = 8;
void check(vvi a)
{
    bool ok=true;
    rep(i,n)rep(j,n){
        if(a[i][j]==0)continue;
        rep(k,n-1)if(a[i][(j+1+k)%n]==1)ok=false;
        rep(k,n-1)if(a[(i+1+k)%n][j]==1)ok=false;
        rep(k,n-1){
            int ni=i+k+1,nj=j+k+1;
            if(ni>n-1||nj>n-1)break;
            if(a[ni][nj]==1)ok=false;
        }
        // cout<<444<<endl;
        rep(k,n-1){
            int ni=i-k-1,nj=j+k+1;
            if(ni<0||nj>n-1)break;
            if(a[ni][nj]==1)ok=false;
        }
        // cout<<333<<endl;
        rep(k,n-1){
            int ni=i-k-1,nj=j-k-1;
            if(ni<0||nj<0)break;
            if(a[ni][nj]==1)ok=false;
        }
        // cout<<222<<endl;
        rep(k,n-1){
            int ni=i+k+1,nj=j-k-1;
            if(ni>n-1||nj<0)break;
            if(a[ni][nj]==1)ok=false;
        }
        // cout<<111<<endl;
        


    }
    if(ok){
        // cout<<333<<endl;
        rep(i,n){
            rep(j,n){
                if(a[i][j]==1)cout<<'Q';
                else cout<<'.';
            }
            cout<<'\n';
        }
    }
}
int main()
{
    int k;

    cin >> k;
    set<pii> st;
    rep(i, k)
    {
        int s, t;
        cin >> s >> t;
        st.insert(mkpr(s, t));
    }
    vint p(n);
    rep(i, n) p[i] = i;
    do
    {
        vvi now(n, vint(n));
        bool ok=true;
        rep(i, n)
        {
            now[i][p[i]] = 1;
        }
        for(auto [x,y]:st)if(now[x][y]==0)ok=false;
        if(ok)check(now);


    } while (next_permutation(p.begin(), p.end()));

    return 0;
}
