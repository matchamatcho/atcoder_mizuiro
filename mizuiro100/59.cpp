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
    int n,k;
    cin>>n>>k;
    vll c(n),r(n);
    rep(i,n){
        cin>>c[i]>>r[i];
        // cout<<c[i]<<" "<<r[i]<<endl;

    }
    vvi ab(n);
    vint a(k),b(k);
    Graph g(n);
    // cout<<444<<endl;
    rep(i,k){
        cin>>a[i]>>b[i];
        // cout<<a[i]<<1231<<endl;
        
        a[i]--;b[i]--;
        // cout<<12<<endl;
        // cout<<a[i]<<" "<<b[i]<<endl;
        ab[a[i]].push_back(b[i]);
        ab[b[i]].push_back(a[i]);
        // cout<<21<<endl;

    }
    // cout<<222<<endl;
    rep(i,n){
        queue<int>q;
        vint visited(n);
        q.push(i);
        visited[i]=1;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            
            for(auto next:ab[now]){
                if(visited[next]==0){
                    if(visited[now]+1<=r[i]+1){
                        visited[next]=visited[now]+1;
                        q.push(next);
                        g[i].push_back({next,c[i]});
                    }
                }
            }
        }
    }
    // cout<<111<<endl;
    vll dis;vint perv;
    dijkstra(g,0,dis,perv);
    cout<<dis[n-1]<<endl;
    

    return 0;
}
