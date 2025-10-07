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
    int R,C;
    cin >> R >> C;
    // cout<<R<<' '<<C<<endl;
    vstr c(R);
   
    vvi visited(R, vint(C, 0));
    queue<pii> q;
    int sy,sx,gy,gx;
    cin >> sy >> sx >> gy >> gx;
    rep(i,R) cin >> c[i];
    // cout<<sy<<endl;
    sy--; sx--; gy--; gx--;
    q.push({sy,sx});
    // cout<<111<<endl;
    // cout<<sy<<endl;
    visited[sy][sx] = 1;
    // cout<<111<<endl;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        int y = now.first;
        int x = now.second;
        rep(k,4){
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if(c[ny][nx] == '#' || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    cout << visited[gy][gx] - 1 << endl;

    

    return 0;
}
