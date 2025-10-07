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

    vpii a;
    auto add=[&](int c,int num){
        if(a.size()==0){
            a.push_back({c,num});
            return;
        }
        if(a.back().first==c){
            a.back().second+=num;
        }else{
            a.push_back({c,num});
        }
    };
    auto add2=[&](int c,int num){
        if(a.size()==0){
            a.push_back({c,num});
            return;
        }
        if(a.back().first==c){
            a.back().second+=num;
        }else{
            int cnt=a.back().second;
            a.pop_back();
            add(c,cnt+num);

        }
    };
    rep(i,n){
        int c;
        cin>>c;
        if(i%2==0){
            add(c,1);
        } else{
            add2(c,1);
        }

    }
    int ans=0;
    for(auto p:a){
        if(p.first==0) ans+=p.second;
    }
    cout<<ans<<endl;
    

    return 0;
}
