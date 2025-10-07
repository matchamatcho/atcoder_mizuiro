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

vint di = {0, 1, 0, -1}, dj = {1, 0, -1, 0}; // 4

int main()
{
    int h,w;
    cin >> h >> w;
    vstr s(h);
    rep(i,h) cin >> s[i];
    int cnt=0;
    rep(i,h)rep(j,w){
        if(s[i][j] == '.') cnt++;
        // cout<<i<<" "<<j<<" "<<cnt<<endl;
    }
    vvi visited(h, vint(w, 0));
    queue<pii> q;
    q.push({0,0});
    visited[0][0] = 1;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        int i = now.first;
        int j = now.second;
        rep(k,4){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if(visited[ni][nj]  >0) continue;
            if(s[ni][nj] == '#') continue;
            visited[ni][nj] = visited[i][j] + 1;
            q.push({ni,nj});
        }
    }
    // cout<<cnt<<endl;
    // cout<<visited[h-1][w-1]<<endl;
    if(visited[h-1][w-1] == 0){
        cout << -1 << endl;
        return 0;
    }
    else{
        cout << cnt - visited[h-1][w-1]  << endl;
        // cout << visited[h-1][w-1] << endl;
    }
    

    return 0;
}
