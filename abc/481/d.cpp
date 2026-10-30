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

struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<pll>>;
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
    // printv(dis)
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.first] > dis[v] + e.second) {
                dis[e.first] = dis[v] + e.second;
                prev[e.first] = v; // 頂点 v を通って e.to にたどり着いた
                pq.emplace(dis[e.first], e.first);
            }
        }
    }
}
vector<int> get_path(const vector<int> &prev, int t) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
    return path;
}


int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    s--;t--;
    Graph graph(n);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        graph[a].push_back({b,1});

    }

    rep(i,n){
        sort(ALL(graph[i]));
        if(graph[i].size()>0){
            graph[i][0].second=0;
            // cout<<i<<":"<<graph[i][0].first<<" "<<graph[i][0].second<<endl;
        }
    }
    vll a(n,INFL);
    vint b(n);
    dijkstra(graph,s,a,b);
    cout<<((a[t]<INFL)?a[t]:-1)<<endl;
    // printv(a)
    // vint c=get_path(b,t);
    // printv(c);
    // printv(b);
    // cout<<s<<" "<<t<<endl;
    

    return 0;
}
