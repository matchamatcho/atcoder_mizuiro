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

ll f(string s){
    ll ret=0;

    ll hour =stoll(s.substr(0,2));
    ll minute =stoll(s.substr(3,2));
    ll second =stoll(s.substr(6,2));
    ret=hour*3600+minute*60+second;


    return ret;
}
int main()
{
    while(1){
        int n;
        cin>>n;
        if(n==0)break;
        vll s(24*3600+1);
        rep(i,n){
            string st,ed;
            cin>>st>>ed;
            s[f(st)]--;
            s[f(ed)]++;
        }
        rep(i,24*3600)s[i+1]+=s[i];
        ll ans=0;
        for(auto x:s)chmin(ans,x);
        cout<<-ans<<endl;
    }
    

    return 0;
}
