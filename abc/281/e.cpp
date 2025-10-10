#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
#define Yes(q) cout << ((q) ? "Yes" : "No") << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const ll INFL = 4e18;


int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vll a(n);
    rep(i,n)cin>>a[i];

    multiset<ll> l,r;
    ll topsum=0;
    vll b;
    rep(i,m)b.push_back(a[i]);
    sort(ALL(b));



    rep(i,k){
        // cout<<i<<endl;
        l.insert(b[i]);
        topsum+=b[i];
    }
    rep(i,m-k){
        // cout<<i<<endl;
        r.insert(b[i+k]);
    }
    // cout<<11<<endl;
    vll ans;
    rep(i,n-m+1){

        // cout<<topsum<<endl;
        
        ans.push_back(topsum);
        // cout<<111<<endl;
        if(i==n-m)break;
        ll out=a[i],in =a[i+m];
        // cout<<out<<" "<<in<<endl;
        if(l.count(out)){
            // cout<<"L-Erase"<<endl;
            // printv(l)
            // printv(r)
            l.erase(l.find(out));
            topsum-=out;
        }
        else{
            // cout<<"R-Erase"<<endl;
            // printv(l)
            // printv(r)
            r.erase(r.find(out));
        }
        r.insert(in);
        // cout<<*l.rbegin()<<" "<<*r.begin()<<"last,first"<<endl;
        if(l.size()<k){
            // cout<<"Erase"<<endl;
            auto it=r.begin();
            topsum+=*it;
            r.erase(it);
            l.insert(*it);
        }
        else if(*r.begin()<*l.rbegin()){
            // cout<<"Swap"<<endl;
            auto itl=l.end();
            itl--;
            auto itr=r.begin();
            topsum+=*itr-*itl;
            l.erase(itl);
            r.erase(itr);
            l.insert(*itr);
            r.insert(*itl);
        }

    }
    printv(ans);

    

    return 0;
}
