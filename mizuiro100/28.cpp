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
    int n;
    cin >> n;
    vvi to(n);
    rep(i, n) {
        int y;
        cin>>y;
        int k;
        cin >> k;
        rep(j, k) {
            int v;
            cin>>v;
            v--;
            to[i].push_back(v);
        }
    }
    vint visited(n);
    queue<int>q;
    q.push(0);
    visited[0]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto next:to[now]){
            if(visited[next]==0){
                visited[next]=visited[now]+1;
                q.push(next);
            }
        }
    }
    rep(i,n){
        if(visited[i]==0){
            cout<<i+1<<' '<<-1<<endl;
        }
        else cout<<i+1<<' '<<visited[i]-1<<endl;
    }
    

    return 0;
}
