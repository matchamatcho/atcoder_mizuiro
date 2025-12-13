#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
#define Yes(q) cout << ((q) ? "Yes" : "No") << endl;
#define priv(value) print_variable(#value, value)
// 汎用的な表示関数テンプレート
// どんな型 T の変数でも受け取れるようにする
template <typename T>
void print_variable(const std::string& name, const T& value) {
    std::cout << "変数名: " << name << ", 値: " << value << std::endl;
}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const ll INFL = 4e18;



struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long long, int>;


/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
    計算量：O(|E|log|V|)
    副作用：dis, prevが書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis, vector<int> &prev) {
    int N = G.size();
    dis.resize(N, INFL);
    prev.resize(N, -1); // 初期化
    priority_queue<P, vector<P>, greater<P>> pq; 
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

int main()
{
    int h,w;
    cin>>h>>w;
    vstr s(h);
    rep(i,h)cin>>s[i];

    vvpii wp(26);
    rep(i,h)rep(j,w){
        if('a'<=s[i][j]&&s[i][j]<='z'){
            wp[s[i][j]-'a'].push_back({i,j});
        }
    }

    vll dis;
    vint prev;
    Graph G(h*w+26);
    rep(i,h)rep(j,w){
        if('a'<=s[i][j]&&s[i][j]<='z'){
            int idx=s[i][j]-'a';
            G[i*w+j].push_back({h*w+idx,0});
            G[h*w+idx].push_back({i*w+j,1});
        }
    }
    rep(i,h)rep(j,w-1){
        if(s[i][j]!='#'&&s[i][j+1]!='#'){
            G[i*w+j].push_back({i*w+(j+1),1});
            G[i*w+(j+1)].push_back({i*w+j,1});
        }
    }
    rep(i,h-1)rep(j,w){
        if(s[i][j]!='#'&&s[i+1][j]!='#'){
            G[i*w+j].push_back({(i+1)*w+j,1});
            G[(i+1)*w+j].push_back({i*w+j,1});
        }
    }
    dijkstra(G,0,dis,prev);
    if(dis[h*w-1]==INFL)cout<<-1<<endl;
    else cout<<dis[h*w-1]<<endl;       



    return 0;
}
