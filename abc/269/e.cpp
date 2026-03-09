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


int ask(int a,int b,int c,int d){
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    int res;
    cin>>res;
    if(res==-1){
        exit(1);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;

    int a=1,b=n+1,c=1,d=n+1;

    while(a<b-1){
        int mid=(a+b)/2;
        int res=ask(a,mid-1,1,n);
        if(res==mid-a) a=mid;
        else b=mid;

    }
    while(c<d-1){
        int mid=(c+d)/2;
        int res=ask(1,n,c,mid-1);
        if(res==mid-c) c=mid;
        else d=mid;

    }

    cout<<"! "<<a<<" "<<c<<endl;

    

    return 0;
}
