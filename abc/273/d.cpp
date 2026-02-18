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
    int h,w,rs,cs;
    cin>>h>>w>>rs>>cs;
    rs--;cs--;
    int n;
    cin>>n;
    vvi r(h),c(w);
    rep(i,n){
        int ri,ci;
        cin>>ri>>ci;

        ri--;ci--;
        r[ri].push_back(ci);
        c[ci].push_back(ri);

    }
    
    rep(i,h){
        r[i].push_back(-1);
        r[i].push_back(INF);
        sort(ALL(r[i]));
        // cout<<r[i].size()<<endl;
    }
    rep(i,w){
        c[i].push_back(-1);
        c[i].push_back(INF);
        sort(ALL(c[i]));}

    int Q;
    cin>>Q;
    rep(i,Q){
        // cout<<rs<<"aaaaaa"<<cs<<endl;
        char d;
        int l;
        cin>>d>>l;
        if(d=='L'||d=='R'){
            // cout<<"aa"<<endl;
            int p=lower_bound(ALL(r[rs]),cs)-r[rs].begin();
            // cout<<2223<<endl;
            if(d=='L'){
                // cout<<"ss"<<p<<" "<<r[rs].size()<<endl;
                if(p==1){
                    cs=max(0,cs-l);
                    // cout<<224<<endl;
                }
                else{
                    int dis=cs-r[rs][p-1]-1;
                    cs=cs-min(l,dis);
                    // cout<<222<<endl;

                }
            }
            else{
                if(p==r[rs].size()-1){
                    cs=min(w-1,cs+l);
                }
                else{
                    int dis=r[rs][p]-cs-1;
                    cs=cs+min(l,dis);
                    // cout<<222<<endl;
                }
            }
        }
        else{
            int p=lower_bound(ALL(c[cs]),rs)-c[cs].begin();
            if(d=='U'){
                if(p==1){
                    rs=max(0,rs-l);
                }
                else{
                    int dis=rs-c[cs][p-1]-1;
                    rs=rs-min(l,dis);
                }
            }
            else{
                if(p==c[cs].size()-1){
                    rs=min(h-1,rs+l);
                }
                else{
                    int dis=c[cs][p]-rs-1;
                    rs=rs+min(l,dis);
                }
            }
        }
        cout<<rs+1<<" "<<cs+1<<endl;
        
    }

    

    return 0;
}
