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


struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long long, int>;
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
    int v,e,s;
    cin>>v>>e>>s;
    Graph g(v);
    rep(i,e){
        int u,v;ll d;
        cin>>u>>v>>d;
        g[u].push_back({v,d});
        // g[v].push_back({u,d});
    }
    vll dis;
    vint prev;
    dijkstra(g,s,dis,prev);
    rep(i,v){
        if(dis[i]<INFL)cout<<dis[i]<<endl;
        else cout<<"INF"<<endl;
    }


    
    

    return 0;
}
