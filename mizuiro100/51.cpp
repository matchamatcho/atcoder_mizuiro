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
    string S;
    cin>>S;
    vint dp((1<<3));
    dp[0];//011が参加して、jが鍵を持って帰る。
    map<int ,char>mp;
    mp[0]='J';mp[1]='O';mp[2]='I';
    dp[1]=1;
    rep(i,N){
        vint old(8);
        swap(old,dp);
        int sekinin;
        if(S[i]=='J')sekinin=0;
        else if(S[i]=='O')sekinin=1;
        else sekinin=2;
        rep(j,8){//今
            rep(k,8){//前
                if((j&(1<<sekinin))==0)continue;
                if((k&j)==0)continue;
                dp[j]=(dp[j]+old[k])%10007;

            }
            
        }
        // printv(dp);
      
    }
    int ans=0;
    rep(i,8){
        ans=(ans+dp[i])%10007;
    }
    cout<<ans<<endl;

    

    return 0;
}
