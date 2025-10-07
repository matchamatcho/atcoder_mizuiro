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
    
    int n;
    cin>>n;
    Era(2e5);
    int nn=n;
    cout<<nn<<":";
    int cnt=0;
    vll aa={nn};
    for(int i=2;i*i<=nn;i++){
        if(!isprime[i])continue;
        while(n%i==0){
            
        // cout<<n<<" ";
            cnt=1;
            cout<<" "<<i;
            n/=i;
            aa.push_back(n);
        }
        // cout<<"end"<<i<<endl;
        if(n==1)break;
    }
    if(n>1)cout<<" "<<n;
    cout<<endl;

    // printv(aa)
    return 0;
}
