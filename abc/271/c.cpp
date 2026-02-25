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


int main()
{
    int n;
    cin>>n;

    vint a(n);
    deque<int>q;
    rep(i,n){cin>>a[i];}
    sort(ALL(a));
    int stk=0;
    rep(i,n-1)if(a[i]==a[i+1])stk++;
    q.push_back(a[0]);
    rep(i,n)if(q.back()<a[i])q.push_back(a[i]);
    int ans=0;

    while(q.size()>0||stk>1){
        if(q.size()>0&&q.front()==ans+1){
            ans++;
            q.pop_front();
        }
        else{
            if(stk>1){
                ans++;
                stk-=2;
            }
            else {
                while(stk<2&&q.size()>0){
                    q.pop_back();
                    stk++;
                }
                if(stk>1){
                    ans++;
                    stk-=2;

                }
                else{
                    break;
                }
                
            }
        }
    }
    cout<<ans<<endl;
    

    return 0;
}
