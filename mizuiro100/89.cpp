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
    cin>>n;
    
    int prev=-1;
    vint ans={};
    int cnt=0;
    rep(i,n){
        int c;
        cin>>c;
        if(c==prev){
            ans.push_back(cnt);
            cnt=1;
            prev=c;
        }
        else{
            cnt++;
            prev=c;
        }

    }
    if(cnt>0)ans.push_back(cnt);
    int res=0;
    if(ans.size()<3){

        for(auto v:ans)res+=v;
    }
    else{
        for(int i=0;i<ans.size()-2;++i){
            res=max(res,ans[i]+ans[i+1]+ans[i+2]);
        }
    }
    // printv(ans);
    cout<<res<<endl;
    // printv(ans);
    return 0;
}

