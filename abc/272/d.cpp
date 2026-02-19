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

ll f(pll p1,pll p2){
    ll di=p1.first-p2.first;
    ll dj=p1.second-p2.second;
    return di*di+dj*dj;
};
vll a;
vector<pll> prs;
ll n,m;

bool check(ll i,ll j){
    return (0<=i&&i<n&&0<=j&&j<n);
}


vpll g(pll pos){
    vpll ans;

    for(auto x:prs){
        ans.push_back({pos.first+x.first,pos.second+x.second});
        ans.push_back({pos.first+x.first,pos.second-x.second});
        ans.push_back({pos.first-x.first,pos.second+x.second});
        ans.push_back({pos.first-x.first,pos.second-x.second});

        ans.push_back({pos.first+x.second,pos.second+x.first});
        ans.push_back({pos.first+x.second,pos.second-x.first});
        ans.push_back({pos.first-x.second,pos.second+x.first});
        ans.push_back({pos.first-x.second,pos.second-x.first});


    }

    vpll ans2;
    for(pll tm:ans){
        if(check(tm.first,tm.second))ans2.push_back(tm);
    }


    return ans2;
}

int main()
{
    cin>>n>>m;
    
    for(ll i=0;i*i<=m;++i)a.push_back(i);
    rep(i,a.size())rep(j,i+1){
        // cout<<i<<endl;
        if(a[i]*a[i]+a[j]*a[j]==m){
            prs.push_back({a[i],a[j]});
            // cout<<a[i]<<" "<<a[j]<<endl;
        }
    }

    vvi ans(n,vint(n,-1));
    ans[0][0]=0;
    queue<pll>q;
    q.push({0,0});
    while(q.size()>0){
        pll now=q.front();
        q.pop();
        for(auto[i,j]:g(now)){
            // cout<<i<<" "<<j<<endl;
            // if(f({i,j},now)==m*m){
                if(ans[i][j]>-1)continue;
                ans[i][j]=ans[now.first][now.second]+1;
                q.push({i,j});
            // }
        }
    }
    rep(i,n){
        // cout<<"aaaaa"<<endl;
        rep(j,n){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    
    

    return 0;
}
