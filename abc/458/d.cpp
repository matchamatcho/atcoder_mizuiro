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


int main()
{
    ll x;
    int q;
    cin>>x>>q;
    std::priority_queue<
      int,                // 要素の型はint
      std::vector<int>,   // 内部コンテナはstd::vector (デフォルトのまま)
      std::greater<int>   // 昇順 (デフォルトはstd::less<T>)
    > q1;
    q1.push(x);

    // 降順に処理する
  std::priority_queue<int> q2;

    rep(i,q){
        ll a,b;
        cin>>a>>b;
        if(q1.top()<=a)q1.push(a);
        else q2.push(a);
        if(q1.top()<=b)q1.push(b);
        else q2.push(b);
        if(q1.size()==q2.size()+3){
            q2.push(q1.top());
            q1.pop();
        }
        else if(q2.size()>q1.size()){
            q1.push(q2.top());
            q2.pop();
        }
        cout<<q1.top()<<endl;

        
        



    }
    

    return 0;
}
