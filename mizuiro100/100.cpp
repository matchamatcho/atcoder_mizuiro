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
    ll n;
    cin>>n;
    

    ll left=1,right=n+2;

    while(right-left>1){
        ll mid=(left+right)/2;
        if(mid*(mid-1)/2<=n)left=mid;
        else right=mid;
        // cout<<mid<<endl;
    }

    // cout<<left<<endl;
    if(left*(left-1)/2!=n){
        cout<<"No"<<endl;
        return 0;
    }

    vector<tuple<int,int,int>> edge;
    int cnt=0;
    vvi st(left);

    rep(i,left)rep(j,i){
        edge.push_back({i+1,j+1,cnt++});
    }

    for(auto[x,y,z]:edge){
        st[x-1].push_back(z);
        st[y-1].push_back(z);
    }

    cout<<"Yes"<<endl;
    cout<<left<<endl;
    for(auto v:st){
        cout<<v.size();
        for(auto x:v)cout<<" "<<x+1;
        cout<<endl;
    }
    



    

    return 0;
}
