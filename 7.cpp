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
    set<pii> h;
    // vvi d(1e4,vint(1e4));
    // map<pii,bool>mp;
    rep(i,n){
        int u,v;
        cin>>u>>v;
        // u--;v--;
        h.insert(mkpr(u,v));
        // d[u][v]=1;
        // d[v][u]=1;
        // mp[mkpr(u,v)]=true;
        // mp[mkpr(v,u)]=true;

        // cout<<u<<v<<endl;
    }
    int ans=0;
    auto i=h.begin();
    while(i!=h.end()){
        auto j=i;
        j++;
        while(j!=h.end()){
            // cout<<i<<j<<endl;
            // cout<<11<<endl;
            auto [x1,y1]=*i;
            auto [x2,y2]=*j;
            ++j;
            // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
            
            vint d1={x2-x1,y2-y1};
            int x3=x2-d1[1],y3=y2+d1[0];
            int x4=x3-d1[0],y4=y3-d1[1];
            
            if(h.count(mkpr(x3,y3))&&h.count(mkpr(x4,y4)))chmax(ans,d1[0]*d1[0]+d1[1]*d1[1]);
            
            vint d2={x1-x2,y1-y2};
            x3=x1-d1[1];y3=y1+d1[0];
            x4=x3-d1[0];y4=y3-d1[1];
            // if(x3<0||y3<0||x4<0||y4<0)continue;
            if(h.count(mkpr(x3,y3))&&h.count(mkpr(x4,y4)))chmax(ans,d1[0]*d1[0]+d1[1]*d1[1]);
            // if(ans==36)cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<endl;
            // if(ans==36)cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<" "<<endl;


            

        }
        i++;
    }
    cout<<ans<<endl;

    

    return 0;
}
