#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using mint = modint998244353;

using ll = long long;
ll mod=998244353;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll,ll>;
using pml=pair<mint,ll>;
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
void COMinit(vector<long long> &fac,vector<long long> &finv,vector<long long> &inv,long long MOD,long long MAX) {
    // const int MOD = mint::mod();
    // long long MAX=fac.size();
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
// nCk mod を計算する
// fac:階乗, finv:階乗の逆元, n: n, k: k, MOD:法
long long COM(vector<long long> fac,vector<long long> finv,long long n, long long k,long long MOD){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main()
{
    // vll fac,finv,inv;
    // COMinit(fac,finv,inv,mod,998244353);
    int n;
    cin>>n;
    vint p(n);
    rep(i,n-1){cin>>p[i+1];p[i+1]--;};
    vll c(n),d(n);
    rep(i,n)cin>>c[i];
    rep(i,n)cin>>d[i];
    vvi tochild(n);
    rep(i,n-1){
        tochild[p[i+1]].push_back(i+1);
    }
    // rep(i,n){printv(tochild[i])}
    auto dfs=[&](auto self,int v,int p=-1)->pml{
        mint res=1;
        ll num=c[v];
        for(auto x:tochild[v]){
            pml t=self(self,x,v);

            res*=t.first;
            num+=t.second;
            // cout<<v<<" "<<t.first.val()<<" "<<t.second<<endl;
        }
        if(num<d[v]){
            return mkpr(0,0);
        }
        // res*=COM(fac,finv,num,d[v],mod);
        mint tt=1;
        rep(i,d[v]){
            tt*=(num-i);
            tt/=d[v]-i;
        }
        res*=tt;
        num-=d[v];
        return mkpr(res,num);

    };
    pml ans=dfs(dfs,0);

    cout<<ans.first.val()<<endl;
    

    

    return 0;
}
