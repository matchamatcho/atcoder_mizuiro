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
    vll a(n);
    rep(i, n) cin >> a[i];
    vll s;
    rep(i,2*n)s.push_back(a[i%n]);
    vll dp(2*n+1, INFL);
    vvll visited(2*n+1, vll(2*n+1, -1));
    auto dfs=[&](auto self,int l,int r)->ll{
        if(visited[l][r]!=-1)return visited[l][r];
        if(l+1==r){
            visited[l][r]=s[l];
            return visited[l][r];}
        if(l+1==r-1){
            visited[l][r]=max(s[l],s[l+1]);
            return visited[l][r];}
        ll ans=0;
        //lをたべる
        int nl=l,nr=r;
        if(s[l+1]>s[r-1]){
            chmax(ans,self(self,l+2,r)+s[l]);
        }
        else{
            chmax(ans,self(self,l+1,r-1)+s[l]);
        }
        //r-1をたべる
        if(s[l]<s[r-2]){
            chmax(ans,self(self,l,r-2)+s[r-1]);
        }
        else{
            chmax(ans,self(self,l+1,r-1)+s[r-1]);
        }
        visited[l][r]=ans;
        return visited[l][r];



    };
    ll now=0;
    
        rep(i,n){
            chmax(now,dfs(dfs,i,i+n));
        }
        cout << now << endl;

        
    
    

    return 0;
}
