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

vector < bool > isprime;
//返り値は素数のリスト。
vector < ll > Era(int n) {
	isprime.resize(n, true);
	vector < ll > res;
	isprime[0] = false;
	isprime[1] = false;
	for(ll i = 2; i < n; ++i) isprime[i] = true;
	for(ll i = 2; i < n; ++i) {
		if(isprime[i]) {
			res.push_back(i);
			for(ll j = i * 2; j < n; j += i) isprime[j] = false;
		}
	}
	return res;
}
int main()
{
    Era(1e6);
    vint s(1e5+1);
    for(int i=1;i<1e5+1;i+=2){
        if(isprime[i]&&isprime[(i+1)/2])s[i]=1;

    }
    rep(i,1e5)s[i+1]+=s[i];
    int q;
    cin>>q;
    rep(i,q){
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;
    }

    
    

    return 0;
}
