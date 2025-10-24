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


int main()
{
    int n;
    cin>>n;
    set<int>st;
    vint a(n),b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
        st.insert(a[i]);
        st.insert(b[i]);
    }
    map<int,int>mp;
    int index=0;
    if(st.count(1)==0)mp[1]=index++;
    for(auto now:st){
        
        mp[now]=index++;
    }
    vvi to(2*n+1);
    rep(i,n){
        // cout<<i<<endl;
        to[mp[a[i]]].push_back(mp[b[i]]);
        to[mp[b[i]]].push_back(mp[a[i]]);
    }
    // cout<<22<<endl;
    queue<int>q;
    vint visited(2*n+1);
    visited[0]=1;
    q.push(0);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto nv:to[now]){
            if(visited[nv]>0)continue;
            visited[nv]=1;
            q.push(nv);

        }
    }
    int ans=0;
    for(auto [key,value]:mp){
        if(visited[value]>0)chmax(ans,key);
    }
    cout<<ans<<endl;

    return 0;
}
