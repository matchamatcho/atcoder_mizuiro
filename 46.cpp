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
    int N;
    cin>>N;
    vint a(N),b(N);
    rep(i,N) cin>>a[i]>>b[i];
    vvi visited(N+1,vint(N+1,-1));
    auto dfs=[&](auto self,int l,int r)->int{
        if (visited[l][r]!=-1) return visited[l][r];
        if(l+1==r-1){
            // cout<<l<<" "<<r<<" "<<a[l]*b[l]*b[l+1]<<endl;
            visited[l][r]=a[l]*b[l]*b[r-1];
            return a[l]*b[l]*b[r-1];
        }
        else if(l>=r-1){
            visited[l][r]=0;
            return 0;
        }
        int now=INF;
        for(int i=l+1;i<r;++i){
            chmin(now,self(self,l,i)+self(self,i,r)+a[l]*b[i-1]*b[r-1]);
        }
        visited[l][r]=now;
        return now;
    };
    cout<<dfs(dfs,0,N)<<endl;
    // cout<<visited[2][4]<<endl;


    

    return 0;
}
