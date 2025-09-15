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

bool FloydWarshall(std::vector<std::vector<long long>>& distances)
{
	const size_t v = distances.size();

	for (size_t i = 0; i < v; ++i)
	{
		for (size_t from = 0; from < v; ++from)
		{
			for (size_t to = 0; to < v; ++to)
			{
				if ((distances[from][i] < INFL) && (distances[i][to] < INFL))
				{
					distances[from][to] = std::min(distances[from][to], (distances[from][i] + distances[i][to]));
				}
			}
		}
	}

	for (size_t i = 0; i < v; ++i)
	{
		// 負閉路が含まれている場合, distances[i][i] が負になるような i が存在する
		if (distances[i][i] < 0)
		{
			return true;
		}
	}

	return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vvll dist(n,vll(n,INFL));
    rep(i,n)dist[i][i]=0;
    rep(i,m){
        int a,b;
        ll t;
        cin>>a>>b>>t;
        a--;b--;
        dist[a][b]=t;
        dist[b][a]=t;
    }
    FloydWarshall(dist);
    ll mx=INFL;
    rep(i,n){
        ll mxnow=0;
        rep(j,n){
            mxnow=max(mxnow,dist[i][j]);
        }
        mx=min(mx,mxnow);
    }
    cout<<mx<<endl;
    
    

    return 0;
}
