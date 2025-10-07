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

vvi di={{-1,-1,0,0,1,1},{-1,-1,0,0,1,1}},dj={{0,-1,1,-1,0,-1},{0,1,-1,1,0,1}}; // 4

int main()
{
    int w,h;
    cin >> w >> h;
    vvi g(h+2, vint(w+2, 0));
    rep(i,h)rep(j,w){
        cin>> g[i+1][j+1];

    }
    vvi visited(h+2, vint(w+2, 0));
    queue<pii> q;
    q.push({0,0});
    visited[0][0] = 1;
    int ans=0;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        int i = now.first;
        int j = now.second;
        rep(k,6){
            int ni = i + di[i%2][k];
            int nj = j + dj[i%2][k];
            if(ni < 0 || ni > h+1 || nj < 0 || nj > w+1) continue;
            if(visited[ni][nj] == 1) continue;
            if(g[ni][nj] == 1) {
                ans++;
                // continue;
                // cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<endl;
                continue;
            }
            visited[ni][nj] = 1;
            q.push({ni,nj});
        }
    }
    cout<<ans<<endl;
    

    return 0;
}
