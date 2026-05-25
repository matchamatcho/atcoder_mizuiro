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

int op(int a, int b) {
    return a+ b;
}

int e() {
    return (int)(0);
}


int main()
{
    int n,q;
    cin>>n>>q;
    segtree<int, op, e> seg(q+1);
    seg.set(0,n);
    int target=0;
    int base=0;
    vint s(n);
    rep(qi,q){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            s[x-1]++;
            seg.set(s[x-1]-1,seg.get(s[x-1]-1)-1);
            seg.set(s[x-1],seg.get(s[x-1])+1);
            if(seg.get(target)==0){
                target++;
                base++;
            }

        }
        else{
            int y;
            cin>>y;
            if(y+base>q+1){cout<<0<<endl;
            continue;}
            cout<<seg.prod(y+base,q+1)<<endl;
        }
    }
    

    return 0;
}
