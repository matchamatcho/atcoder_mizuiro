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
int d(int x,int y){
    return abs(x-y)/2;
}


int main()
{
    int n;
    cin>>n;
    vint x(n);
    rep(i,n)cin>>x[i];
    if(n==1){
        cout<<0<<endl;

    }
    else if(n==2){
        cout<<(x[1]-x[0])/2<<endl;
        cout<<(x[1]-x[0])/2<<endl;
        
    }
    else if(n==3){
        cout<<(x[2]-x[0])/2<<endl;
        cout<<(x[1]-x[0])/2+(x[2]-x[1])/2<<endl;
        cout<<(x[2]-x[0])/2<<endl;


    }
    else{
        rep(k,n){
            cout<<k<<":";
            if(k==0||k==n-1){
                cout<<(x.back()-x[0])/2<<endl;
            }
            else{
                int next=-1;
                int ans=0;
                if(x.back()-x[k]>x[k]-x[0]){
                    next=k+1;
                    ans+=abs(x[k]-x[next])/2;
                    ans+=max(d(x[0],x[k]),d(x[next],x.back()));
                }
                else if(x.back()-x[k]==x[k]-x[0]){
                    cout<<"SAme ";
                    if(d(x[k],x[k-1])>=d(x[k],x[k+1])){
                        next=k+1;
                    ans+=abs(x[k]-x[next])/2;
                    ans+=max(d(x[0],x[k]),d(x[next],x.back()));

                    }
                    else{
                        next=k-1;
                    ans+=abs(x[k]-x[next])/2;
                    ans+=max(d(x[0],x[next]),d(x[k],x.back()));

                    }

                }
                else {
                    next=k-1;
                    ans+=abs(x[k]-x[next])/2;
                    ans+=max(d(x[0],x[next]),d(x[k],x.back()));
                }
                cout<<ans<<endl;

            }
        }
    }
    

    return 0;
}
