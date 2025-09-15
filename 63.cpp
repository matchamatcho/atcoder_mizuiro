//出来てない

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    int n;
    cin>>n;
    vvll dist(n,vll(n,INFL));
    rep(i,n)rep(j,n){
        cin>>dist[i][j];
    }
    vvll tmp=dist;
    FloydWarshall(dist);
    if(tmp!=dist){
        cout<<-1<<endl;
        return 0;
    }
    
    priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>> pq;
    dsu uf(n);
    rep(i,n)rep(j,n){
        if(i<j)pq.push({dist[i][j],{i,j}});
    }
    ll ans=0;
    vvll newdist(n,vll(n,INFL));
    rep(i,n)newdist[i][i]=0;
    rep(i,n)rep(j,i){
        ans+=dist[i][j];
    }
    set <pii>st;
    rep(i,n)rep(j,i){
        rep(k,n){
            if(dist[i][j]==dist[i][k]+dist[k][j]){
                if(st.count({i,j})>0)continue;
                ans-=dist[i][j];
            st.insert({i,j});
            }
        }
    }
    while(0){
        auto p=pq.top();pq.pop();
        ll c=p.first;
        int u=p.second.first;
        int v=p.second.second;
        if(!uf.same(u,v)){
            uf.merge(u,v);
            bool changed=false;
            changed=chmin(newdist[u][v],c);
            
            rep(i,n){
                rep(j,n){
                    changed=chmin(newdist[i][j],newdist[i][u]+newdist[u][v]+newdist[v][j]);
                    changed=chmin(newdist[i][j],newdist[i][v]+newdist[v][u]+newdist[u][j]);
                }
                if(changed)ans+=c;
            }
        }
        
        // ans+=c;
    }
    cout<<ans<<endl;


    return 0;
}
